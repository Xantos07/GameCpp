#include "Enemy.h"
#include "raymath.h"
/*Enemy::Enemy(Vector2 pos, Texture2D tex) : worldPos(pos), texture(tex){}*/

Enemy::Enemy(Vector2 pos, Texture2D tex) 
{
    worldPos=pos; 
    texture=tex;

    width = texture.width / maxFrame;
    height = texture.height / maxFrame;

    speed = 3.5f;
}

void Enemy::Tick(float t)
{   
    //get toTarget
    velocity = Vector2Subtract(target -> GetScreenPos(), GetScreenPos());

    BaseCharacter::Tick(t);
    BaseCharacter::DrawnCollision();
}

void Enemy::DrawnCollision()
{
    BaseCharacter::DrawnCollision();
}

Vector2 Enemy::GetScreenPos()
{
    return Vector2Subtract(worldPos, target -> GetWorldPos());
}