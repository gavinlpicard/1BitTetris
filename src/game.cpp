#include "game.h"
#include <iostream>

Game::Game()
{
  grid = Grid();
  blocks = GetAllBlocks();
  currentBlock = GetRandomBlock();
  nextBlock = GetRandomBlock();
  gameOver = false;
  score = 0;
}

Block Game::GetRandomBlock()
{
  if (blocks.empty())
  {
    blocks = GetAllBlocks();
  }
  int randomIndex = GetRandomValue(0, blocks.size() - 1);
  Block block = blocks[randomIndex];
  blocks.erase(blocks.begin() + randomIndex);
  return block;
}

std::vector<Block> Game::GetAllBlocks()
{
  return {IBlock(), JBlock(), LBlock(), OBlock(), SBlock(), TBlock(), ZBlock()};
}

void Game::Draw(std::vector<Texture2D> blocks)
{
  grid.Draw(blocks);
  if (!gameOver) currentBlock.Draw(blocks, 39, 39, 17);
  switch (nextBlock.id)
  {
    case 3:
    nextBlock.Draw(blocks, 364, 172, 16);
    break;
    case 4:
    nextBlock.Draw(blocks, 364, 140, 16);
    break;
    default:
    nextBlock.Draw(blocks, 380, 140, 16);
    break;
  }
}

void Game::HandleInput()
{
  int keyPressed = GetKeyPressed();
  if (gameOver && keyPressed != 0)
  {
    gameOver = false;
    Reset();
  }
  switch (keyPressed)
  {
    case KEY_LEFT:
    case KEY_A:
    MoveBlockLeft();
    break;
    case KEY_RIGHT:
    case KEY_D:
    MoveBlockRight();
    break;
    case KEY_DOWN:
    case KEY_S:
    UpdateScore(0, 1);
    MoveBlockDown();
    break;
    case KEY_UP:
    case KEY_W:
    case KEY_SPACE:
    case KEY_R:
    RotateBlock();
    break;
  }
}

void Game::MoveBlockLeft()
{
  if (!gameOver)
  {
    currentBlock.Move(0, -1);
    if (IsBlockOutside() || BlockFits() == false)
    {
      currentBlock.Move(0, 1);
    }
  }
}

void Game::MoveBlockRight()
{
  if (!gameOver)
  {
    currentBlock.Move(0, 1);
    if (IsBlockOutside() || BlockFits() == false)
    {
      currentBlock.Move(0, -1);
    }
  }
}

void Game::MoveBlockDown()
{
  if (!gameOver)
  {
    currentBlock.Move(1, 0);
    if (IsBlockOutside() || BlockFits() == false)
    {
      currentBlock.Move(-1, 0);
      LockBlock();
    }
  }
}

bool Game::IsBlockOutside()
{
  std::vector<Position> tiles = currentBlock.GetCellPositions();
  for (Position item : tiles)
  {
    if (grid.IsCellOutside(item.row, item.col)) return true;
  }
  return false;
}

void Game::RotateBlock()
{
  currentBlock.Rotate();
  if (IsBlockOutside() || BlockFits() == false)
  {
    currentBlock.UndoRotation();
  }
}

void Game::LockBlock()
{
  std::vector<Position> tiles = currentBlock.GetCellPositions();
  for (Position item : tiles)
  {
    grid.grid[item.row][item.col] = currentBlock.id;
  }
  currentBlock = nextBlock;
  if (BlockFits() == false)
  {
    gameOver = true;
  }
  nextBlock = GetRandomBlock();
  int rowsCleared = grid.ClearFullRows();
  UpdateScore(rowsCleared, 0);
}

bool Game::BlockFits()
{
  std::vector<Position> tiles = currentBlock.GetCellPositions();
  for (Position item : tiles)
  {
    if (grid.IsCellEmpty(item.row, item.col) == false)
    {
      return false;
    }
  }
  return true;
}

void Game::Reset()
{
  grid.Initialize();
  blocks = GetAllBlocks();
  currentBlock = GetRandomBlock();
  nextBlock = GetRandomBlock();
  score = 0;
}

void Game::UpdateScore(int linesCleared, int moveDownPoints)
{
  switch(linesCleared)
  {
    case 1:
    score += 100;
    break;
    case 2:
    score += 300;
    break;
    case 3:
    score += 500;
    default:
    break;
  }
  score += moveDownPoints;
}
