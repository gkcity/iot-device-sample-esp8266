/**
* Copyright (C) 2013-2015
*
* @author jxfengzi@gmail.com
* @date   2013-11-19
*
* @file   S_8_Lightbulb_doGet.c
*
* @remark
*
*/

#include "S_8_Lightbulb_doGet.h"
#include "../../iid/IID.h"

static void P_8_9_Name_doGet(PropertyOperation *o)
{
    o->value = JsonValue_NewString("light");
}

static void P_8_9_On_doGet(PropertyOperation *o)
{
    o->value = JsonValue_NewBoolean(true);
}

void S_8_Lightbulb_doGet(PropertyOperation *o)
{
    printf("S_8_Lightbulb_doGet: piid = [%d]\n", o->pid.iid);

    switch (o->pid.iid)
    {
        case IID_8_9_Name:
            P_8_9_Name_doGet(o);
            break;

        case IID_8_10_On:
            P_8_9_On_doGet(o);
            break;

        default:
            o->status = -100;
            break;
    }
}