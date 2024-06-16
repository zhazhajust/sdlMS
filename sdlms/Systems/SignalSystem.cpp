#include "Components/Player.h"
#include "Components/Signal.h"
#include "DeltaTimeSystem.h"
#include "Components/Player.h"

class SignalSystem : public System{
    void run(class World& world){
        DeltaTimeSystem deltatime = world.get_delta_time();
        deltatime.frame_signal.connect(std::bind(&Player::onFrameEnd, &player, std::placeholders::_1));
    }
};

