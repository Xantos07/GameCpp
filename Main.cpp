#include "raylib.h"
#include "raymath.h"
#include "Props.h"

#include "Grid.h"
#include "BaseCharacter.h"
#include "Character.h"
#include "Enemy.h"

int main()
{
    const int width = 1000;
    const int height = 1000;

    InitWindow(width, height, "RPG !");

    // map variables
    Texture2D Map = LoadTexture("textures/Map.png");
    Rectangle mapRec;
    Vector2 mapPos{0.0, 0.0};

    float mapScale{8};

    
    Character player{width, height};

    Grid grid{Map.width, Map.height,mapScale , 8};

    //Enemy Enemy{Vector2{450.0f,780.0f}, LoadTexture("textures/Basic Charakter Spritesheet.png")};

    Props props[17]{
        Props{Vector2{250.0f,480.0f},LoadTexture("textures/Basic Plants.png"),  Vector2{0,0}, Vector2{6,2}},

        //64 => tile = 8 / map => *8
        Props{Vector2{768.0f,576.0f},LoadTexture("textures/Basic Plants.png"),  Vector2{4,0}, Vector2{6,2}},
        Props{Vector2{768.0f,640.0f},LoadTexture("textures/Basic Plants.png"),  Vector2{4,0}, Vector2{6,2}},
        Props{Vector2{768.0f,704.0f},LoadTexture("textures/Basic Plants.png"),  Vector2{4,0}, Vector2{6,2}},
        Props{Vector2{768.0f,768.0f},LoadTexture("textures/Basic Plants.png"),  Vector2{4,0}, Vector2{6,2}},

        Props{Vector2{832.0f,576.0f},LoadTexture("textures/Basic Plants.png"),  Vector2{4,0}, Vector2{6,2}},
        Props{Vector2{832.0f,640.0f},LoadTexture("textures/Basic Plants.png"),  Vector2{4,0}, Vector2{6,2}},
        Props{Vector2{832.0f,704.0f},LoadTexture("textures/Basic Plants.png"),  Vector2{4,0}, Vector2{6,2}},
        Props{Vector2{832.0f,768.0f},LoadTexture("textures/Basic Plants.png"),  Vector2{4,0}, Vector2{6,2}},

        Props{Vector2{896.0f,576.0f},LoadTexture("textures/Basic Plants.png"),  Vector2{4,0}, Vector2{6,2}},
        Props{Vector2{896.0f,640.0f},LoadTexture("textures/Basic Plants.png"),  Vector2{4,0}, Vector2{6,2}},
        Props{Vector2{896.0f,704.0f},LoadTexture("textures/Basic Plants.png"),  Vector2{4,0}, Vector2{6,2}},
        Props{Vector2{896.0f,768.0f},LoadTexture("textures/Basic Plants.png"),  Vector2{4,0}, Vector2{6,2}},

        Props{Vector2{960.0f,576.0f},LoadTexture("textures/Basic Plants.png"),  Vector2{4,0}, Vector2{6,2}},
        Props{Vector2{960.0f,640.0f},LoadTexture("textures/Basic Plants.png"),  Vector2{4,0}, Vector2{6,2}},
        Props{Vector2{960.0f,704.0f},LoadTexture("textures/Basic Plants.png"),  Vector2{4,0}, Vector2{6,2}},
        Props{Vector2{960.0f,768.0f},LoadTexture("textures/Basic Plants.png"),  Vector2{4,0}, Vector2{6,2}},
    };

    //Enemy.SetTarget(&player);
    grid.SetTarget(&player);

    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        BeginDrawing();

        ClearBackground(BLACK);

        mapPos = Vector2Scale(player.GetWorldPos(), -1.0f);
        DrawTextureEx(Map, mapPos, 0, mapScale, WHITE);
        //DrawText(TextFormat("Actuellement en : %i   /--------/   %i", dieu.GetWorldPos().x, dieu.GetWorldPos().y), 0, 0, 15, RED);

       for (auto prop : props)
       {    
            prop.Render(player.GetWorldPos());
            prop.DrawnCollision(player.GetWorldPos());
       }

        if(player.GetWorldPos().x < 0 || 
        player.GetWorldPos().y < 0 ||
        player.GetWorldPos().x + width > Map.width *mapScale ||
        player.GetWorldPos().y + height > Map.height *mapScale)
        {
           player.UndoMovement();      
        }
        
        for (auto prop : props)
        {
            if (CheckCollisionRecs(prop.GetCollisionRec(player.GetWorldPos()), player.GetCollisionRec()))
            {
                    player.UndoMovement();
            }
        } 
        
        player.Tick(GetFrameTime());
        //Enemy.Tick(GetFrameTime());
        grid.Tick(GetFrameTime());
        
        player.DrawnCollision();
        //Enemy.DrawnCollision();
        grid.DrawGrid();

        EndDrawing();
    }

    CloseWindow();
}