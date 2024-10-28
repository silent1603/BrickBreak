#ifndef GLOBAL_VALRIABLES
#define GLOBAL_VALRIABLES
#include <string>
struct GameConfigInfo
{
    std::string asset_path;
    uint16_t width;
    uint16_t height;
    std::string app_name;
};

GameConfigInfo gameConfigInfo; 
#endif