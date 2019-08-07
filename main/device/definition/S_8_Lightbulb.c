/**
 * Copyright (C) 2013-2015
 *
 * @author jxfengzi@gmail.com
 * @date   2013-11-19
 *
 * @file   S_8_Lightbulb.c
 *
 * @remark
 *
 */

#include "S_8_Lightbulb.h"
#include "P_8_9_Name.h"
#include "P_8_10_On.h"

Service * S_8_Lightbulb(void)
{
    Service *thiz = NULL;

    do
    {
        thiz = Service_NewInstance(2, "homekit-spec", "lightbulb", 0x00000043, NULL);
        if (thiz == NULL)
        {
            break;
        }

        if (RET_FAILED(TinyList_AddTail(&thiz->properties, P_8_9_Name())))
        {
            Service_Delete(thiz);
            thiz = NULL;
            break;
        }

        if (RET_FAILED(TinyList_AddTail(&thiz->properties, P_8_10_On())))
        {
            Service_Delete(thiz);
            thiz = NULL;
            break;
        }
    } while (false);

    return thiz;
}