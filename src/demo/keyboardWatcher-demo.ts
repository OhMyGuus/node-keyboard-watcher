import { keyboardWatcher } from '..'

keyboardWatcher.start(); // key B


keyboardWatcher.addKeyHook(0x42)
console.log("Ketwatcger started abd watching input for key: B");

keyboardWatcher.on('keydown', (keyid) => {
    console.log("Keydown event: ", keyid);
});

keyboardWatcher.on('keyup', (keyid) => {
    console.log("Keyup event: ", keyid);
});

process.stdin.resume();
