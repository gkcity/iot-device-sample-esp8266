/**
* Copyright (C) 2013-2015
*
* @author jxfengzi@gmail.com
* @date   2013-11-19
*
* @file   InitializeConfiguration.c
*
* @remark
*
*/

#include <tiny_snprintf.h>
#include "InitializeConfiguration.h"

#define LTSK                "ki/atspw7hjR+4PdQnO6MBC1wRcpiJn2EZhOsvk0ft4="
#define LTPK                "ZcXOjevU/cTD0ILHAcLpTyZ4NNztdlje7C1V5iIjsTw="

void InitializeConfiguration(ProductConfig *thiz, const char *serialNumber, const char *ip)
{
    strncpy(thiz->serialNumber, serialNumber, DEVICE_ID_LENGTH);
    strncpy(thiz->ip, ip, TINY_IP_LEN);
    strncpy(thiz->ltsk, LTSK, DEVICE_LTSK_BASE64_LENGTH);
    strncpy(thiz->ltpk, LTPK, DEVICE_LTPK_BASE64_LENGTH);
    thiz->productId = PRODUCT_ID;
    thiz->productVersion = PRODUCT_VERSION;
    thiz->port = 0;

    tiny_snprintf(thiz->did, DEVICE_ID_LENGTH, "%s@%d", thiz->serialNumber, thiz->productId);
}