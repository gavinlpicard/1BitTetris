#include "grid.h"
#include "colors.h"
#include <iostream>

Grid::Grid()
{
  numRows = 20;
  numCols = 10;
  cellSize = 32;
  Initialize();
  colors = GetCellColors();
}

void Grid::Initialize()
{
  int row, col;
  for (row = 0; row < numRows; row++)
  {
    for (col = 0; col < numCols; col++)
    {
      grid[row][col] = 0;
    }
  }
}

void Grid::Print()
{
  int row, col;
  for (row = 0; row < numRows; row++)
  {
    for (col = 0; col < numCols; col++)
    {
      std::cout << grid[row][col] << " ";
    }
    std::cout << std::endl;
  }
}

void Grid::Draw(std::vector<Texture2D> blocks)
{
  int row, col, cellValue;
  for (row = 0; row < numRows; row++)
  {
    for (col = 0; col < numCols; col++)
    {
      cellValue = grid[row][col];

      if (cellValue > 0) DrawTextureEx(blocks[cellValue], {(float) (col * cellSize + 39), (float) (row * cellSize + 39)}, 0, 2, BLUE);
      //DrawRectangle(col * cellSize + 11, row * cellSize + 11, cellSize - 1, cellSize - 1, colors[cellValue]);
    }
  }
}

bool Grid::IsCellOutside(int row, int col)
{
  if (row >= 0 && row < numRows && col >= 0 && col < numCols) return false;
  return true;
}

bool Grid::IsCellEmpty(int row, int col)
{
  if (grid[row][col] == 0)
  {
    return true;
  }
  return false;
}

int Grid::ClearFullRows()
{
  int completed = 0;
  for (int row = numRows - 1; row >= 0; row--)
  {
    if (IsRowFull(row))
    {
      ClearRow(row);
      completed++;
    }
    else if (completed > 0)
    {
      MoveRowDown(row, completed);
    }
  }
  return completed;
}

bool Grid::IsRowFull(int row)
{
  for (int col = 0; col < numCols; col++)
  {
    if (grid[row][col] == 0)
    {
      return false;
    }
  }
  return true;
}

void Grid::ClearRow(int row)
{
  for (int col = 0; col < numCols; col++)
  {
    grid[row][col] = 0;
  }
}

void Grid::MoveRowDown(int row, int numRows)
{
  for (int col = 0; col < numCols; col++)
  {
    grid[row + numRows][col] = grid[row][col];
    grid[row][col] = 0;
  }
}
