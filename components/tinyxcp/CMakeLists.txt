set(SOURCE_ROOT tinyxcp/source/src)
set(SOURCE_INC
        ${SOURCE_ROOT}/xcp-common
        ${SOURCE_ROOT}/xcp-message
        ${SOURCE_ROOT}/xcp-message-codec
        ${SOURCE_ROOT}/xcp-websocket)

#-----------------------
# XcpCommon
#-----------------------

SET(XcpCommon_Header
        ${SOURCE_ROOT}/xcp-common/XcpSessionInfo.h
        ${SOURCE_ROOT}/xcp-common/XcpKeyCreator.h
        ${SOURCE_ROOT}/xcp-common/XcpStage.h
        )

SET(XcpCommon_Source
        ${SOURCE_ROOT}/xcp-common/XcpSessionInfo.c
        ${SOURCE_ROOT}/xcp-common/XcpKeyCreator.c
        )

#-----------------------
# XcpMessageCodec
#-----------------------

SET(XcpMessageCodec_Header
		${SOURCE_ROOT}/xcp-message-codec/XcpMessageCodec.h
		${SOURCE_ROOT}/xcp-message-codec/iq/IQCodec.h
		${SOURCE_ROOT}/xcp-message-codec/iq/IQErrorCodec.h
		${SOURCE_ROOT}/xcp-message-codec/iq/IQQueryCodec.h
		${SOURCE_ROOT}/xcp-message-codec/iq/IQResultCodec.h
		${SOURCE_ROOT}/xcp-message-codec/iq/basic/ChildrenAddedCodec.h
		${SOURCE_ROOT}/xcp-message-codec/iq/basic/ChildrenRemovedCodec.h
		${SOURCE_ROOT}/xcp-message-codec/iq/basic/EventOccurredCodec.h
		${SOURCE_ROOT}/xcp-message-codec/iq/basic/InitializeCodec.h
		${SOURCE_ROOT}/xcp-message-codec/iq/basic/PropertiesChangedCodec.h
		${SOURCE_ROOT}/xcp-message-codec/iq/basic/SetAccessKeyCodec.h
		${SOURCE_ROOT}/xcp-message-codec/iq/basic/VerifyFinishCodec.h
		${SOURCE_ROOT}/xcp-message-codec/iq/basic/VerifyStartCodec.h
		${SOURCE_ROOT}/xcp-message-codec/iq/basic/GetPropertiesCodec.h
		${SOURCE_ROOT}/xcp-message-codec/iq/basic/SetPropertiesCodec.h
		${SOURCE_ROOT}/xcp-message-codec/iq/basic/InvokeActionCodec.h
		${SOURCE_ROOT}/xcp-message-codec/iq/basic/GetChildrenCodec.h
		${SOURCE_ROOT}/xcp-message-codec/iq/basic/GetAccessKeyCodec.h
		${SOURCE_ROOT}/xcp-message-codec/xid/PIDCodec.h
		${SOURCE_ROOT}/xcp-message-codec/xid/AIDCodec.h
        )

SET(XcpMessageCodec_Source
		${SOURCE_ROOT}/xcp-message-codec/XcpMessageCodec.c
		${SOURCE_ROOT}/xcp-message-codec/iq/IQCodec.c
		${SOURCE_ROOT}/xcp-message-codec/iq/IQErrorCodec.c
		${SOURCE_ROOT}/xcp-message-codec/iq/IQQueryCodec.c
		${SOURCE_ROOT}/xcp-message-codec/iq/IQResultCodec.c
		${SOURCE_ROOT}/xcp-message-codec/iq/basic/ChildrenAddedCodec.c
		${SOURCE_ROOT}/xcp-message-codec/iq/basic/ChildrenRemovedCodec.c
		${SOURCE_ROOT}/xcp-message-codec/iq/basic/EventOccurredCodec.c
		${SOURCE_ROOT}/xcp-message-codec/iq/basic/InitializeCodec.c
		${SOURCE_ROOT}/xcp-message-codec/iq/basic/PropertiesChangedCodec.c
		${SOURCE_ROOT}/xcp-message-codec/iq/basic/SetAccessKeyCodec.c
		${SOURCE_ROOT}/xcp-message-codec/iq/basic/VerifyFinishCodec.c
		${SOURCE_ROOT}/xcp-message-codec/iq/basic/VerifyStartCodec.c
		${SOURCE_ROOT}/xcp-message-codec/iq/basic/GetPropertiesCodec.c
		${SOURCE_ROOT}/xcp-message-codec/iq/basic/SetPropertiesCodec.c
		${SOURCE_ROOT}/xcp-message-codec/iq/basic/InvokeActionCodec.c
		${SOURCE_ROOT}/xcp-message-codec/iq/basic/GetChildrenCodec.c
		${SOURCE_ROOT}/xcp-message-codec/iq/basic/GetAccessKeyCodec.c
		${SOURCE_ROOT}/xcp-message-codec/xid/PIDCodec.c
		${SOURCE_ROOT}/xcp-message-codec/xid/AIDCodec.c
        )

#-----------------------
# XcpMessage
#-----------------------

SET(XcpMessage_Header
		${SOURCE_ROOT}/xcp-message/XcpMessage.h
		${SOURCE_ROOT}/xcp-message/XcpConstant.h
		${SOURCE_ROOT}/xcp-message/iq/IQ.h
		${SOURCE_ROOT}/xcp-message/iq/IQError.h
		${SOURCE_ROOT}/xcp-message/iq/IQErrorFactory.h
		${SOURCE_ROOT}/xcp-message/iq/IQQuery.h
		${SOURCE_ROOT}/xcp-message/iq/IQResult.h
		${SOURCE_ROOT}/xcp-message/iq/IQMethod.h
		${SOURCE_ROOT}/xcp-message/iq/basic/ByebyeFactory.h
		${SOURCE_ROOT}/xcp-message/iq/basic/ChildrenAdded.h
		${SOURCE_ROOT}/xcp-message/iq/basic/ChildrenRemoved.h
		${SOURCE_ROOT}/xcp-message/iq/basic/EventOccurred.h
		${SOURCE_ROOT}/xcp-message/iq/basic/EventOccurredFactory.h
		${SOURCE_ROOT}/xcp-message/iq/basic/GetAccessKey.h
		${SOURCE_ROOT}/xcp-message/iq/basic/GetAccessKeyFactory.h
		${SOURCE_ROOT}/xcp-message/iq/basic/GetChildren.h
		${SOURCE_ROOT}/xcp-message/iq/basic/GetProperties.h
		${SOURCE_ROOT}/xcp-message/iq/basic/GetPropertiesFactory.h
		${SOURCE_ROOT}/xcp-message/iq/basic/Initialize.h
		${SOURCE_ROOT}/xcp-message/iq/basic/InitializeFactory.h
		${SOURCE_ROOT}/xcp-message/iq/basic/InvokeAction.h
		${SOURCE_ROOT}/xcp-message/iq/basic/InvokeActionFactory.h
		${SOURCE_ROOT}/xcp-message/iq/basic/PingFactory.h
		${SOURCE_ROOT}/xcp-message/iq/basic/PongFactory.h
		${SOURCE_ROOT}/xcp-message/iq/basic/PropertiesChanged.h
		${SOURCE_ROOT}/xcp-message/iq/basic/PropertiesChangedFactory.h
		${SOURCE_ROOT}/xcp-message/iq/basic/SetAccessKey.h
		${SOURCE_ROOT}/xcp-message/iq/basic/SetAccessKeyFactory.h
		${SOURCE_ROOT}/xcp-message/iq/basic/SetProperties.h
		${SOURCE_ROOT}/xcp-message/iq/basic/SetPropertiesFactory.h
		${SOURCE_ROOT}/xcp-message/iq/basic/VerifyFinish.h
		${SOURCE_ROOT}/xcp-message/iq/basic/VerifyFinishFactory.h
		${SOURCE_ROOT}/xcp-message/iq/basic/VerifyStart.h
		${SOURCE_ROOT}/xcp-message/iq/basic/VerifyStartFactory.h
		${SOURCE_ROOT}/xcp-message/handler/XcpMessageHandler.h
        )

SET(XcpMessage_Source
		${SOURCE_ROOT}/xcp-message/XcpMessage.c
		${SOURCE_ROOT}/xcp-message/iq/IQ.c
		${SOURCE_ROOT}/xcp-message/iq/IQError.c
		${SOURCE_ROOT}/xcp-message/iq/IQErrorFactory.c
		${SOURCE_ROOT}/xcp-message/iq/IQQuery.c
		${SOURCE_ROOT}/xcp-message/iq/IQResult.c
		${SOURCE_ROOT}/xcp-message/iq/IQMethod.c
		${SOURCE_ROOT}/xcp-message/iq/basic/ByebyeFactory.c
		${SOURCE_ROOT}/xcp-message/iq/basic/ChildrenAdded.c
		${SOURCE_ROOT}/xcp-message/iq/basic/ChildrenRemoved.c
		${SOURCE_ROOT}/xcp-message/iq/basic/EventOccurred.c
		${SOURCE_ROOT}/xcp-message/iq/basic/EventOccurredFactory.c
		${SOURCE_ROOT}/xcp-message/iq/basic/GetAccessKey.c
		${SOURCE_ROOT}/xcp-message/iq/basic/GetAccessKeyFactory.c
		${SOURCE_ROOT}/xcp-message/iq/basic/GetChildren.c
		${SOURCE_ROOT}/xcp-message/iq/basic/GetProperties.c
		${SOURCE_ROOT}/xcp-message/iq/basic/GetPropertiesFactory.c
		${SOURCE_ROOT}/xcp-message/iq/basic/Initialize.c
		${SOURCE_ROOT}/xcp-message/iq/basic/InitializeFactory.c
		${SOURCE_ROOT}/xcp-message/iq/basic/InvokeAction.c
		${SOURCE_ROOT}/xcp-message/iq/basic/InvokeActionFactory.c
		${SOURCE_ROOT}/xcp-message/iq/basic/PingFactory.c
		${SOURCE_ROOT}/xcp-message/iq/basic/PongFactory.c
		${SOURCE_ROOT}/xcp-message/iq/basic/PropertiesChanged.c
		${SOURCE_ROOT}/xcp-message/iq/basic/PropertiesChangedFactory.c
		${SOURCE_ROOT}/xcp-message/iq/basic/SetAccessKey.c
		${SOURCE_ROOT}/xcp-message/iq/basic/SetAccessKeyFactory.c
		${SOURCE_ROOT}/xcp-message/iq/basic/SetProperties.c
		${SOURCE_ROOT}/xcp-message/iq/basic/SetPropertiesFactory.c
		${SOURCE_ROOT}/xcp-message/iq/basic/VerifyFinish.c
		${SOURCE_ROOT}/xcp-message/iq/basic/VerifyFinishFactory.c
		${SOURCE_ROOT}/xcp-message/iq/basic/VerifyStart.c
		${SOURCE_ROOT}/xcp-message/iq/basic/VerifyStartFactory.c
		${SOURCE_ROOT}/xcp-message/handler/XcpMessageHandler.c
		)

#-----------------------
# Xcpws
#-----------------------

SET(Xcpws_Header
		${SOURCE_ROOT}/xcp-websocket/XcpwsClientRuntime.h
		${SOURCE_ROOT}/xcp-websocket/XcpwsServerRuntime.h
		${SOURCE_ROOT}/xcp-websocket/client/XcpwsClient.h
		${SOURCE_ROOT}/xcp-websocket/client/handler/XcpwsClientHandler.h
		${SOURCE_ROOT}/xcp-websocket/client/handler/XcpwsClientHandlerContext.h
		${SOURCE_ROOT}/xcp-websocket/client/verifier/XcpClientVerifier.h
		${SOURCE_ROOT}/xcp-websocket/server/XcpwsServer.h
		${SOURCE_ROOT}/xcp-websocket/server/XcpwsServerContext.h
		${SOURCE_ROOT}/xcp-websocket/server/XcpwsBonjour.h
		${SOURCE_ROOT}/xcp-websocket/server/handler/XcpwsServerHandler.h
		${SOURCE_ROOT}/xcp-websocket/server/handler/XcpwsServerHandlerContext.h
		${SOURCE_ROOT}/xcp-websocket/codec-message/CustomDataType.h
		${SOURCE_ROOT}/xcp-websocket/codec-message/MessageCodec.h
		${SOURCE_ROOT}/xcp-websocket/codec-message/MessageCodecContext.h
		${SOURCE_ROOT}/xcp-websocket/codec-binary/WebSocketBinaryFrameCodec.h
		${SOURCE_ROOT}/xcp-websocket/codec-binary/WebSocketBinaryFrameCodecContext.h
		${SOURCE_ROOT}/xcp-websocket/codec-binary/WebSocketBinaryFrameCodecType.h
		${SOURCE_ROOT}/xcp-websocket/codec-binary/WebSocketBinaryFrameDecoder.h
		${SOURCE_ROOT}/xcp-websocket/codec-binary/WebSocketBinaryFrameEncoder.h
		)

SET(Xcpws_Source
		${SOURCE_ROOT}/xcp-websocket/XcpwsClientRuntime.c
		${SOURCE_ROOT}/xcp-websocket/XcpwsServerRuntime.c
		${SOURCE_ROOT}/xcp-websocket/client/XcpwsClient.c
		${SOURCE_ROOT}/xcp-websocket/client/handler/XcpwsClientHandler.c
		${SOURCE_ROOT}/xcp-websocket/client/handler/XcpwsClientHandlerContext.c
		${SOURCE_ROOT}/xcp-websocket/client/verifier/XcpClientVerifier.c
		${SOURCE_ROOT}/xcp-websocket/server/XcpwsServer.c
		${SOURCE_ROOT}/xcp-websocket/server/XcpwsServerContext.c
		${SOURCE_ROOT}/xcp-websocket/server/XcpwsBonjour.c
		${SOURCE_ROOT}/xcp-websocket/server/handler/XcpwsServerHandler.c
		${SOURCE_ROOT}/xcp-websocket/server/handler/XcpwsServerHandlerContext.c
		${SOURCE_ROOT}/xcp-websocket/codec-message/MessageCodec.c
		${SOURCE_ROOT}/xcp-websocket/codec-message/MessageCodecContext.c
		${SOURCE_ROOT}/xcp-websocket/codec-binary/WebSocketBinaryFrameCodec.c
		${SOURCE_ROOT}/xcp-websocket/codec-binary/WebSocketBinaryFrameCodecContext.c
		${SOURCE_ROOT}/xcp-websocket/codec-binary/WebSocketBinaryFrameDecoder.c
		${SOURCE_ROOT}/xcp-websocket/codec-binary/WebSocketBinaryFrameEncoder.c
		)

#-----------------------
# XcpWebcmd
#-----------------------

SET(XcpWebcmd_Header
		${SOURCE_ROOT}/xcp-webcmd/server/WebcmdServer.h
		${SOURCE_ROOT}/xcp-webcmd/server/handler/WebcmdServerHandler.h
		${SOURCE_ROOT}/xcp-webcmd/server/handler/HandleCommon.h
		${SOURCE_ROOT}/xcp-webcmd/server/handler/HandleGetAccessKey.h
		${SOURCE_ROOT}/xcp-webcmd/server/handler/HandleResetAccessKey.h
		${SOURCE_ROOT}/xcp-webcmd/server/handler/HandlePropertyChanged.h
		${SOURCE_ROOT}/xcp-webcmd/server/handler/HandleEventOccurred.h
		${SOURCE_ROOT}/xcp-webcmd/client/WebcmdClient.h
		)

SET(XcpWebcmd_Source
		${SOURCE_ROOT}/xcp-webcmd/server/WebcmdServer.c
		${SOURCE_ROOT}/xcp-webcmd/server/handler/WebcmdServerHandler.c
		${SOURCE_ROOT}/xcp-webcmd/server/handler/HandleCommon.c
		${SOURCE_ROOT}/xcp-webcmd/server/handler/HandleGetAccessKey.c
		${SOURCE_ROOT}/xcp-webcmd/server/handler/HandleResetAccessKey.c
		${SOURCE_ROOT}/xcp-webcmd/server/handler/HandlePropertyChanged.c
		${SOURCE_ROOT}/xcp-webcmd/server/handler/HandleEventOccurred.c
		${SOURCE_ROOT}/xcp-webcmd/client/WebcmdClient.c
		)

set(COMPONENT_ADD_INCLUDEDIRS ${SOURCE_INC})
set(COMPONENT_SRCS
		${XcpCommon_Header}
		${XcpCommon_Source}
		${XcpMessage_Header}
		${XcpMessage_Source}
		${XcpMessageCodec_Header}
		${XcpMessageCodec_Source}
		${Xcpws_Header}
		${Xcpws_Source}
		${XcpWebcmd_Header}
		${XcpWebcmd_Source}
        )

set(COMPONENT_REQUIRES tinycrypto tinymdns tinyfx tiny)

register_component()

component_compile_definitions(TINY_STATIC)
component_compile_definitions(ESP8266)
component_compile_definitions(LWIP_SOCKET)
component_compile_definitions(ICACHE_FLASH)
#component_compile_definitions(TINY_DEBUG)

component_compile_options(-Wno-multichar)
component_compile_options(-Wno-pointer-to-int-cast)
component_compile_options(-fPIC)
component_compile_options(-std=gnu99)
