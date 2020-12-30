import { keyboardWatcher } from '..'

keyboardWatcher.start(); // key B


keyboardWatcher.addKeyHook(0x42)
process.stdin.resume();
