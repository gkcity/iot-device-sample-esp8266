/**
 * Copyright (C) 2013-2015
 *
 * @author jxfengzi@gmail.com
 * @date   2013-11-19
 *
 * @file   P_8_9_Name.h
 *
 * @remark
 *
 */

#include "P_8_9_Name.h"

Property * P_8_9_Name(void)
{
    return Property_NewInstance(9, "homekit-spec", "name", 0x00000023, NULL, FORMAT_STRING, ACCESS_READ, NONE);
}