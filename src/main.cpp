#include "raylib.h"
#include "raymath.h"
#include "game.h"
#include <iostream>

double lastUpdateTime = 0;

bool EventTriggered(double interval)
{
  double currentTime = GetTime();
  if (currentTime - lastUpdateTime >= interval)
  {
    lastUpdateTime = currentTime;
    return true;
  }
  return false;
}

int main()
{
  InitWindow(720, 720, "Raylib Tetris");
  SetTargetFPS(60);

  Font font = LoadFont("assets/fonts/joystix_monospace.otf");

  Texture2D grid = LoadTextureFromImage(LoadImage("assets/textures/tetris_grid.png"));
  Texture2D grid_2 = LoadTextureFromImage(LoadImage("assets/textures/grid_2.png"));
  Texture2D title = LoadTextureFromImage(LoadImage("assets/textures/tetris_title.png"));

  Texture2D block_1 = LoadTextureFromImage(LoadImage("assets/textures/block_1.png"));
  Texture2D block_2 = LoadTextureFromImage(LoadImage("assets/textures/block_2.png"));
  Texture2D block_3 = LoadTextureFromImage(LoadImage("assets/textures/block_3.png"));
  Texture2D block_4 = LoadTextureFromImage(LoadImage("assets/textures/block_4.png"));
  Texture2D block_5 = LoadTextureFromImage(LoadImage("assets/textures/block_5.png"));
  Texture2D block_6 = LoadTextureFromImage(LoadImage("assets/textures/block_6.png"));
  Texture2D block_7 = LoadTextureFromImage(LoadImage("assets/textures/block_7.png"));

  std::vector<Texture2D> blocks = {block_1, block_1, block_2, block_3, block_4, block_5, block_6, block_7};

  Game game = Game();

  while(WindowShouldClose() == false)
  {
    game.HandleInput();
    if (EventTriggered(0.2))
    {
      game.MoveBlockDown();
    }
    BeginDrawing();
    ClearBackground(BLACK);
    //DrawTextEx(font, "Score", {338, 15}, 38, 2, WHITE);
    //DrawTextEx(font, "Next", {348, 175}, 38, 2, WHITE);
    //DrawRectangleRounded({320, 55, 170, 60}, 0.3, 6, {59, 85, 162, 255});

    //DrawTextEx(font, scoreText, {334, 68}, 32, 2, WHITE);
    //DrawRectangleRounded({320, 215, 170, 170}, 0.2, 6, {59, 85, 162, 255});
    DrawTextureEx(grid, {39, 39}, 0, 2, BLUE);
    //DrawTextureEx(grid_2, {400, 39}, 0, 2, BLUE);


    game.Draw(blocks);
    EndDrawing();
  }

  CloseWindow();
  return 0;
}
