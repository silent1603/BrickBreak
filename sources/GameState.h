#ifndef GAMESTATE
#define GAMESTATE
#include <vector>
#include <memory>
#include "GameStateLayer.h"
#include "GameStateType.h"
class GameState
{
public:
    GameState(uint16_t id,GameStateType type,bool enable = true);
	GameState(const GameState&) = delete;
	GameState& operator=(const GameState&) = delete;

    virtual ~GameState();

    virtual void StartState() = 0;
    virtual void ResumeState() = 0;
    virtual void UpdateState(float fElapsedTime);
    virtual void PauseState() = 0;
    virtual void EndState() = 0;
    virtual void RenderState();
    virtual void ProcessInputState() = 0;
    inline uint16_t Id() const { return m_id;}
    std::size_t layers() const {return m_layers.size();}

    inline GameStateType Type() const { return m_type;}

    void AddLayer(std::shared_ptr<GameStateLayer> layer);
    bool IsEnable() const { return m_enabled;}
    void SetEnable(bool enable){m_enabled = enable;}
protected:
    std::vector<std::shared_ptr<GameStateLayer>> m_layers;
    GameStateType m_type;
    uint16_t m_id;
    bool m_enabled;
};
#endif