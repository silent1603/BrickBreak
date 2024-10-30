#include "GameStateManager.h"

GameStateManager::GameStateManager() : m_currentState(nullptr)
{

}

GameStateManager::GameStateManager(uint16_t initStateSize)
{
    m_gameStateStack.reserve(initStateSize);
}

GameStateManager::~GameStateManager()
{

}

void GameStateManager::ActiveState(uint16_t id)
{
    if(m_currentState->Id() != id)
    {
		for(auto s : m_gameStateStack)
        { 
            if(s->Id() == id) 
            {
				m_currentState = s.get();
			}
        }
	}
}

void GameStateManager::PushState(std::shared_ptr<GameState> state)
{
    if (m_gameStateStack.size() > 1)
    {
        std::shared_ptr<GameState> state =  (*m_gameStateStack.rbegin());
        state->PauseState();
    }

	auto st = std::find(m_gameStateStack.begin(), m_gameStateStack.end(), state);
	if(st == m_gameStateStack.end())
    {
		m_gameStateStack.emplace_back(state);
        state->StartState();
        state->ResumeState();
	    m_currentState = state.get();
        
	}
}

std::shared_ptr<GameState> GameStateManager::PopState()
{
    std::shared_ptr<GameState> state = nullptr;
    if (m_gameStateStack.size() > 0)
    {
        std::shared_ptr<GameState> state = (*m_gameStateStack.rbegin());
        state->EndState();
        m_gameStateStack.pop_back();
    }
     return state;
}

std::shared_ptr<GameState> GameStateManager::PeekState()
{
    return m_gameStateStack.size() > 0 ? (*m_gameStateStack.rbegin()) : nullptr;
}

std::shared_ptr<GameState> GameStateManager::GetStatebById(uint16_t id)
{
    auto st = std::find_if(m_gameStateStack.begin(), m_gameStateStack.end(), 
    [id](const std::shared_ptr<GameState>& gameState)
        {
            return gameState->Id() == id;
        }
    );
    
    return st != m_gameStateStack.end() ? (*st) : nullptr;
}

void GameStateManager::Update(float fTimeElapsed)
{
    if (m_currentState)
    {
        m_currentState->UpdateState(fTimeElapsed)
    }
}