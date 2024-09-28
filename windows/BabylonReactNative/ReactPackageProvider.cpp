#include "pch.h"

#include "ReactPackageProvider.h"
#if __has_include("ReactPackageProvider.g.cpp")
#include "ReactPackageProvider.g.cpp"
#endif

#include "BabylonModule.h"
#include "EngineViewManager.h"

using namespace winrt::Microsoft::ReactNative;

namespace winrt::BabylonReactNative::implementation
{

void ReactPackageProvider::CreatePackage(IReactPackageBuilder const &packageBuilder) noexcept
{
  AddAttributedModules(packageBuilder, true);

  packageBuilder.AddModule(L"BabylonModule", MakeModuleProvider<BabylonModule>());
  RegisterEngineViewNativeComponent(packageBuilder);
}

} // namespace winrt::BabylonReactNative::implementation
