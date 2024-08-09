#pragma once
#include "../../math/coordinates.h"

namespace Entities
{
    class Entity
    {
        protected:
            static int idCounter;
            const int id;
            const char* texturePath;
            Math::IntCoords* position;
            Math::IntCoords* size;
            float speed;
            const int maxHealth;
            int health;
            int attackDamage;
            int rangedDamage;

        public:
            Entity(int pos[2], int sz[2], const char* tp, float s, const int mh, int d, int rd);
            Entity();
            virtual ~Entity();
            const int getId() const;
            const char* getTexturePath() const;
            Math::IntCoords* getPosition();
            Math::IntCoords* getSize();
            int getWidth() const;
            int getHeight() const;
            float getSpeed() const;
            int getMaxHealth() const;
            int getHealth() const;
            int getAttackDamage() const;
            int getRangedDamage() const;
            void setTexturePath(const char* tp);
            void setPosition(Math::IntCoords* pos);
            void setSize(Math::IntCoords* sz);
            void setPosition(int pos[2]);
            void setSpeed(float s);
            void setHealth(int h);
            void setAttackDamage(int d);
            void setRangedDamage(int d);

            // virtual methods
            virtual void attack(Entity* entity);
            virtual void rangeAttack(Entity* entity);
            virtual void jump(const float gravity);
            virtual void move(int direction);
            virtual void takeDamage(Entity* entity);
            virtual void die();
    };
}
