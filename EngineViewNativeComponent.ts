import type { HostComponent, ViewProps } from 'react-native';
import codegenNativeComponent from 'react-native/Libraries/Utilities/codegenNativeComponent';
import type { Double } from 'react-native/Libraries/Types/CodegenTypes';

export interface NativeEngineViewProps extends ViewProps {
  isTransparent: boolean;
  antiAliasing: Double;
  androidView: string;
}

export default codegenNativeComponent<NativeEngineViewProps>('EngineView') as HostComponent<NativeEngineViewProps>;
