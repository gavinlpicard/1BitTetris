#include "block.h"
#include <iostream>

Block::Block()
{
  cellSize = 32;
  rotationState = 0;
  blocks = GetBlockTextures();
  rowOffset = 0;
  colOffset = 0;
  std::cout << "test" << std::endl;
}

void Block::Draw(std::vector<Texture2D> blocks, int offsetX, int offsetY, int size)
{
  std::vector<Position> tiles = GetCellPositions();
  for (Position item : tiles)
  {
    DrawTexturePro(blocks[id], {0, 0, (float) size, (float) size}, {0, 0, (float) size * 2, (float) size * 2}, {(float) -1 * item.col * cellSize - offsetX, (float) -1 * item.row * cellSize - offsetY}, 0, BLUE);
  }
}

void Block::Move(int rows, int cols)
{
  rowOffset += rows;
  colOffset += cols;
}

std::vector<Position> Block::GetCellPositions()
{
  std::vector<Position> tiles = cells[rotationState];
  std::vector<Position> movedTiles;
  for (Position item : tiles)
  {
    Position newPos = Position(item.row + rowOffset, item.col + colOffset);
    movedTiles.push_back(newPos);
  }
  return movedTiles;
}

void Block::Rotate()
{
  rotationState++;
  if (rotationState >= (int) cells.size()) rotationState = 0;
}

void Block::UndoRotation()
{
  rotationState--;
  if (rotationState < 0) rotationState = cells.size() - 1;
}
