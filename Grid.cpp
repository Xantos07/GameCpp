#include "Grid.h"
#include "raymath.h"
#include <iostream>
#include <vector>


Grid::Grid(int winWidth, int winHeight,float scaleMap, int sizePixel) :
 windowWidth(winWidth),  windowHeight(winHeight), windowPixel(sizePixel), scale(scaleMap)
{ 
    windowWidth = (windowWidth / windowPixel) * scale;
    windowHeight = (windowHeight / windowPixel) * scale;    

    tableau.resize(windowWidth);
    for (auto& windowWidth : tableau) 
    {
        windowWidth.resize(windowHeight, Tile());
    }
}

Vector2 Grid::GetScreenPos()
{
    return Vector2Subtract(worldPos, target -> GetWorldPos());
}

void Grid::Tick(float t)
{
    //DrawText(tableau[0][0].data.c_str(), 0, 0, 15, RED);

    std::string boolString = (tableau[0][0].IsEmpty()) ? "true" : "false";
    DrawText(boolString.c_str(), 0, 0, 15, RED);

    std::string boolString2 = (tableau[1][0].IsEmpty()) ? "true" : "false";
    DrawText(boolString2.c_str(), 0, 100, 15, RED);

    tableau[0][0].SetTile(true);
}

void Grid::DrawGrid()
{
    for (int x = 0; x < windowWidth; x++)
    {
        DrawLine(GetScreenPos().x + x * windowPixel * scale,
        GetScreenPos().y + windowPixel * scale, 
        GetScreenPos().x + x * windowPixel * scale, 
        GetScreenPos().y + windowPixel * scale * windowHeight, PINK);

        DrawLine(GetScreenPos().x + windowPixel * scale,
        GetScreenPos().y + x * windowPixel * scale, 
        GetScreenPos().x * windowPixel * scale * -windowWidth, 
        GetScreenPos().y + x * windowPixel * scale, PINK);
    }

    //DrawRectangleLines(GetScreenPos().x + x * windowPixel * scale, GetScreenPos().y + y * windowPixel * scale, windowWidth, windowHeight, PINK);
}
