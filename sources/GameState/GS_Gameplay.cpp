#include "GS_Gameplay.h"

GS_Gameplay::GS_Gameplay(uint16_t id)
    : GameState(id, GameStateType::GAME_PLAY)
{

}

void GS_Gameplay::StartState()
{

}

void GS_Gameplay::ResumeState()
{

}

void GS_Gameplay::UpdateState(float fElapsedTime)
{
    GameState::UpdateState(fElapsedTime);
}

void GS_Gameplay::PauseState()
{

}

void GS_Gameplay::EndState()
{

}

void GS_Gameplay::RenderState()
{
    GameState::RenderState();
}

void GS_Gameplay::ProcessInputState()
{

}

