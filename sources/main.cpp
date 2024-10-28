
#include "Game.h"

int main() {
    Game game;
    game.Init();

    while (game.Running()) {
        game.HandleEvents();
        game.Update(0.016f);
        game.Draw();
    }

    game.CleanUp();
    return 0;
}