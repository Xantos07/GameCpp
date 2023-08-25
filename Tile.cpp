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
        if(!update)
        {        
            update= true;

            prop = {pos, LoadTexture("textures/Basic Plants.png"), Vector2{1, 0}, Vector2{6, 2}};
        }

        prop.Render(characterPos);

        // DrawTextureEx(texture, screenPos,0.f, scale, WHITE);
    }
}

void Tile:: UpdateTile(Vector2 playerPos)
 { 
    if (!isEmpty)
    {
      prop.Grow(GetFrameTime(), playerPos);
    }
}