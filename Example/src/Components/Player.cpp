#include "Player.hpp"

#include "GameOverLabel.hpp"
#include <Morkovka2D/Application.hpp>
#include <Morkovka2D/LevelManager.hpp>
#include <Morkovka2D/CollisionDetector.hpp>
#include <Morkovka2D/Camera.hpp>

#include <imgui.h>

Player::Player(Shader* shader, Camera* camera)
    : Sprite("textures/Mushroomer.png", shader)
    , camera(camera)
    , isPlaying(true)
    , time_freze(false)
    , isInvincible(false) {
    setPosition(0.f, 0.5f, 0.f);
    setSize(1., 1.);
}

void Player::jump(float force) {
    verticalForce = force;
}

void Player::update(double deltaTime) {
    isGrounded = false;
    camera->setPosition(getMaxX(), getMaxY(), 5.f);
    verticalForce += gravity * deltaTime;
    float horizontalSpeed = deltaTime * moveSpeed;
    float verticalSpeed = deltaTime * verticalForce;

    if(time_freze == false) {
        time -= deltaTime;
    }

    if(std::abs(verticalForce) > 0.1f) {
        if(verticalForce >= 0.f) {
            if(CollisionDetector::moveAcceptable(this, Direction::UP, verticalSpeed)) {
                translate(0.f, verticalSpeed, 0.f);
            } else {
                verticalForce = 0.f;
            }
        } else {
            if(CollisionDetector::moveAcceptable(this, Direction::DOWN, verticalSpeed)) {
                translate(0.f, verticalSpeed, 0.f);
            } else {
                verticalForce = 0.f;
                isGrounded = true;
            }
        }
    }

    // Если игрок упал слишком низко (за карту) - перезагрузка уровня
    if (getMinY() < -10.f) {
        Application::getInstance()->loadLevel(getCurrentLevel());
        return;
    }

    if(Application::getInstance()->window->isKeyPressed(Key::SPACE) && isGrounded) {
        jump(jumpForce);
    }

    if(Application::getInstance()->window->isKeyPressed(Key::A)
        && CollisionDetector::moveAcceptable(this, Direction::LEFT, -horizontalSpeed)) {
        translate(-horizontalSpeed , 0.f, 0.f);
    }
    if(Application::getInstance()->window->isKeyPressed(Key::D)
        && CollisionDetector::moveAcceptable(this, Direction::RIGHT, horizontalSpeed)) {
        translate(horizontalSpeed, 0.f, 0.f);
    }

    if(time <= 0 && time_freze == false) {
        showGameOver();
    }

    auto& colors = ImGui::GetStyle().Colors;
	colors[ImGuiCol_WindowBg] = ImVec4{ 0.f, 0.f, 0.f, 0.f }; 
    //задать позицию у окна
    ImGui::SetNextWindowPos(ImVec2(0, 0));
    ImGui::SetNextWindowSize(ImGui::GetIO().DisplaySize);  
    ImGui::Begin("Player info", nullptr, ImGuiWindowFlags_NoDecoration | ImGuiWindowFlags_NoResize);
    ImGui::Text("Player, x: %f, y: %f", getMinX(), getMinY());  
    if(time_freze == false) {  
        ImGui::Text("Time left: %f", time);
    }
    //сдвинуть кнопку перед созданием её 
    ImGui::SetCursorPos(ImVec2(10, 50));
    if(ImGui::Button("RESTART LEVEL", ImVec2(200, 50))) {
        ImGui::End();
        Application::getInstance()->loadLevel(getCurrentLevel());
        return;
    }
    if(ImGui::Button(isInvincible ? "MAKE VUNERABLE" : "MAKE INVINCIBLE", ImVec2(200, 50))) {
        isInvincible = isInvincible == false;
    }
    if(ImGui::Button(time_freze ? "Time Off" : "Time On" , ImVec2(200, 50))) {
        time_freze = time_freze == false;
    }
    if(ImGui::Button("SUPER JUMP", ImVec2(200, 50))) {
        jump(15.f);
    }
    ImGui::Text("Money: %d of %d", money, maxMoney);
    if(ImGui::Button("MENU", ImVec2(200, 50))) {
        ImGui::End();
        Application::getInstance()->loadLevel(getMenuLevel());
        return;
    }
    ImGui::End();

    draw();
}

void Player::showGameOver() {
    if(isPlaying == false) { return; } 
    Application::getInstance()->world.addActor(new GameOverLabel(shader, this));
    isPlaying = false;
}