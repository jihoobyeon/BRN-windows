const BabylonModule = require('./NativeBabylon').defualt;

export function initialize(): Promise<void> {
  return BabylonModule.initialize();
}

export function resetView(): Promise<void> {
  return BabylonModule.resetView();
}
