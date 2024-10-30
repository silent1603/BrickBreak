#include "GUI_MainMenuLayer.h"
#include "raylib.h"

#define RAYGUI_IMPLEMENTATION
#include "GlobalVariables.h"
#include "raygui.h"

#include "GameState/GS_Gameplay.h"
#include "GameState/GS_Setting.h"

GUI_MainMenuLayer::GUI_MainMenuLayer(uint16_t id, bool enabled)
    : GameStateLayer(id, enabled), m_redirectToGamePlay(false),
      m_redirectToSettings(false)
{
}

GUI_MainMenuLayer::~GUI_MainMenuLayer()

{
}

bool GUI_MainMenuLayer::Setup()
{
    float buttonWidth = 200.0f;
    float buttonHeight = 50.0f;

    float centerX = (GetScreenWidth()) / 2 - buttonWidth / 2;
    float centerY = (GetScreenHeight()) / 2;
    m_startButtonRect = {centerX, 200.0f, buttonWidth, buttonHeight};
    m_settingsButtonRect = {centerX, 300.0f, buttonWidth, buttonHeight};
    m_exitButtonRect = {centerX, 400.0f, buttonWidth, buttonHeight};

    return true;
}

bool GUI_MainMenuLayer::Update(float fElapsedTime)
{

        if(m_redirectToGamePlay)
        {
            m_redirectToGamePlay = false;
            gameManagerInfo.stateManager->PushState(std::make_unique<GS_Gameplay>(1));
        }

        if(m_redirectToSettings)
        {
            m_redirectToGamePlay = false;
            gameManagerInfo.stateManager->PushState(std::make_unique<GS_Setting>(1));
        }

    return true;
}

bool GUI_MainMenuLayer::Render()
{

        if (GuiButton(m_startButtonRect, "Start Game"))
        {
            m_redirectToGamePlay = true;
        }
        if (GuiButton(m_settingsButtonRect, "Settings"))
        {
            m_redirectToSettings = true;
        }

    return true;
}
