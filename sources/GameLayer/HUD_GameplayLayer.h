#ifndef GUI_GAMEPLAYLAYER
#define GUI_GAMEPLAYLAYER
#include <vector>
#include <memory>
#include "GameStateLayer.h"
#include "raylib.h"


class GUI_GameplayLayer : public GameStateLayer 
{
public:
    GUI_GameplayLayer(uint16_t id, bool enabled = true);
    virtual ~GUI_GameplayLayer();

    virtual bool Setup() override;
    virtual bool Update(float fElapsedTime) override;
    virtual bool Render() override;

private:
    std::shared_ptr<GameData>
    std::vector<Vector2> entityPosition;
    std::vector<Vector2> entitySpeed;
    std::vector<bool> entityActive;
};
#endif