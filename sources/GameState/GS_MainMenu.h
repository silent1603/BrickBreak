#ifndef GS_MAINMENU
#define GS_MAINMENU
#include "GameState.h"
#include <iostream>
#include "GameStateType.h"
class GS_MainMenu : public GameState
{
public:
    GS_MainMenu(uint16_t id);

    void StartState() override;
    void ResumeState() override; 
    void UpdateState(float fElapsedTime) override; 
    void PauseState() override; 
    void EndState() override ;
    void RenderState() override;
    void ProcessInputState() override;
};
#endif