import { initialize, resetView } from '@babylonjs/react-native-windows-module';
// This legacy React Native module is created by Babylon React Native, and is only used to bootstrap the JSI object creation.
// This will likely be removed when the BabylonNative global object is eventually converted to a TurboModule.
export async function ensureInitialized() {
    // This does the first stage of Babylon Native initialization, including creating the BabylonNative JSI object.
    await initialize();
    return true;
}
export async function reset() {
    return resetView();
}
//# sourceMappingURL=BabylonModule.js.map