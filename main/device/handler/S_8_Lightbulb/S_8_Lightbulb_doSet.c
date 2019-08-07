/**
* Copyright (C) 2013-2015
*
* @author jxfengzi@gmail.com
* @date   2013-11-19
*
* @file   S_8_Lightbulb_doSet.c
*
* @remark
*
*/

#include "S_8_Lightbulb_doSet.h"
#include "../../iid/IID.h"
#include "../../print/PrintValue.h"
#include "driver/gpio.h"

static void P_8_10_On_doSet(PropertyOperation *o)
{
    esp_err_t ret = 0;

    printf("P_8_10_On_doSet\n");
    printValue(o->value);

    o->status = 0;

    ret = gpio_set_level(GPIO_NUM_12, o->value ? 1 : 0);
    if (ret)
    {
        printf("gpio_set_level(12) => %d\n", ret);
    }
}

void S_8_Lightbulb_doSet(PropertyOperation *o)
{
    printf("S_8_Lightbulb_doSet: piid = [%d]\n", o->pid.iid);

    switch (o->pid.iid)
    {
        case IID_8_10_On:
            P_8_10_On_doSet(o);
            break;

        default:
            o->status = -100;
            break;
    }
}