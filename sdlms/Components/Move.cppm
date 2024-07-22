module;

#include <optional>

export module components:move;
import :foothold;
import :ladderrope;
import core;

export struct Move
{
    float hspeed = 0.0;
    std::optional<float> hspeed_min = -125.0f;
    std::optional<float> hspeed_max = 125.0f;
    float vspeed = 0.0;
    std::optional<float> vspeed_min = -5000.0f;
    std::optional<float> vspeed_max = 670.0f;
    float hforce = 0.0;
    float vforce = 0.0;
    float hacc = 0.0;
    float vacc = 0.0;

    std::optional<float> rx0 = Map::Border::l;
    std::optional<float> rx1 = Map::Border::r;

    int page = 0;
    int zmass = 0;

    enum AREA : uint8_t
    {
        LAND,
        SWIM,
    };

    uint8_t area = LAND;

    FootHold *foo = nullptr;
    LadderRope *lr = nullptr;

    Move() = default;
};