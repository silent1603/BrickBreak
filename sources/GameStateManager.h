#ifndef GAMESTATEMANAGER
#define GAMESTATEMANAGER
#include <vector>
#include <memory>
#include <queue>
#include "GameState.h"
#include "GameStateType.h"

class GameStateManager
{
public:
    GameStateManager();
    GameStateManager(uint16_t initStateSize);

    virtual ~GameStateManager();
    
    GameStateManager(const GameStateManager&) = delete;
    GameStateManager& operator=(const GameStateManager&) = delete;
    
    inline std::size_t Count() const { return m_gameStateStack.size();}
    
    void ActiveState(uint16_t id);
    void PushState(std::shared_ptr<GameState> state);
    void Update(float fTimeElapsed);
    bool NeedUpdate();
    std::shared_ptr<GameState> PopState();
    std::shared_ptr<GameState> PeekState();
    std::shared_ptr<GameState> GetStatebById(uint16_t id);
    

private:
    std::vector<std::shared_ptr<GameState>> m_gameStateStack;
    std::queue<std::shared_ptr<GameState>> m_gameStateQueue; 
    GameState* m_currentState;
};
#endif