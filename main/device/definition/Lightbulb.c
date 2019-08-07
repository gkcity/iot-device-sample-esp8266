/**
 * Copyright (C) 2013-2015
 *
 * @author jxfengzi@gmail.com
 * @date   2013-11-19
 *
 * @file   Lightbulb.c
 *
 * @remark
 *
 */

#include <tiny_snprintf.h>
#include "Lightbulb.h"
#include "../handler/OnPropertySet.h"
#include "../handler/OnActionInvoke.h"
#include "../handler/OnPropertyGet.h"
#include "../initializer/InitializeConfiguration.h"
#include "S_1_AccessoryInformation.h"
#include "S_8_Lightbulb.h"

Product * Lightbulb(const char *serialNumber, const char *ip)
{
    Product *thiz = NULL;

    do
    {
        thiz = Product_New();
        if (thiz == NULL)
        {
            break;
        }

        thiz->onGet = OnPropertyGet;
        thiz->onSet = OnPropertySet;
        thiz->onInvoke = OnActionInvoke;

        if (RET_FAILED(TinyList_AddTail(&thiz->device.services, S_1_AccessoryInformation())))
        {
            Product_Delete(thiz);
            thiz = NULL;
            break;
        }

        if (RET_FAILED(TinyList_AddTail(&thiz->device.services, S_8_Lightbulb())))
        {
            Product_Delete(thiz);
            thiz = NULL;
            break;
        }

        InitializeConfiguration(&thiz->config, serialNumber, ip);
    } while (false);

    return thiz;
}