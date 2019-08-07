#include <string.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/event_groups.h"
#include "esp_system.h"
#include "esp_wifi.h"
#include "esp_event_loop.h"
#include "esp_log.h"
#include "nvs_flash.h"
#include "lwip/err.h"
#include "lwip/sys.h"

#include "device/definition/Lightbulb.h"
#include "DeviceStack.h"

#define EXAMPLE_ESP_WIFI_SSID      "airport-milink"
#define EXAMPLE_ESP_WIFI_PASS      "milink123"
#define EXAMPLE_MAX_STA_CONN       10

/* FreeRTOS event group to signal when we are connected*/
static EventGroupHandle_t wifi_event_group;

/* The event group allows multiple bits for each event,
   but we only care about one event - are we connected
   to the AP with an IP? */
const int WIFI_CONNECTED_BIT = BIT0;

static const char *TAG = "xiot";

static void getSerialNumber(char sn[16])
{
    uint8_t mac[6];
    esp_wifi_get_mac(WIFI_IF_STA, mac);

    snprintf(sn, 16, "%02x%02x%02x%02x%02x%02x", mac[0], mac[1], mac[2], mac[3], mac[4], mac[5]);
}

static void runIotStack(void *param)
{
    const char *ip = (const char *)param;
    char sn[16];
    Product *product = NULL;
    uint16_t port = 60006;

    /**
     * 1. 初始化产品
     */
    memset(sn, 0, 16);
    getSerialNumber(sn);

    product = Lightbulb(sn, ip);
    if (product == NULL)
    {
        ESP_LOGI(TAG, "product is null");
        return;
    }

    /**
     * 2. 线程1： 启动协议栈，连接到服务器，等待控制指令并执行。
     */
    StartDeviceStack(product, &port);

    /**
     * 3. 线程2： 监控设备数据，如果发生变化，则通过ipc端口通知服务器。
     */
    //    StartDeviceMonitor(device->did, port);

    /**
     * 4. 线程3: 主线程，阻塞在这里，等待用户输入命令
     */
    // WaitingForUserCommand(port);

    /**
     * 5. 停止数据监控
     */
    //StopDeviceMonitor();

    /**
     * 6. 停止协议栈
     */
    StopDeviceStack();

    /**
     * 7. 销毁产品，准备退出
     */
    Product_Delete(product);
}

void startIoTStack(const char *ip)
{
    wifi_ap_record_t ap;

    memset(&ap, 0, sizeof(wifi_ap_record_t));
    if (esp_wifi_sta_get_ap_info(&ap) == ESP_OK)
    {
        ESP_LOGI(TAG, "ap.ssid: %s", ap.ssid);
    }

    xTaskCreate(runIotStack, "iot", 1024 * 6, (void *)ip, 5, NULL);
}

#if 0
static void runCaptivePortal(void *param)
{
    tcpip_adapter_ip_info_t info;
    if (tcpip_adapter_get_ip_info(TCPIP_ADAPTER_IF_AP, &info) != ESP_OK)
    {
        ESP_LOGI(TAG, "tcpip_adapter_get_ip_info failed");
        return;
    }

    CaptivePortal * cp = CaptivePortal_New(NULL, NULL);
    if (cp == NULL)
    {
        ESP_LOGI(TAG, "CaptivePortal_New failed");
        return;
    }

    char s[32];
    uint8_t *a = (uint8_t *) &info.ip.addr;
    snprintf(s, 32, "%d.%d.%d.%d", a[0], a[1], a[2], a[3]);
    printf("runCaptivePortal ip: %s\n", s);

    CaptivePortal_Run(cp, info.ip.addr);
}

void startCaptivePortal(void)
{
    ESP_LOGI(TAG, "startCaptivePortal");
    xTaskCreate(runCaptivePortal, "cp", 1024 * 6, NULL, 5, NULL);
}

void stopCaptivePortal(void)
{
    ESP_LOGI(TAG, "stopCaptivePortal");
}
#endif

static esp_err_t event_handler(void *ctx, system_event_t *event)
{
    switch(event->event_id) {
        case SYSTEM_EVENT_STA_START:
            esp_wifi_connect();
            break;

        case SYSTEM_EVENT_STA_GOT_IP:
            ESP_LOGI(TAG, "got ip:%s", ip4addr_ntoa(&event->event_info.got_ip.ip_info.ip));
            xEventGroupSetBits(wifi_event_group, WIFI_CONNECTED_BIT);
            startIoTStack(ip4addr_ntoa(&event->event_info.got_ip.ip_info.ip));
            break;

        case SYSTEM_EVENT_AP_STACONNECTED:
            ESP_LOGI(TAG, "station:"MACSTR" join, AID=%d",
            MAC2STR(event->event_info.sta_connected.mac), event->event_info.sta_connected.aid);
            break;

        case SYSTEM_EVENT_AP_STADISCONNECTED:
            ESP_LOGI(TAG, "station:"MACSTR"leave, AID=%d",
            MAC2STR(event->event_info.sta_disconnected.mac), event->event_info.sta_disconnected.aid);
            break;

        case SYSTEM_EVENT_STA_DISCONNECTED:
            esp_wifi_connect();
            xEventGroupClearBits(wifi_event_group, WIFI_CONNECTED_BIT);
            break;

#if 0
        case SYSTEM_EVENT_AP_START:
            startCaptivePortal();
            break;

        case SYSTEM_EVENT_AP_STOP:
            stopCaptivePortal();
            break;
#endif

        default:
            break;
    }
    return ESP_OK;
}

void wifi_init_softap()
{
    wifi_event_group = xEventGroupCreate();

    tcpip_adapter_init();
    ESP_ERROR_CHECK(esp_event_loop_init(event_handler, NULL));

    wifi_init_config_t cfg = WIFI_INIT_CONFIG_DEFAULT();
    ESP_ERROR_CHECK(esp_wifi_init(&cfg));
    wifi_config_t wifi_config = {
            .ap = {
                    .ssid = EXAMPLE_ESP_WIFI_SSID,
                    .ssid_len = strlen(EXAMPLE_ESP_WIFI_SSID),
                    .max_connection = EXAMPLE_MAX_STA_CONN,
                    .authmode = WIFI_AUTH_OPEN
            },
    };
    if (strlen(EXAMPLE_ESP_WIFI_PASS) == 0) {
        wifi_config.ap.authmode = WIFI_AUTH_OPEN;
    }

    ESP_ERROR_CHECK(esp_wifi_set_mode(WIFI_MODE_AP));
    ESP_ERROR_CHECK(esp_wifi_set_config(ESP_IF_WIFI_AP, &wifi_config));
    ESP_ERROR_CHECK(esp_wifi_start());

    ESP_LOGI(TAG, "wifi_init_softap finished, SSID: %s", EXAMPLE_ESP_WIFI_SSID);
}

void wifi_init_sta()
{
    wifi_event_group = xEventGroupCreate();

    tcpip_adapter_init();
    ESP_ERROR_CHECK(esp_event_loop_init(event_handler, NULL) );

    wifi_init_config_t cfg = WIFI_INIT_CONFIG_DEFAULT();
    ESP_ERROR_CHECK(esp_wifi_init(&cfg));
    wifi_config_t wifi_config = {
            .sta = {
                    .ssid = EXAMPLE_ESP_WIFI_SSID,
                    .password = EXAMPLE_ESP_WIFI_PASS
            },
    };

    ESP_ERROR_CHECK(esp_wifi_set_mode(WIFI_MODE_STA) );
    ESP_ERROR_CHECK(esp_wifi_set_config(ESP_IF_WIFI_STA, &wifi_config) );
    ESP_ERROR_CHECK(esp_wifi_start() );

    ESP_LOGI(TAG, "wifi_init_sta finished.");
    ESP_LOGI(TAG, "connect to ap SSID:%s password:%s",
             EXAMPLE_ESP_WIFI_SSID, EXAMPLE_ESP_WIFI_PASS);
}

void app_main()
{
    printf("app started, free heap size: %d\n", esp_get_free_heap_size());
    printf("SDK version:%s\n", esp_get_idf_version());

    //Initialize NVS
    esp_err_t ret = nvs_flash_init();
    if (ret == ESP_ERR_NVS_NO_FREE_PAGES) {
        ESP_ERROR_CHECK(nvs_flash_erase());
        ret = nvs_flash_init();
    }
    ESP_ERROR_CHECK(ret);

#if 0
    ESP_LOGI(TAG, "ESP_WIFI_MODE_AP");
    wifi_init_softap();
#else
    ESP_LOGI(TAG, "ESP_WIFI_MODE_STA");
    wifi_init_sta();
#endif
}


