SET(WEBKIT_TESTNETSCAPEPLUGIN_DIR "${TOOLS_DIR}/DumpRenderTree/TestNetscapePlugIn")

SET(WebKitTestNetscapePlugin_SOURCES
    ${WEBKIT_TESTNETSCAPEPLUGIN_DIR}/PluginObject.cpp
    ${WEBKIT_TESTNETSCAPEPLUGIN_DIR}/PluginTest.cpp
    ${WEBKIT_TESTNETSCAPEPLUGIN_DIR}/TestObject.cpp
    ${WEBKIT_TESTNETSCAPEPLUGIN_DIR}/main.cpp

    ${WEBKIT_TESTNETSCAPEPLUGIN_DIR}/Tests/DocumentOpenInDestroyStream.cpp
    ${WEBKIT_TESTNETSCAPEPLUGIN_DIR}/Tests/EvaluateJSAfterRemovingPluginElement.cpp
    ${WEBKIT_TESTNETSCAPEPLUGIN_DIR}/Tests/FormValue.cpp
    ${WEBKIT_TESTNETSCAPEPLUGIN_DIR}/Tests/GetURLNotifyWithURLThatFailsToLoad.cpp
    ${WEBKIT_TESTNETSCAPEPLUGIN_DIR}/Tests/GetURLWithJavaScriptURL.cpp
    ${WEBKIT_TESTNETSCAPEPLUGIN_DIR}/Tests/GetURLWithJavaScriptURLDestroyingPlugin.cpp
    ${WEBKIT_TESTNETSCAPEPLUGIN_DIR}/Tests/GetUserAgentWithNullNPPFromNPPNew.cpp
    ${WEBKIT_TESTNETSCAPEPLUGIN_DIR}/Tests/NPDeallocateCalledBeforeNPShutdown.cpp
    ${WEBKIT_TESTNETSCAPEPLUGIN_DIR}/Tests/NPPNewFails.cpp
    ${WEBKIT_TESTNETSCAPEPLUGIN_DIR}/Tests/NPPSetWindowCalledDuringDestruction.cpp
    ${WEBKIT_TESTNETSCAPEPLUGIN_DIR}/Tests/NPRuntimeObjectFromDestroyedPlugin.cpp
    ${WEBKIT_TESTNETSCAPEPLUGIN_DIR}/Tests/NPRuntimeRemoveProperty.cpp
    ${WEBKIT_TESTNETSCAPEPLUGIN_DIR}/Tests/NullNPPGetValuePointer.cpp
    ${WEBKIT_TESTNETSCAPEPLUGIN_DIR}/Tests/PassDifferentNPPStruct.cpp
    ${WEBKIT_TESTNETSCAPEPLUGIN_DIR}/Tests/PluginScriptableNPObjectInvokeDefault.cpp
    ${WEBKIT_TESTNETSCAPEPLUGIN_DIR}/Tests/PrivateBrowsing.cpp
    ${WEBKIT_TESTNETSCAPEPLUGIN_DIR}/Tests/x11/CallInvalidateRectWithNullNPPArgument.cpp
)

SET(WebKitTestNetscapePlugin_INCLUDE_DIRECTORIES
    ${WEBKIT_TESTNETSCAPEPLUGIN_DIR}
    ${WEBKIT_TESTNETSCAPEPLUGIN_DIR}/unix/ForwardingHeaders
    ${WEBCORE_DIR}
)

INCLUDE_DIRECTORIES(${WebKitTestNetscapePlugin_INCLUDE_DIRECTORIES})

ADD_LIBRARY(TestNetscapePlugin SHARED ${WebKitTestNetscapePlugin_SOURCES})
