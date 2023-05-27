#include "Tile.h"
#include "raymath.h"
#include <iostream>

Tile::Tile() //(Vector2 coord) : Coord(coord)
{
}

void Tile::Render(Vector2 characterPos, Vector2 pos)
{
    if (!isEmpty)
    {
        Vector2 screenPos = Vector2Subtract(worldPos, characterPos);
        /*
            Rectangle source{3 * width, 0 * height, width, height};
            Rectangle dest{screenPos.x, screenPos.y, 64 , 64};
            DrawTexturePro(texture, source, dest, Vector2{}, 0, WHITE);
        */
        prop = {pos, LoadTexture("textures/Basic Plants.png"), Vector2{4, 0}, Vector2{6, 2}};
        prop.Render(characterPos);
        // DrawTextureEx(texture, screenPos,0.f, scale, WHITE);
    }
}

Rectangle Tile::GetCollisionRec(Vector2 characterPos)
{
    Vector2 screenPos = Vector2Subtract(worldPos, characterPos);

    // DrawCircle(screenPos.x , screenPos.y, 10.0f,ORANGE);
    // DrawLine(screenPos.x , screenPos.y, screenPos.x + width *scale, screenPos.y + height *scale, RED);
    return Rectangle{
        screenPos.x,
        screenPos.y,
        64,
        64};
}