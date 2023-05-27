#include "raylib.h"
#include <string>
#include "Props.h"

class Tile
{   
    private:
        Vector2 coord{};        
        Vector2 worldPos{};
        bool isEmpty{true};
        bool update{false};
        Props prop = {Vector2{0.0f,0.0f},LoadTexture("textures/Basic Plants.png"),  Vector2{4,0}, Vector2{6,2}};
    public:
        Tile(/*Vector2 coord*/);
        void SetCoord(Vector2 _coord){coord = _coord; };
        bool IsEmpty() { return isEmpty;};
        void SetProps(Props _prop) {prop=_prop; };
        void SetWorldPos(Vector2 _worldPos){worldPos = _worldPos; };
        Vector2 GetWorldPos() { return worldPos;};

        void Render(Vector2 characterPos, Vector2 pos);

        void SetTile(bool _isEmpty){isEmpty = _isEmpty; };

};