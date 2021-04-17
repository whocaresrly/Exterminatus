#include "raylib.h"

#include "game.h"
#include "MenuScreen.h"

void Game::MenuScreen::ProcessInput() {
    // Your process input code here...
    if (IsKeyPressed(KEY_ENTER)) currentScreen = &gameScreen;
}

void Game::MenuScreen::Update() {
    // Your update game code here...
}

void Game::MenuScreen::Draw() {
    // Your drawing code here...
    ClearBackground(RAYWHITE);
    DrawText("Menu - press ENTER to start game", 10, 10, 30, LIGHTGRAY);
}
