#ifndef CHARACTER_H
#define CHARACTER_H

//#pragma once

#include "raylib.h"
#include "BaseCharacter.h"


class Grid;

class Character : public BaseCharacter
{
    private:

        int windowWidth{};
        int windowHeight{};
        Texture2D hue {LoadTexture("textures/Tools.png")};
        Vector2 posGrid;
        Grid* grid;

    public:
        
        Character(int winWidth, int winHeight);
        virtual void Tick(float deltaTime) override;
        virtual void DrawnCollision() override;
        virtual Vector2 GetScreenPos() override;
        void SetPosGrid(Vector2 _posGrid) {posGrid = _posGrid;};

        void SetGrid(Grid* _grid){grid = _grid; }
};

#endif