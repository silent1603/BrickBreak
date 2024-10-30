#ifndef GS_GAMEPLAY
#define GS_GAMEPLAY
#include "GameState.h"
class GS_Gameplay : public GameState
{
public:
    GS_Gameplay(uint16_t id);

    void StartState() override;
    void ResumeState() override; 
    void UpdateState(float fElapsedTime) override; 
    void PauseState() override; 
    void EndState() override ;
    void RenderState() override;
    void ProcessInputState() override;
} ;
#endif