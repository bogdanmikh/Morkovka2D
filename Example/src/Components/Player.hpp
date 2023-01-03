#pragma once

#include <Morkovka2D/GameObject.hpp>
#include <Morkovka2D/Sprite.hpp>
#include <Morkovka2D/Camera.hpp>

class Player: public GameObject, public Sprite {
public:
    int money = 0;
    int maxMoney = 0;
    Player(Shader* shader, Camera* camera);
    void update(double deltaTime) override;
    void showGameOver();
    void jump(float force);
    
    bool time_freze;
    bool isInvincible;
    float time;
private:
    bool isPlaying;
    bool isGrounded;
    float verticalForce = 0.f;
    float gravity = -9.8f;
    float jumpForce = 6.f;
    float moveSpeed = 3.f;
    Camera *camera;
};