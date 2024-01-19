#ifndef HEADER_SDLMS_INPUT
#define HEADER_SDLMS_INPUT

#include <SDL2/SDL.h>
#include <map>
#include "util/currenton.hpp"

#include "sdlms/map.hpp"
#include "sdlms/camera.hpp"

class Input : public Currenton<Input>
{
public:
	Input();

	void beginNewFrame();
	void keyUpEvent(const SDL_Event &event);
	void keyDownEvent(const SDL_Event &event);

	bool wasKeyPressed(SDL_Scancode key);
	bool wasKeyReleased(SDL_Scancode key);
	bool isKeyHeld(SDL_Scancode key);

	int loop();

private:
	std::map<SDL_Scancode, bool> _heldKeys;
	std::map<SDL_Scancode, bool> _pressedKeys;
	std::map<SDL_Scancode, bool> _releasedKeys;
};

#endif
