#include "sdlms/minimap.hpp"


void MiniMap::draw()
{
    for (auto &it : _s)
    {
        it._draw();
    }
}