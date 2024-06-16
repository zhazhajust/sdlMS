#pragma once
#include "Systems/System.h"
#include "Components/AnimatedSprite.h"
#include "Components/Transform.h"
#include "Components/HVMove.h"
#include "Components/Avatar.h"
#include "Components/Video.h"
#include "Components/Signal.h"

#include "Entities/Portal.h"

class DeltaTimeSystem : public System
{
public:
	void run(World &world) override;
	
	Signal<int> frame_signal;

private:
	bool update_animated_sprite(AnimatedSprite *aspr, World &world);
	void update_avatar(Avatar *hvm, World &world);
};
