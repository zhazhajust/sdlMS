#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include "Core/Window.h"
#include "Resource/Wz.h"
#include "Core/Map.h"
#include "Systems/Render.h"
#include "Core/Camera.h"
#include "Systems/Animate.h"

int width = 1920;
int height = 1080;

void main_loop()
{
    if (Window::quit)
    {
#ifdef __EMSCRIPTEN__
        emscripten_cancel_main_loop(); /* this should "kill" the app. */
#else
        exit(0);
#endif
    }
    Window::poll_events();
    Window::tick_delta_time();
    Window::clear();

    Render::run();
    Animate::run();

    Window::update();
}

int main(int argc, char *argv[])
{
    Camera::y = -500;
    
    Camera::w = width;
    Camera::h = height;

    Wz::init("./Data/");
    Window::create_window("sdlMS", width, height);

    // SDL_CreateTexture()
    Map::load(100000000);

    while (true)
    {
        main_loop();
    }
}