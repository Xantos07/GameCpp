#include "Character.h"
#include "raymath.h"

Character::Character(int winWidth, int winHeight) : windowWidth(winWidth),  windowHeight(winHeight)
{
    width = texture.width / maxFrame;
    height = texture.height/ maxFrame;

        screenPos = {static_cast<float>(winWidth) / 2.0f - scale * (0.5f * (float)width),
                 static_cast<float>(winHeight) / 2.0f - scale * (0.5f * (float)height)
    };
}

Vector2 Character::GetScreenPos()
{
    return Vector2{static_cast<float>(windowWidth) / 2.0f - scale * (0.5f * (float)width),
                 static_cast<float>(windowHeight) / 2.0f - scale * (0.5f * (float)height)
    };
}

void Character::Tick(float t)
{
    Vector2 origin{};
    Vector2 offSet{};
    Vector2 spriteVec{0,1};
    if (IsKeyDown(KEY_A))
    {        
        velocity.x += -1;
        origin = {0.f, hue.height/6 * scale};
        offSet = {-20.f, 5.f};
    }
    if (IsKeyDown(KEY_D))
    {       
         velocity.x += 1;
         origin = {hue.width/6 * scale, hue.height/6 * scale};
         offSet = {20.f, 5.f};
    }
    if (IsKeyDown(KEY_W))
    {       
         velocity.y += -1;
    }
    if (IsKeyDown(KEY_S))
    {        
         velocity.y += 1;
    }

    if (IsMouseButtonDown(MOUSE_BUTTON_LEFT))
    {
        spriteVec.x = 1;
    }
    

    BaseCharacter::Tick(t);

    //draw 
    Rectangle source{spriteVec.x * width, spriteVec.y * height, static_cast<float>(hue.width/6) * rightLeft,  static_cast<float>(hue.height/6)};
    Rectangle dest{GetScreenPos().x + offSet.x, GetScreenPos().y + offSet.y, hue.width/6 * scale, hue.height/6 * scale};
    DrawTexturePro(hue,source,dest, {}, 0.f, WHITE);

    DrawRectangleLines(GetScreenPos().x + offSet.x, GetScreenPos().y + offSet.y, hue.width/6 * scale, hue.height/6 * scale, PURPLE);
}

void  Character::DrawnCollision()
{
    BaseCharacter::DrawnCollision();
}