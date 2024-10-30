#include "GameState.h"

GameState::GameState(uint16_t id,GameStateType type) : m_id(id), m_type(type) 
{

}

GameState::~GameState()
{

}

void GameState::AddLayer(std::shared_ptr<GameStateLayer> layer)
{
    m_layers.push_back(layer);
}

void GameState::UpdateState(float fElapsedTime)
{
    std::vector<std::shared_ptr<GameStateLayer>>::reverse_iterator i = m_layers.rbegin();
    while (i != m_layers.rend())
    {
        (*i)->Update(fElapsedTime);
        ++i;
    }
    
}

void GameState::RenderState()
{
    std::vector<std::shared_ptr<GameStateLayer>>::reverse_iterator i =
        m_layers.rbegin();
    while (i != m_layers.rend())
    {
        (*i)->Render();
        ++i;
    }
}