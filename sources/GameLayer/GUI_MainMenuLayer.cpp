#include "GUI_MainMenuLayer.h"
#include "raylib.h"

#define RAYGUI_IMPLEMENTATION
#include "raygui.h"
#include "GlobalVariables.h"

GUI_MainMenuLayer::GUI_MainMenuLayer(uint16_t id,  bool enabled)
    : GameStateLayer(id, enabled)
{
}

GUI_MainMenuLayer::~GUI_MainMenuLayer()

{
}


bool GUI_MainMenuLayer::Setup()
{
    float buttonWidth = 200.0f;
    float buttonHeight = 50.0f;

    float centerX = (GetScreenWidth() ) / 2 - buttonWidth/2;
    float centerY = (GetScreenHeight() ) / 2;
    m_startButtonRect = {centerX, 200.0f, buttonWidth, buttonHeight};
    m_settingsButtonRect = {centerX, 300.0f, buttonWidth, buttonHeight};
    m_exitButtonRect = {centerX, 400.0f, buttonWidth, buttonHeight};


    return true;
}

bool GUI_MainMenuLayer::Update(float fElapsedTime)
{
    return true;
}


bool GUI_MainMenuLayer::Render()
{
    if (GuiButton(m_startButtonRect, "Start Game"))
    {
    }
    if (GuiButton(m_settingsButtonRect, "Settings"))
    {
    }
    return true;
}
