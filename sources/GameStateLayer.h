#ifndef GAMELAYER
#define GAMELAYER
#include <stdint.h>
class GameStateLayer
{
public:
    GameStateLayer(uint16_t id, bool enable);
    virtual ~GameStateLayer();
    GameStateLayer(const GameStateLayer&) = delete;
	GameStateLayer& operator=(const GameStateLayer&) = delete;

    inline uint16_t Id() const { return m_id;}
    inline bool IsEnable() const { return m_enabled;}
    inline bool SetEnable(bool enabled) { m_enabled = enabled;}
    
    virtual bool Setup() = 0;
    virtual bool Update(float fElapsedTime) = 0;
    virtual bool Render() = 0;

protected:
    uint16_t m_id;
    bool m_enabled;
};
#endif