/**
 * Copyright (C) 2013-2015
 *
 * @author jxfengzi@gmail.com
 * @date   2013-11-19
 *
 * @file   DeviceStack.c
 *
 * @remark
 *
 */

#include <tiny_malloc.h>
#include <tiny_log.h>
#include <IotLauncher.h>
#include <XcpwsClientRuntime.h>
#include <XcpwsServerRuntime.h>
#include <TinyThread.h>
#include <server/WebcmdServer.h>
#include "DeviceStack.h"

#define TAG "DeviceStack"

static TinyThread *_thread = NULL;

static void _loop(void *param)
{
    TinyRet ret = IotLauncher_Run((IotLauncher *) param);
    if (RET_FAILED(ret))
    {
        LOG_D(TAG, "IotLauncher_Run FAILED: %d", ret);
    }
}

TinyRet StartDeviceStack(Product *product, uint16_t *port)
{
    TinyRet ret = TINY_RET_OK;
    IotLauncher *launcher = NULL;

    do
    {
        if (_thread != NULL)
        {
            ret = TINY_RET_E_STARTED;
            break;
        }

        _thread = TinyThread_New();
        if (_thread == NULL)
        {
            ret = TINY_RET_E_NEW;
            break;
        }

        IotRuntime *runtime = XcpwsClientRuntime_New();
        if (runtime == NULL)
        {
            ret = TINY_RET_E_NEW;
            break;
        }

        launcher = IotLauncher_NewRuntime(product, runtime, WebcmdServer_New(runtime, port), NULL, NULL);
        if (launcher == NULL)
        {
            ret = TINY_RET_E_NEW;
            break;
        }

        ret = TinyThread_Initialize(_thread, _loop, launcher, "stack");
        if (RET_FAILED(ret))
        {
            IotLauncher_Delete(launcher);
            break;
        }

        if (! TinyThread_Start(_thread))
        {
            ret = TINY_RET_E_INTERNAL;
            break;
        }
    } while (false);

    return ret;
}

TinyRet StopDeviceStack(void)
{
    TinyRet ret = TINY_RET_OK;

    do
    {
        if (_thread == NULL)
        {
            ret = TINY_RET_E_STOPPED;
            break;
        }

        if (_thread->status != ThreadRunning)
        {
            ret = TINY_RET_E_STATUS;
            break;
        }

        ret = IotLauncher_Stop((IotLauncher *) (_thread->thread_param));
        if (RET_FAILED(ret))
        {
            break;
        }

        if (!TinyThread_Join(_thread))
        {
            ret = TINY_RET_E_INTERNAL;
        }
    } while (false);

    return ret;
}