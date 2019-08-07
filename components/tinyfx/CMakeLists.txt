set(SOURCE_ROOT tinyfx/source/src)
set(SOURCE_INC
        ${SOURCE_ROOT}/IotTypedef
        ${SOURCE_ROOT}/IotFactory
        ${SOURCE_ROOT}/IotLauncher)

#-----------------------
# IotTypedef
#-----------------------

SET(IotTypedef_Header
        ${SOURCE_ROOT}/IotTypedef/constant/iot_constant.h
        ${SOURCE_ROOT}/IotTypedef/product/Product.h
        ${SOURCE_ROOT}/IotTypedef/product/config/ProductConfig.h
        ${SOURCE_ROOT}/IotTypedef/product/config/AccessoryCategoryIdentifier.h
        ${SOURCE_ROOT}/IotTypedef/product/config/AccessoryConfig.h
        ${SOURCE_ROOT}/IotTypedef/product/handler/IdentifyListener.h
        ${SOURCE_ROOT}/IotTypedef/product/handler/PropertyHandler.h
        ${SOURCE_ROOT}/IotTypedef/product/handler/ActionHandler.h
        ${SOURCE_ROOT}/IotTypedef/product/operator/ProductOperator.h
        ${SOURCE_ROOT}/IotTypedef/device/Device.h
        ${SOURCE_ROOT}/IotTypedef/device/Service.h
        ${SOURCE_ROOT}/IotTypedef/device/Action.h
        ${SOURCE_ROOT}/IotTypedef/device/Event.h
        ${SOURCE_ROOT}/IotTypedef/device/Property.h
        ${SOURCE_ROOT}/IotTypedef/device/Argument.h
        ${SOURCE_ROOT}/IotTypedef/device/access/Access.h
        ${SOURCE_ROOT}/IotTypedef/device/format/Format.h
        ${SOURCE_ROOT}/IotTypedef/device/constraint/ValueList.h
        ${SOURCE_ROOT}/IotTypedef/device/constraint/ValueRange.h
        ${SOURCE_ROOT}/IotTypedef/operation/AID.h
        ${SOURCE_ROOT}/IotTypedef/operation/EID.h
        ${SOURCE_ROOT}/IotTypedef/operation/PID.h
        ${SOURCE_ROOT}/IotTypedef/operation/ActionOperation.h
        ${SOURCE_ROOT}/IotTypedef/operation/EventOperation.h
        ${SOURCE_ROOT}/IotTypedef/operation/PropertyOperation.h
        ${SOURCE_ROOT}/IotTypedef/operation/PropertyOperations.h
        ${SOURCE_ROOT}/IotTypedef/operation/PropertyOperations.h
        ${SOURCE_ROOT}/IotTypedef/urn/Urn.h
        ${SOURCE_ROOT}/IotTypedef/urn/UrnType.h
        ${SOURCE_ROOT}/IotTypedef/unit/Unit.h
        ${SOURCE_ROOT}/IotTypedef/api/iot_api.h
        )

SET(IotTypedef_Source
        ${SOURCE_ROOT}/IotTypedef/product/Product.c
        ${SOURCE_ROOT}/IotTypedef/product/operator/ProductOperator.c
        ${SOURCE_ROOT}/IotTypedef/device/Device.c
        ${SOURCE_ROOT}/IotTypedef/device/Service.c
        ${SOURCE_ROOT}/IotTypedef/device/Action.c
        ${SOURCE_ROOT}/IotTypedef/device/Event.c
        ${SOURCE_ROOT}/IotTypedef/device/Property.c
        ${SOURCE_ROOT}/IotTypedef/device/Argument.c
        ${SOURCE_ROOT}/IotTypedef/device/access/Access.c
        ${SOURCE_ROOT}/IotTypedef/device/format/Format.c
        ${SOURCE_ROOT}/IotTypedef/device/constraint/ValueList.c
        ${SOURCE_ROOT}/IotTypedef/device/constraint/ValueRange.c
        ${SOURCE_ROOT}/IotTypedef/operation/PID.c
        ${SOURCE_ROOT}/IotTypedef/operation/ActionOperation.c
        ${SOURCE_ROOT}/IotTypedef/operation/EventOperation.c
        ${SOURCE_ROOT}/IotTypedef/operation/PropertyOperation.c
        ${SOURCE_ROOT}/IotTypedef/operation/PropertyOperations.c
        ${SOURCE_ROOT}/IotTypedef/urn/Urn.c
        ${SOURCE_ROOT}/IotTypedef/urn/UrnType.c
        )

#-----------------------
# IotLauncher
#-----------------------

SET(IotLauncher_Header
        ${SOURCE_ROOT}/IotLauncher/IotLauncher.h
        ${SOURCE_ROOT}/IotLauncher/IotRuntime.h
        )

SET(IotLauncher_Source
        ${SOURCE_ROOT}/IotLauncher/IotLauncher.c
        ${SOURCE_ROOT}/IotLauncher/IotRuntime.c
        )

#-----------------------
# IotFactory
#-----------------------

SET(IotFactory_Header
        ${SOURCE_ROOT}/IotFactory/ProductFactory.h
        )

SET(IotFactory_Source
        ${SOURCE_ROOT}/IotFactory/ProductFactory.c
        )

set(COMPONENT_ADD_INCLUDEDIRS ${SOURCE_INC})
set(COMPONENT_SRCS
        ${IotTypedef_Header}
        ${IotTypedef_Source}
        ${IotLauncher_Header}
        ${IotLauncher_Source}
        ${IotFactory_Header}
        ${IotFactory_Source}
        )


set(COMPONENT_REQUIRES tiny)

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
