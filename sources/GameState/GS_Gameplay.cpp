#include "GS_Gameplay.h"
#include "GameLayer/GL_Entity_Gameplay.h"
#include "GameLayer/HUD_GameplayLayer.h"
GS_Gameplay::GS_Gameplay(uint16_t id)
    : GameState(id, GameStateType::GAME_PLAY)
{

}

void GS_Gameplay::StartState()
{
    std::shared_ptr<Hud
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

