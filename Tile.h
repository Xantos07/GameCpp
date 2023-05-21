#include "raylib.h"
#include <string>

class Tile
{   
    private:
        Vector2 coord{};
        bool isEmpty{};
    public:
        Tile(/*Vector2 coord*/);
        void SetCoord(Vector2 _coord){coord = _coord; };
        bool IsEmpty() { return isEmpty;};
        void SetTile(bool _isEmpty){isEmpty = _isEmpty; };
        void Draw(){DrawRectangle(coord.x,coord.y, 64 , 64, BLACK);};
        std::string data = "Je suis la dans les ombre!";
};