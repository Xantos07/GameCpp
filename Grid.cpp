#include "Grid.h"
#include "raymath.h"
#include <iostream>
#include <vector>


Grid::Grid(int winWidth, int winHeight,float scaleMap, int sizePixel) :
 windowWidth(winWidth),  windowHeight(winHeight), windowPixel(sizePixel), scale(scaleMap)
{  
    windowWidth = (windowWidth / windowPixel) * scale;
    windowHeight = (windowHeight / windowPixel) * scale;    
  
    int x = (windowWidth/64) * scale;
    int y = (windowHeight/64) * scale;

    tableau.resize(windowWidth);

    for (auto& x : tableau) 
    {
        x.resize(y, Tile());
    }
    // Peu causer une latence
    for (int i = 0; i < x; i++) 
    {
        for (int j = 0; j < y; j++) 
        {            
            tableau[i][j] = Tile();            
            tableau[i][j].SetCoord(Vector2{i*64.f,j*64.f});
            tableau[i][j].SetWorldPos(Vector2{i*64.f + worldPos.x,j*64.f+ worldPos.y});
        }
    }
    
}

void Grid::Tick(float t,Vector2 playPos)
{
    //DrawText(tableau[0][0].data.c_str(), 0, 0, 15, RED);

    /*
    Vector2 test = Vector2Subtract(target -> GetWorldPos(), worldPos);

    int score = test.x / 64;
    int score2 = test.y / 64; 

    tableau[score][score2].SetTile(false);
      

    DrawRectangle(player->GetScreenPos().x + 64,player->GetScreenPos().y, 64 , 64, BLACK);
    DrawRectangle(player->GetScreenPos().x ,player->GetScreenPos().y+ 64, 64 , 64, BLACK);
    DrawRectangle(player->GetScreenPos().x - 64,player->GetScreenPos().y, 64 , 64, BLACK);
    DrawRectangle(player->GetScreenPos().x,player->GetScreenPos().y- 64, 64 , 64, BLACK);
    */  

    int x = (windowWidth/64) * scale;
    int y = (windowHeight/64) * scale;

    for (int i = 0; i < x; i++) 
    {
        for (int j = 0; j < y; j++) 
        {       
            tableau[i][j].SetWorldPos(Vector2Scale(playPos, -1.0f));
            tableau[i][j].Render(playPos, Vector2{i*x*2,j*y*2});
        }
    }

}

void Grid::DrawGrid()
{
    for (int x = 0; x < windowWidth; x++)
    {
        DrawLine(worldPos.x + x * windowPixel * scale,
        worldPos.y + windowPixel * scale, 
        worldPos.x + x * windowPixel * scale, 
        worldPos.y + windowPixel * scale * windowHeight, PINK);

        DrawLine(worldPos.x + windowPixel * scale,
        worldPos.y + x * windowPixel * scale, 
        worldPos.x * windowPixel * scale * -windowWidth, 
        worldPos.y + x * windowPixel * scale, PINK);
    }

    //DrawRectangleLines(GetScreenPos().x + x * windowPixel * scale, GetScreenPos().y + y * windowPixel * scale, windowWidth, windowHeight, PINK);
}
