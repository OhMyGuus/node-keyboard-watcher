
#include "keyhandler.h"
#include <iostream> 
#include <map> 
#include <uv.h>
#include "shared.h"

static uv_thread_t hook_tid;

enum class keystate
{
	Up,
	Down
};

std::map<int, keystate> key_map = {};

void AddKeyHandler(int keyId)
{
	key_map.insert(std::pair<char, keystate>(keyId, keystate::Up));
}

void ClearKeyHooks(){
	key_map.clear();
}

void RemoveKeyHandler(int keyId)
{
}

void OnkeyUp(int keyId)
{
	emit_event(new KeyEvent{keyId,"keyup"});
}

void OnKeyDown(int keyId)
{
	emit_event(new KeyEvent{keyId,"keydown"});
}

static void keywatcher_thread(void *_arg)
{
//	AddKeyHandler(0x4E);
	// AddKeyHandler(0x4F);

	while (true)
	{
		for (auto const &x : key_map)
		{
			auto oldState = x.second;
			auto currentstate = GetKeyState(x.first) < 0 ? keystate::Down : keystate::Up;
			if (oldState != currentstate)
			{
				if (currentstate == keystate::Up)
					OnkeyUp(x.first);
				if (currentstate == keystate::Down)
					OnKeyDown(x.first);
			}
			key_map[x.first] = currentstate;
		}
		Sleep(50);
	}
}

 void StartKeyHandler(){
	  uv_thread_create(&hook_tid, keywatcher_thread, NULL);

}

