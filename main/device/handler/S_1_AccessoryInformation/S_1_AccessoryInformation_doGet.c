/**
* Copyright (C) 2013-2015
*
* @author jxfengzi@gmail.com
* @date   2013-11-19
*
* @file   S_1_AccessoryInformation_doGet.c
*
* @remark
*
*/

#include "S_1_AccessoryInformation_doGet.h"
#include "../../iid/IID.h"

static void P_1_3_Manufacturer_doGet(PropertyOperation *o)
{
     o->value = JsonValue_NewString("GeekCity");
}

static void P_1_4_Model_doGet(PropertyOperation *o)
{
     o->value = JsonValue_NewString("sample-device");
}

static void P_1_5_Name_doGet(PropertyOperation *o)
{
    o->value = JsonValue_NewString("Lightbulb2018");
}

static void P_1_6_SerialNumber_doGet(PropertyOperation *o)
{
     o->value = JsonValue_NewString("10001");
}

static void P_1_7_FirmwareRevision_doGet(PropertyOperation *o)
{
     o->value = JsonValue_NewString("1.0.0");
}

void S_1_AccessoryInformation_doGet(PropertyOperation *o)
{
    printf("S_1_AccessoryInformation_doGet: piid = [%d]\n", o->pid.iid);

    switch (o->pid.iid)
    {
        case IID_1_3_Manufacturer:
            P_1_3_Manufacturer_doGet(o);
            break;

        case IID_1_4_Model:
            P_1_4_Model_doGet(o);
            break;

        case IID_1_5_Name:
            P_1_5_Name_doGet(o);
            break;

        case IID_1_6_SerialNumber:
            P_1_6_SerialNumber_doGet(o);
            break;

        case IID_1_7_FirmwareRevision:
            P_1_7_FirmwareRevision_doGet(o);
            break;

        default:
            o->status = -100;
            break;
    }
}