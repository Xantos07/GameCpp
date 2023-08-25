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

void Props::DrawnCollision(Vector2 characterPos)
{
    Vector2 screenPos = Vector2Subtract(worldPos, characterPos);

    DrawCircle(screenPos.x , screenPos.y, 5.0f,BLUE);  

    Vector2 A = Vector2{screenPos.x, screenPos.y};
    Vector2 B = Vector2{screenPos.x, screenPos.y + height*scale};
    Vector2 C = Vector2{screenPos.x+width*scale, screenPos.y};
    Vector2 D = Vector2{screenPos.x +width*scale, screenPos.y +height*scale};
    
    DrawLine(A.x , A.y, B.x , B.y,BLUE);  
    DrawLine(B.x , B.y, D.x , D.y,BLUE);  
    DrawLine(C.x , C.y, A.x , A.y,BLUE);  
    DrawLine(D.x , D.y, C.x , C.y,BLUE);  

}


void Props::Grow(float t, Vector2 characterPos)
{
    currentGrow = currentGrow + t;
    //std::cout << "currentGrow : " << currentGrow <<std:: endl;

    if(currentGrow > timeToGrow && endGrowing == false)
    {
        endGrowing = true;
        std::cout << "Growing : " << std:: endl;

        //prop = {pos, LoadTexture("textures/Basic Plants.png"), Vector2{1, 0}, Vector2{6, 2}};
        texture =  LoadTexture("textures/Basic Plants.png");
        textureCoordinate = Vector2{2,2};
        width = texture.width / 6;
        height = texture.height/ 2;

        Render(characterPos);
    }
}