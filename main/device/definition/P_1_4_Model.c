/**
 * Copyright (C) 2013-2015
 *
 * @author jxfengzi@gmail.com
 * @date   2013-11-19
 *
 * @file   P_1_4_Model.h
 *
 * @remark
 *
 */

#include "P_1_4_Model.h"

Property * P_1_4_Model(void)
{
    return Property_NewInstance(4, "homekit-spec", "model", 0x00000021, NULL, FORMAT_STRING, ACCESS_READ, NONE);
}