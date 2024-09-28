#pragma once

#if __has_include("codegen\NativeBabylonDataTypes.g.h")
#include "codegen\NativeBabylonDataTypes.g.h"
#endif
#include "codegen\NativeBabylonSpec.g.h"

#include "NativeModules.h"

namespace winrt::BabylonReactNative::implementation {
    REACT_MODULE(BabylonModule, L"BabylonModule");
    struct BabylonModule : std::enable_shared_from_this<BabylonModule>
    {
        using ModuleSpec = BabylonModuleCodegen::BabylonModuleSpec;

        REACT_INIT(Initialize);
        void Initialize(const winrt::Microsoft::ReactNative::ReactContext& reactContext) noexcept;

        REACT_METHOD(CustomInitialize, L"initialize");
        void CustomInitialize(const winrt::Microsoft::ReactNative::ReactPromise<bool>& result) noexcept;

        REACT_METHOD(ResetView, L"resetView");
        void ResetView(const winrt::Microsoft::ReactNative::ReactPromise<bool>& result) noexcept;

    private:
         winrt::Microsoft::ReactNative::ReactContext _reactContext;
    };
} // namespace winrt::BabylonReactNative::implementation
