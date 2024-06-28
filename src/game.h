#pragma once
#include "grid.h"
#include "blocks.cpp"

class Game
{
  public:
    Game();
    Block GetRandomBlock();
    std::vector<Block> GetAllBlocks();
    void Draw(std::vector<Texture2D> blocks);
    void MoveBlockLeft();
    void MoveBlockRight();
    void MoveBlockDown();
    void HandleInput();
    Grid grid;
    bool gameOver;
    int score;

  private:
    bool IsBlockOutside();
    void RotateBlock();
    void LockBlock();
    bool BlockFits();
    void Reset();
    void UpdateScore(int linesCleared, int moveDownPoints);
    std::vector<Block> blocks;
    Block currentBlock;
    Block nextBlock;
};