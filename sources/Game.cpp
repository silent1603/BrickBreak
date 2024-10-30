#include "Game.h"
#include "GameState/GS_MainMenu.h"
#include "Logger.h"
#include "raylib.h"
#include "rapidjson/rapidjson.h"
#include "rapidjson/filereadstream.h"
#include "rapidjson/document.h"
#include "GlobalVariables.h"
Game::Game()
    : m_running(false)
{
}

Game::~Game()
{
}

void Game::Init()
{
    m_running = true;
    LoadGameConfig();
    InitWindow(gameConfigInfo.width,gameConfigInfo.height,gameConfigInfo.app_name.c_str());
    SetTargetFPS(60);
    SetWindowTitle("brickbreak");
    Image icon = LoadImage("resources/images/ground.png");
    SetWindowIcon(icon); 
    std::shared_ptr<GameState> currentState = std::make_unique<GS_MainMenu>(0);
    gameManagerInfo.stateManager = std::make_unique<GameStateManager>(4);
    gameManagerInfo.stateManager->PushState(currentState, true);
}

void Game::CleanUp()
{
    CloseWindow();
}

void Game::Update(float fElapsedTime)
{
    if (gameManagerInfo.stateManager->PeekState() != nullptr)
    {
        gameManagerInfo.stateManager->Update(fElapsedTime);
    }
}

void Game::HandleEvents()
{
    if (WindowShouldClose())
    {
        Quit();
    }

    if (auto state = gameManagerInfo.stateManager->PeekState())
    {
        state->ProcessInputState();
    }
    
}

void Game::Draw()
{
    BeginDrawing();
    ClearBackground(RAYWHITE);
    if (auto state = gameManagerInfo.stateManager->PeekState())
    {
        state->RenderState();
    }
    EndDrawing();
}

void Game::LoadGameConfig()
{
    GameConfig config;
    
    config.asset_path = "resources";
    config.app_name = "Game Demo";
    config.height = 1260;
    config.width = 720;
    FILE* fp = fopen("resources/config.json", "rb");        // Read the file into a buffer 
    char readBuffer[65536]; 
    rapidjson::FileReadStream is(fp, readBuffer, 
                                 sizeof(readBuffer)); 
  
    // Parse the JSON document 
    rapidjson::Document doc; 
    doc.ParseStream(is); 
    if(!doc.HasParseError())
    {
      if(doc.HasMember("window_height") && doc["window_height"].IsInt())
      {
            config.height = doc["window_height"].GetInt();
      }
      if(doc.HasMember("window_width") && doc["window_width"].IsInt())
      {
            config.width = doc["window_width"].GetInt();
      }
    }
    fclose(fp);
    gameConfigInfo = config;
}