#include "GameState.h"

GameState::GameState(uint16_t id,GameStateType type) : m_id(id), m_type(type) 
{

}

GameState::~GameState()
{

}

void GameState::AddLayer(std::shared_ptr<GameStateLayer> layer)
{
    m_layers.emplace_back(layer);
}

void GameState::UpdateState(float fElapsedTime)
{
    std::vector<std::shared_ptr<GameStateLayer>>::iterator i = m_layers.begin();
    while (i != m_layers.end())
    {
        (*i)->update(fElapsedTime);
        ++i;
    }
    
}