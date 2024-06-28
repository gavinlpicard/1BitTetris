#include "colors.h"
#include <vector>

const Color darkGray = {25, 31, 40, 255};
const Color green = {47, 230, 23, 255};
const Color red = {232, 18, 18, 255};
const Color orange = {236, 116, 17, 255};
const Color yellow = {237, 234, 4, 255};
const Color purple = {166, 0, 247, 255};
const Color cyan = {21, 204, 209, 255};
const Color blue = {13, 64, 216, 255};

std::vector<Color> GetCellColors()
{
  return {darkGray, green, red, orange, yellow, purple, cyan, blue};
}

std::vector<Texture2D> GetBlockTextures()
{
  Texture2D block_1 = LoadTextureFromImage(LoadImage("assets/textures/block_1.png"));
  return {block_1, block_1};
}