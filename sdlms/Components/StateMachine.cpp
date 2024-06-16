#include "Components/Physic/Normal.h"
#include <iostream>
#include <memory>
#include "Components/Physic/Normal.h"

// 前向声明 Player 类
class Player;

// 状态基类
class PlayerState {
public:
    virtual ~PlayerState() = default;
    
    virtual void enter(Player& Player) = 0;
    virtual void execute(Player& Player) = 0;
    virtual void exit(Player& Player) = 0;
};

// 前向声明状态类
class MovingState;
class ClimbingState;
class JumpingState;
class AttackingState;

class MovingState : public PlayerState {
public:
    void enter(Player& Player) override {
        std::cout << "Entering Moving State" << std::endl;
    }
    
    void execute(Player& Player) override {
        std::cout << "Executing Moving State" << std::endl;
        // 移动逻辑
    }
    
    void exit(Player& Player) override {
        std::cout << "Exiting Moving State" << std::endl;
    }
};

class ClimbingState : public PlayerState {
public:
    void enter(Player& Player) override {
        std::cout << "Entering Climbing State" << std::endl;
    }
    
    void execute(Player& Player) override {
        std::cout << "Executing Climbing State" << std::endl;
        // 攀爬逻辑
    }
    
    void exit(Player& Player) override {
        std::cout << "Exiting Climbing State" << std::endl;
    }
};

class JumpingState : public PlayerState {
public:
    void enter(Player& Player) override {
        std::cout << "Entering Jumping State" << std::endl;
    }
    
    void execute(Player& Player) override {
        std::cout << "Executing Jumping State" << std::endl;
        // 跳跃逻辑
    }
    
    void exit(Player& Player) override {
        std::cout << "Exiting Jumping State" << std::endl;
    }
};

class AttackingState : public PlayerState {
public:
    void enter(Player& Player) override {
        std::cout << "Entering Attacking State" << std::endl;
    }
    
    void execute(Player& Player) override {
        std::cout << "Executing Attacking State" << std::endl;
        // 攻击逻辑
    }
    
    void exit(Player& Player) override {
        std::cout << "Exiting Attacking State" << std::endl;
    }
};


class Player {
public:
    Player() : currentState(nullptr) {}

    void changeState(std::unique_ptr<PlayerState> newState) {
        if (currentState) {
            currentState->exit(*this);
        }
        currentState = std::move(newState);
        if (currentState) {
            currentState->enter(*this);
        }
    }

    void update() {
        if (currentState) {
            currentState->execute(*this);
        }
    }

private:
    std::unique_ptr<PlayerState> currentState;
};

void handleInput(Normal* norm, Player* Player) {
    if (norm->vkey == Normal::Left or Normal::Right) {
        Player->changeState(std::make_unique<MovingState>());
    } else if (norm->lctrl == Normal::Attack) {
        Player->changeState(std::make_unique<AttackingState>());
    } else if (norm->vkey == Normal::Up) {
        Player->changeState(std::make_unique<ClimbingState>());
    } else if (norm->vkey == Normal::Down) {
        Player->changeState(std::make_unique<JumpingState>());
    }
}
