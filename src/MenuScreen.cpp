#include "raylib.h"

#include "MenuScreen.h"
#include "GameScreen.h"
#include "StoryScreen.h"
#include "game.h"

Game::MenuScreen::MenuScreen() {
    backgroundTexture = LoadTexture("assets/graphics/Background_Space_Test_1.2.png");
}

Game::MenuScreen::~MenuScreen() {
    // Your screen cleanup code here...
}


void Game::MenuScreen::ProcessInput() {
    // Your process input code here...
    if (IsKeyPressed(KEY_ENTER)) currentScreen = Game::StoryScreen::getInstance();
}

void Game::MenuScreen::Update() {
    // Your update game code here...
}

void Game::MenuScreen::Draw() {
    // Your drawing code here...
    ClearBackground(RAYWHITE);
    DrawTexture(backgroundTexture, 0, 0, WHITE);
    DrawText("EXTERMINATUS", 90, 430, 50, RAYWHITE);
    DrawText("Press Enter to Start", 130, 600, 30, RAYWHITE);
}
