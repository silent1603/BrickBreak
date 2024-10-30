#ifndef GS_ENDGAME
#define GS_ENDGAME
#include "GameState.h"
class GS_EndGame : public GameState
{
public:
    GS_EndGame(uint16_t id);

    void StartState() override;
    void ResumeState() override; 
    void UpdateState(float fElapsedTime) override; 
    void PauseState() override; 
    void EndState() override ;
    void RenderState() override;
    void ProcessInputState() override;
} ;
#endif