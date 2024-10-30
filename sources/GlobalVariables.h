#ifndef GLOBAL_VARIABLES
#define GLOBAL_VARIABLES
#include <string>
#include "GameStateManager.h"
struct GameConfig
{
    std::string asset_path;
    uint16_t width;
    uint16_t height;
    std::string app_name;
};

struct GameManager
{
    std::unique_ptr<GameStateManager> stateManager;
};

extern GameConfig gameConfigInfo;
extern GameManager gameManagerInfo;
#endif