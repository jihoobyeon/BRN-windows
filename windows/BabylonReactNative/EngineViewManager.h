#pragma once
#include "NativeModules.h"
#include "winrt/Microsoft.ReactNative.h"
#include "EngineView.h"

namespace winrt::BabylonReactNative::implementation {

    struct EngineViewManager
        : winrt::implements<
        EngineViewManager,
        winrt::Microsoft::ReactNative::IViewManager,
        winrt::Microsoft::ReactNative::IViewManagerWithReactContext,
        winrt::Microsoft::ReactNative::IViewManagerWithNativeProperties,
        winrt::Microsoft::ReactNative::IViewManagerWithExportedEventTypeConstants> {
    public:
        EngineViewManager();

        // IViewManager
        winrt::hstring Name() const noexcept;
        winrt::BabylonReactNative::EngineView CreateView() noexcept;

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
        winrt::BabylonReactNative::EngineView _engineView{ nullptr };
    };

} // namespace winrt::BabylonReactNative::implementation

