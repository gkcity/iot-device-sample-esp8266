/**
 * Copyright (C) 2013-2015
 *
 * @author jxfengzi@gmail.com
 * @date   2013-11-19
 *
 * @file   P_1_2_Identify.h
 *
 * @remark
 *
 */

#include "P_1_2_Identify.h"

Property * P_1_2_Identify(void)
{
    return Property_NewInstance(2, "homekit-spec", "identify", 0x0000003E, NULL, FORMAT_BOOL, ACCESS_WRITE, NONE);
}