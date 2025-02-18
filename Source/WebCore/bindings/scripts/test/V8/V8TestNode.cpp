/*
    This file is part of the WebKit open source project.
    This file has been generated by generate-bindings.pl. DO NOT MODIFY!

    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Library General Public
    License as published by the Free Software Foundation; either
    version 2 of the License, or (at your option) any later version.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Library General Public License for more details.

    You should have received a copy of the GNU Library General Public License
    along with this library; see the file COPYING.LIB.  If not, write to
    the Free Software Foundation, Inc., 59 Temple Place - Suite 330,
    Boston, MA 02111-1307, USA.
*/

#include "config.h"
#include "V8TestNode.h"

#include "BindingState.h"
#include "ContextFeatures.h"
#include "Frame.h"
#include "RuntimeEnabledFeatures.h"
#include "V8Binding.h"
#include "V8DOMWrapper.h"
#include "V8Node.h"
#include <wtf/UnusedParam.h>

namespace WebCore {

WrapperTypeInfo V8TestNode::info = { V8TestNode::GetTemplate, V8TestNode::derefObject, 0, 0, &V8Node::info, WrapperTypeObjectPrototype };

namespace TestNodeV8Internal {

template <typename T> void V8_USE(T) { }

} // namespace TestNodeV8Internal

v8::Handle<v8::Value> V8TestNode::constructorCallback(const v8::Arguments& args)
{
    INC_STATS("DOM.TestNode.Constructor");

    if (!args.IsConstructCall())
        return throwTypeError("DOM object constructor cannot be called as a function.");

    if (ConstructorMode::current() == ConstructorMode::WrapExistingObject)
        return args.Holder();

    RefPtr<TestNode> impl = TestNode::create();
    v8::Handle<v8::Object> wrapper = args.Holder();

    V8DOMWrapper::setDOMWrapper(wrapper, &info, impl.get());
    V8DOMWrapper::setJSWrapperForDOMNode(impl.release(), wrapper, args.GetIsolate());
    return wrapper;
}

static v8::Persistent<v8::FunctionTemplate> ConfigureV8TestNodeTemplate(v8::Persistent<v8::FunctionTemplate> desc)
{
    desc->ReadOnlyPrototype();

    v8::Local<v8::Signature> defaultSignature;
    defaultSignature = V8DOMConfiguration::configureTemplate(desc, "TestNode", V8Node::GetTemplate(), V8TestNode::internalFieldCount,
        0, 0,
        0, 0);
    UNUSED_PARAM(defaultSignature); // In some cases, it will not be used.
    desc->SetCallHandler(V8TestNode::constructorCallback);
    

    // Custom toString template
    desc->Set(v8::String::NewSymbol("toString"), V8PerIsolateData::current()->toStringTemplate());
    return desc;
}

v8::Persistent<v8::FunctionTemplate> V8TestNode::GetRawTemplate()
{
    V8PerIsolateData* data = V8PerIsolateData::current();
    V8PerIsolateData::TemplateMap::iterator result = data->rawTemplateMap().find(&info);
    if (result != data->rawTemplateMap().end())
        return result->second;

    v8::HandleScope handleScope;
    v8::Persistent<v8::FunctionTemplate> templ = createRawTemplate();
    data->rawTemplateMap().add(&info, templ);
    return templ;
}

v8::Persistent<v8::FunctionTemplate> V8TestNode::GetTemplate()
{
    V8PerIsolateData* data = V8PerIsolateData::current();
    V8PerIsolateData::TemplateMap::iterator result = data->templateMap().find(&info);
    if (result != data->templateMap().end())
        return result->second;

    v8::HandleScope handleScope;
    v8::Persistent<v8::FunctionTemplate> templ =
        ConfigureV8TestNodeTemplate(GetRawTemplate());
    data->templateMap().add(&info, templ);
    return templ;
}

bool V8TestNode::HasInstance(v8::Handle<v8::Value> value)
{
    return GetRawTemplate()->HasInstance(value);
}


v8::Handle<v8::Object> V8TestNode::wrapSlow(PassRefPtr<TestNode> impl, v8::Handle<v8::Object> creationContext, v8::Isolate* isolate)
{
    v8::Handle<v8::Object> wrapper;
    ASSERT(static_cast<void*>(static_cast<Node*>(impl.get())) == static_cast<void*>(impl.get()));
    Document* document = 0;
    UNUSED_PARAM(document);
    document = impl->document(); 

    v8::Handle<v8::Context> context;
    if (!creationContext.IsEmpty() && creationContext->CreationContext() != v8::Context::GetCurrent()) {
        // For performance, we enter the context only if the currently running context
        // is different from the context that we are about to enter.
        context = v8::Local<v8::Context>::New(creationContext->CreationContext());
        ASSERT(!context.IsEmpty());
        context->Enter();
    }

    wrapper = V8DOMWrapper::instantiateV8Object(document, &info, impl.get());

    if (!context.IsEmpty())
        context->Exit();

    if (UNLIKELY(wrapper.IsEmpty()))
        return wrapper;
    v8::Persistent<v8::Object> wrapperHandle = V8DOMWrapper::setJSWrapperForDOMNode(impl, wrapper, isolate);
    if (!hasDependentLifetime)
        wrapperHandle.MarkIndependent();
    wrapperHandle.SetWrapperClassId(v8DOMSubtreeClassId);
    return wrapper;
}

void V8TestNode::derefObject(void* object)
{
    static_cast<TestNode*>(object)->deref();
}

} // namespace WebCore
