#include "Menu.hpp"

#include <imgui.h>

#include <Morkovka2D/Application.hpp>
#include <Morkovka2D/LevelManager.hpp>

void Menu::update(double deltaTime) {
    ImVec2 displaySize = ImGui::GetIO().DisplaySize;
    ImGui::SetNextWindowPos(ImVec2(0.0f, 0.0f));
    ImGui::SetNextWindowSize(displaySize);  
    ImGui::Begin("Menu", nullptr, ImGuiWindowFlags_NoDecoration | ImGuiWindowFlags_NoResize); 
    ImGui::SetCursorPos(ImVec2(100, 200));
    if(ImGui::Button("Level 1", ImVec2(displaySize.x - 200, 100))) {
        Application::getInstance()->loadLevel(getLevelWithIndex(0));
    }
    ImGui::SetCursorPos(ImVec2(100, 400));
    if(ImGui::Button("Level 2", ImVec2(displaySize.x - 200, 100))) {
        Application::getInstance()->loadLevel(getLevelWithIndex(1));
    }
    ImGui::SetCursorPos(ImVec2(100, 600));
    if(ImGui::Button("Exit", ImVec2(displaySize.x - 200, 100))) {
        Application::getInstance()->close();
    }
    ImGui::End();
}