#ifndef HEADER_SDLMS_MAIN
#define HEADER_SDLMS_MAIN


#include "util/map_util.hpp"
#include "util/wz_util.hpp"
#include "util/sound_util.hpp"
#include "util/hud_util.hpp"
#include "util/ffmpeg.hpp"
#include "util/freetype.hpp"
#include "util/string_util.hpp"
#include "util/sprite_util.hpp"

#include "sdlms/camera.hpp"
#include "sdlms/graphics.hpp"
#include "sdlms/input.hpp"
#include "sdlms/map.hpp"
#include "sdlms/sound.hpp"
#include "sdlms/hud.hpp"




using namespace util;

class Main final
{

public:
    int run(int argc, char **argv);

private:
    std::unique_ptr<WzUtil> _wz_util;
    std::unique_ptr<MapUtil> _map_util;
    std::unique_ptr<SoundUtil> _sound_util;
    std::unique_ptr<HudUtil> _hud_util;
    std::unique_ptr<SpriteUtil> _sprite_util;
    std::unique_ptr<Camera> _camera;
    std::unique_ptr<Graphics> _graphics;
    std::unique_ptr<Input> _input;
    std::unique_ptr<Map> _map;
    std::unique_ptr<Hud> _hud;
    std::unique_ptr<Sound> _sound;
    std::unique_ptr<FFMPEG> _ffmpeg;
    std::unique_ptr<FreeType> _freetype;
    std::unique_ptr<StringUtil> _string_util;
    
};
#endif