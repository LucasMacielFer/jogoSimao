#pragma once
#include "game-parts/level.h"

namespace GameMain
{
    class Game
    {
        private:
            GameParts::Level* level;
            Entities::Player* player1;
            Entities::Player* player2;
            
        public:
            Game();
            ~Game();
            void run();
    };
}