import { keyboardWatcher } from '..'

// overlayWindow.addListener(0x42); // key B
keyboardWatcher.start(); // key B


keyboardWatcher.addKeyHook()
process.stdin.resume();
