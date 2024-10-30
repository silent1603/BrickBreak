#include "GS_Setting.h"

GS_Setting::GS_Setting(uint16_t id)
    : GameState(id, GameStateType::SETTINGS)
{

}

void GS_Setting::StartState()
{

}

void GS_Setting::ResumeState()
{

}

void GS_Setting::UpdateState(float fElapsedTime)
{
    GameState::UpdateState(fElapsedTime);
}

void GS_Setting::PauseState()
{

}

void GS_Setting::EndState()
{

}

void GS_Setting::RenderState()
{
    GameState::RenderState();
}

void GS_Setting::ProcessInputState()
{

}

