#include "Props.h"
#include "raymath.h"
#include <iostream>

Props::Props(Vector2 pos, Texture2D tex, Vector2 textureCoord, Vector2 divide) : worldPos(pos), texture(tex), textureCoordinate(textureCoord)
{
    width = texture.width / divide.x;
    height = texture.height/ divide.y;
}

void Props::Render(Vector2 characterPos)
{
     Vector2 screenPos = Vector2Subtract(worldPos, characterPos);

    Rectangle source{textureCoordinate.x * width, textureCoordinate.y * height, width, height};
    Rectangle dest{screenPos.x, screenPos.y, scale * width,scale* height};
    
    DrawTexturePro(texture, source, dest, Vector2{}, 0, WHITE);

    //DrawTextureEx(texture, screenPos,0.f, scale, WHITE);
}

Rectangle Props::GetCollisionRec(Vector2 characterPos)
{
    Vector2 screenPos = Vector2Subtract(worldPos, characterPos);

    //DrawCircle(screenPos.x , screenPos.y, 10.0f,ORANGE);
    //DrawLine(screenPos.x , screenPos.y, screenPos.x + width *scale, screenPos.y + height *scale, RED);
    return Rectangle
    {
        screenPos.x,
        screenPos.y, 
        width*scale,
        height*scale  
    };
}