#ifndef GAME
#define GAME
#include <memory>
#include "GameStateManager.h"

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
    void LoadGameConfig();
private:
    bool m_running;
};
#endif