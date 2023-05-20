#include "BaseCharacter.h"
#include "raymath.h"

BaseCharacter::BaseCharacter()
{

}

// using scope resolution operator :: when there is a local
void BaseCharacter::UndoMovement()
{
  worldPos = worldPosLastFrame;
}

Rectangle BaseCharacter::GetCollisionRec()
{
    return Rectangle
    {
        GetScreenPos().x,
        GetScreenPos().y,
        width*scale,
        height*scale 
    };
}

void BaseCharacter::DrawnCollision()
{
    DrawCircle(GetScreenPos().x , GetScreenPos().y, 5.0f,RED);  

    Vector2 A = Vector2{GetScreenPos().x, GetScreenPos().y};
    Vector2 B = Vector2{GetScreenPos().x, GetScreenPos().y + height*scale};
    Vector2 C = Vector2{GetScreenPos().x+width*scale, GetScreenPos().y};
    Vector2 D = Vector2{GetScreenPos().x +width*scale, GetScreenPos().y +height*scale};
    
    DrawLine(A.x , A.y, B.x , B.y,RED);  
    DrawLine(B.x , B.y, D.x , D.y,RED);  
    DrawLine(C.x , C.y, A.x , A.y,RED);  
    DrawLine(D.x , D.y, C.x , C.y,RED);  
}

void BaseCharacter::Tick(float t)
{
    worldPosLastFrame = worldPos;

    // update running time
    runningTime += t;

    if (runningTime >= updateTime)
    {
        runningTime = 0.0;
        // update animation frame
        frame++;

        if (frame > maxFrame)
            frame = 0;
    }
    
    if (Vector2Length(velocity) != 0.0)
    {
        worldPos = Vector2Add(worldPos, Vector2Scale(Vector2Normalize(velocity), speed));
        velocity.x > 0.f ? rightLeft = -1.f : rightLeft = 1.f;
        // direction.x < 0 ? playerDirection = 2 : playerDirection = 3;

        if (velocity.x < 0)
            playerDirection = 2; 
        else if (velocity.x > 0)       
            playerDirection = 3;
        else if (velocity.y < 0)       
            playerDirection = 1;      
        else if (velocity.y > 0)
            playerDirection = 0;
    }
    
    velocity = {};    
    
    Rectangle source{frame * width, playerDirection * height, width, height};
    Rectangle dest{GetScreenPos().x, GetScreenPos().y, scale * width, scale * height};

    DrawTexturePro(texture, source, dest, Vector2{}, 0, WHITE);
}