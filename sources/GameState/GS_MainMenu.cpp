#include "GS_MainMenu.h"
#include "GameLayer/GUI_MainMenuLayer.h"
GS_MainMenu::GS_MainMenu(uint16_t id)
    : GameState(id, GameStateType::MAIN_MENU)
{

}

void GS_MainMenu::StartState()
{
    std::shared_ptr<GUI_MainMenuLayer> guilayer = std::make_shared<GUI_MainMenuLayer>(0,true);
    guilayer->Setup();
    m_layers.emplace_back(guilayer);
}

void GS_MainMenu::ResumeState()
{

}

void GS_MainMenu::UpdateState(float fElapsedTime)
{
    GameState::UpdateState(fElapsedTime);
}

void GS_MainMenu::PauseState()
{

}

void GS_MainMenu::EndState()
{

}

void GS_MainMenu::RenderState()
{
    GameState::RenderState();
}

void GS_MainMenu::ProcessInputState()
{

}

