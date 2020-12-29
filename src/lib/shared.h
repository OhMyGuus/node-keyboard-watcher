#ifndef ADDON_SRC_SHARED_H
#define ADDON_SRC_SHARED_H

struct KeyEvent {
  int keyId;
  char* stringType;
};

void emit_event(KeyEvent* e);

#endif