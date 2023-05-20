#include "raylib.h"
#include "Character.h"

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
    public:

        Grid(int width, int height,float scale, int sizePixel);
        void Tick(float t);
        void DrawGrid();
        void SetTarget(Character* character){target = character; }
        Vector2 GetScreenPos();
};
