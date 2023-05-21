#ifndef CHARACTER_H
#define CHARACTER_H

#include "raylib.h"
#include "BaseCharacter.h"

class Character : public BaseCharacter
{
    private:
        int windowWidth{};
        int windowHeight{};
        Texture2D hue {LoadTexture("textures/Tools.png")};

    public:
        
        Character(int winWidth, int winHeight);
        virtual void Tick(float deltaTime) override;
        virtual void DrawnCollision() override;
        virtual Vector2 GetScreenPos() override;
};

#endif