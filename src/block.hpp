#pragma once
#include "position.hpp"
#include "textures.hpp"
#include <vector>
#include <map>

class Block
{
  public:
    Block();
    void Draw(int offsetX, int offsetY, int size);
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
    std::vector<Texture2D> textures;
    int rowOffset;
    int colOffset;
};