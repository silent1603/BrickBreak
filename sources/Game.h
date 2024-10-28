#ifndef GAME
#define GAME
#include <memory>
#include "GameStateManager.h"
struct GameConfigInfo;
class Game
{
public:
    Game();
    ~Game();
    void Init();
    void CleanUp();
    void Update(float fElapsedTime);
    void HandleEvents();
    void Draw();
    bool Running() { return m_running;}
    void Quit() { m_running =false;}
    GameConfigInfo LoadGameConfig();
private:

    bool m_running;
    std::unique_ptr<GameStateManager> m_stateManager;
};
#endif