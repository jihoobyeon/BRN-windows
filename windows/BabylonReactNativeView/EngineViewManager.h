#pragma once
#include "NativeModules.h"
#include "winrt/Microsoft.ReactNative.h"
#include <winrt/Microsoft.UI.Composition.h>
#include "EngineView.h"
#include "codegen/react/components/EngineView/EngineView.g.h"

namespace winrt::BabylonReactNativeView::implementation {
    struct EngineViewManager
        : winrt::implements<EngineViewManager, winrt::IInspectable>, winrt::EngineView::Codegen::BaseEngineView<EngineViewManager> {
    public:
        EngineViewManager();

        // IViewManager
        winrt::hstring Name() const noexcept;
        winrt::BabylonReactNativeView::EngineView CreateView() noexcept;

        // IViewManagerWithReactContext
        winrt::Microsoft::ReactNative::IReactContext ReactContext() noexcept;
        void ReactContext(winrt::Microsoft::ReactNative::IReactContext reactContext) noexcept;

        // IViewManagerWithNativeProperties
        winrt::Windows::Foundation::Collections::
            IMapView<winrt::hstring, winrt::Microsoft::ReactNative::ViewManagerPropertyType>
            NativeProps() noexcept;
        void UpdateProperties(
            winrt::Microsoft::UI::Xaml::FrameworkElement const view,
            winrt::Microsoft::ReactNative::IJSValueReader const& propertyMapReader) noexcept;

        // IViewManagerWithExportedEventTypeConstants
        winrt::Microsoft::ReactNative::ConstantProviderDelegate ExportedCustomBubblingEventTypeConstants() noexcept;
        winrt::Microsoft::ReactNative::ConstantProviderDelegate ExportedCustomDirectEventTypeConstants() noexcept;

    private:
        winrt::Microsoft::ReactNative::IReactContext _reactContext{ nullptr };
        winrt::BabylonReactNativeView::EngineView _engineView{ nullptr };
    };

    void RegisterEngineViewNativeComponent(winrt::Microsoft::ReactNative::IReactPackageBuilder const& builder) noexcept;
} // namespace winrt::BabylonReactNative::implementation