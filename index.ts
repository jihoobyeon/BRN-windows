const BabylonModule = require('./NativeBabylon').defualt;

export function initialize(): Promise<boolean> {
  return BabylonModule.initialize();
}

export function resetView(): Promise<boolean> {
  return BabylonModule.resetView();
}
