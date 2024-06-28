#pragma once
#include "raylib.h"
#include <vector>

class Grid
{
  public:
    Grid();
    void Initialize();
    void Print();
    void Draw(std::vector<Texture2D> blocks);
    bool IsCellOutside(int row, int col);
    bool IsCellEmpty(int row, int col);
    int ClearFullRows();
    int grid[20][10];

  private:
    bool IsRowFull(int row);
    void ClearRow(int row);
    void MoveRowDown(int row, int numRows);
    int numRows;
    int numCols;
    int cellSize;
    std::vector<Color> colors;
};