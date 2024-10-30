#ifndef GUI_MAINMENULAYER
#define GUI_MAINMENULAYER
#include "GameStateLayer.h"
#include "raylib.h"


class GUI_MainMenuLayer : public GameStateLayer 
{
public:
    GUI_MainMenuLayer(uint16_t id, bool enabled = true);
    virtual ~GUI_MainMenuLayer();

    virtual bool Setup() override;
    virtual bool Update(float fElapsedTime) override;
    virtual bool Render() override;

private:
    // Button positions
    Rectangle m_startButtonRect;
    Rectangle m_settingsButtonRect;
    Rectangle m_exitButtonRect;

    bool m_redirectToGamePlay;
    bool m_redirectToSettings;
};
#endif