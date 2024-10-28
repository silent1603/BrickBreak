#include "GS_MainMenu.h"

GS_MainMenu::GS_MainMenu(uint16_t id) : GameState(id, GameStateType::MAIN_MENU)
{
}

void GS_MainMenu::StartState()
{
    std::cout << "Main Menu: Starting\n";
}

void GS_MainMenu::ResumeState()
{
    std::cout << "Main Menu: Resuming\n";
}

void GS_MainMenu::UpdateState(float fElapsedTime)
{
    std::cout << "Main Menu: Updating\n";
}

void GS_MainMenu::PauseState()
{
    std::cout << "Main Menu: Pausing\n";
}

void GS_MainMenu::EndState()
{
    std::cout << "Main Menu: Ending\n";
}

void GS_MainMenu::RenderState()
{
    std::cout << "Main Menu: Rendering\n";
}

void GS_MainMenu::ProcessInputState()
{
    std::cout << "Main Menu: Processing Input\n";
}