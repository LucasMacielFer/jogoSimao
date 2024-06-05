#pragma once
#include "entity.h"

namespace Entities 
{
    class Player : public Entity 
    {
        private:
            int score;

        public:
            Player(int pos[2], int sz[2], const char* tp);
            Player();
            ~Player();
            int getScore() const;
            void setScore(int s);

            // Virtual methods from Entity:
            void attack(Entity* entity);
            void rangeAttack(Entity* entity);
            void die();
    };
}