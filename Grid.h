#include "raylib.h"
#include "Character.h"
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
        Character* target;
        
        std::vector<std::vector<Tile>> tableau;

    public:

        Grid(int width, int height,float scale, int sizePixel);
        void Tick(float t);
        void DrawGrid();
        void SetTarget(Character* character){target = character; }

        Vector2 GetScreenPos();
};
