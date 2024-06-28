#pragma once
#include "position.h"
#include "colors.h"
#include <vector>
#include <map>

class Block
{
  public:
    Block();
    void Draw(std::vector<Texture2D> blocks, int offsetX, int offsetY, int size);
    void Move(int rows, int cols);
    std::vector<Position> GetCellPositions();
    void Rotate();
    void UndoRotation();
    int id;
    std::map<int, std::vector<Position>> cells;

  private:
    int cellSize;
    int rotationState;
    std::vector<Color> colors;
    std::vector<Texture2D> blocks;
    int rowOffset;
    int colOffset;
};