#include "Grid.h"
#include "raymath.h"

Grid::Grid(int winWidth, int winHeight,float scaleMap, int sizePixel) :
 windowWidth(winWidth),  windowHeight(winHeight), windowPixel(sizePixel), scale(scaleMap)
{
    windowWidth = (windowWidth / windowPixel) * scale;
    windowHeight = (windowHeight / windowPixel) * scale;
}

Vector2 Grid::GetScreenPos()
{
    return Vector2Subtract(worldPos, target -> GetWorldPos());
}

void Grid::Tick(float t)
{

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
