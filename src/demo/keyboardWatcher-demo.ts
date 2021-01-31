import { keyboardWatcher } from '..'

keyboardWatcher.start(); // key B


keyboardWatcher.addKeyHook(162)
console.log("Started keyboard watcher.. ");

keyboardWatcher.on('keydown', (keyid) => {
    console.log("Keydown event: ", keyid.toString(16).toUpperCase());
});

keyboardWatcher.on('keyup', (keyid) => {
    console.log("Keyup event: ", keyid.toString(16).toUpperCase());
});

process.stdin.resume();
