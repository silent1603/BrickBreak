#ifndef GS_SETTINGS
#define GS_SETTINGS
#include "GameState.h"
class GS_Setting : public GameState
{
public:
    GS_Setting(uint16_t id);

    void StartState() override;
    void ResumeState() override; 
    void UpdateState(float fElapsedTime) override; 
    void PauseState() override; 
    void EndState() override ;
    void RenderState() override;
    void ProcessInputState() override;
} ;
#endif