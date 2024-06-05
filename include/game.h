#pragma once
#include "game-parts/level.h"

// Salvamento/carregamento desacoplado com "function" do stl

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