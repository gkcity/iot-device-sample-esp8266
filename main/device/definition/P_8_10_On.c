/**
 * Copyright (C) 2013-2015
 *
 * @author jxfengzi@gmail.com
 * @date   2013-11-19
 *
 * @file   P_8_10_On.h
 *
 * @remark
 *
 */

#include "P_8_10_On.h"

Property * P_8_10_On(void)
{
    return Property_NewInstance(10, "homekit-spec", "on", 0x00000025, NULL, FORMAT_BOOL, ACCESS_RWN, NONE);
}