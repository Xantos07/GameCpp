#ifndef Props_H
#define Props_H

#include "raylib.h"

class Props
{   
    private:
        Texture2D texture{};
        Vector2 worldPos{};
        Vector2 textureCoordinate {};

        float scale{4.0};

        float width{};
        float height{};

        float timeToGrow = 3.0f;
        float currentGrow = 0.0f;

        bool endGrowing = false;

    public:

        Props(Vector2 pos,Texture2D texture, Vector2 textureCoord,  Vector2 divide);
        Vector2 GetWorldPos() { return worldPos; }
        Rectangle GetCollisionRec(Vector2 characterPos);
        void Render(Vector2 characterPos); 
        void DrawnCollision(Vector2 characterPos);
        void Grow(float t, Vector2 characterPos);

};
#endif