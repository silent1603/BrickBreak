#include "GS_EndGame.h"

GS_EndGame::GS_EndGame(uint16_t id)
    : GameState(id, GameStateType::ENDGAME)
{

}

void GS_EndGame::StartState()
{

}

void GS_EndGame::ResumeState()
{

}

void GS_EndGame::UpdateState(float fElapsedTime)
{
    GameState::UpdateState(fElapsedTime);
}

void GS_EndGame::PauseState()
{

}

void GS_EndGame::EndState()
{

}

void GS_EndGame::RenderState()
{
    GameState::RenderState();
}

void GS_EndGame::ProcessInputState()
{

}

