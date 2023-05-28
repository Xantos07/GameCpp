#ifndef GRID_H
#define GRID_H

#include "raylib.h"
#include "Tile.h"
#include <vector>

class Grid
{
    
    private:
        int windowWidth{};
        int windowHeight{};
        int windowPixel{};
        float scale{};
        Vector2 worldPos{};
        Vector2 screenPos{};
        //Character* player;

         std::vector<std::vector<Tile>> tableau;
        //std::vector<std::vector<Tile>> tableau;

    public:

        Grid(int width, int height,float scale, int sizePixel);
        void Tick(float t, Vector2 playPos);
        void DrawGrid();
        void SetWorldPos(Vector2 _pos) {worldPos = _pos;};
        void SetBoard(std::vector<std::vector<Tile>> _tableau) {tableau = _tableau;};
        //void SetTarget(Character* _player){player = _player; }
Vector2 GetWorldPos(){return worldPos;}
        std::vector<std::vector<Tile>> GetGrid(){return tableau;}

        Vector2 GetScreenPos();
};

#endif