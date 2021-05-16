#include "raylib.h"

#include "MenuScreen.h"
#include "GameScreen.h"
#include "GamefinishedScreen.h"
#include "game.h"

Game::GamefinishedScreen::GamefinishedScreen() {

}

Game::GamefinishedScreen::~GamefinishedScreen() {
    // Your screen cleanup code here...
}


void Game::GamefinishedScreen::ProcessInput() {
    // Your process input code here...
    if (IsKeyPressed(KEY_ENTER)) currentScreen = Game::MenuScreen::getInstance();
}

void Game::GamefinishedScreen::Update() {
    // Your update game code here...
}

void Game::GamefinishedScreen::Draw() {
    // Your drawing code here...
    ClearBackground(BLACK);
    DrawText("Congratulations!", 100, 470, 50, WHITE);
    DrawText("You did it...", 160, 525, 50, WHITE);
}
