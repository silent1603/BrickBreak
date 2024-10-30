#include "GameState.h"

GameState::GameState(uint16_t id,GameStateType type,bool enable) : m_id(id), m_type(type) ,m_enabled(enable)
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
        if((*i)->IsEnable())
        {
            (*i)->Update(fElapsedTime);
        }
        ++i;
    }
}

void GameState::RenderState()
{
    std::vector<std::shared_ptr<GameStateLayer>>::iterator i =
        m_layers.begin();
    while (i != m_layers.end())
    {
        if((*i)->IsEnable())
        {
            (*i)->Render();
        }
        ++i;
    }
}