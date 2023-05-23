#ifndef BASE_CHARACTER_H
#define BASE_CHARACTER_H
#include "raylib.h"


class BaseCharacter
{
    private:

    public:

        BaseCharacter();
        Vector2 GetWorldPos() { return worldPos; }

        void UndoMovement();
        virtual void Tick(float t);
        virtual void DrawnCollision();
        Rectangle GetCollisionRec();
        virtual Vector2 GetScreenPos() = 0;

    protected : 

        Texture2D texture = LoadTexture("textures/Basic Charakter Spritesheet.png");
        Vector2 screenPos{};
        Vector2 worldPos{};

        Vector2 worldPosLastFrame{};
        int playerDirection{0};
        int frame{};
        int maxFrame{4};
        float updateTime{1.0 / 12.0};
        float runningTime{};
        
        // 1 : facing right, -1 : facing left
        float rightLeft{1.f};

        float speed{4};
        float width{};
        float height{};
        float scale{4.0};
        Vector2 velocity{};
};

#endif