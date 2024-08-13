#include "../../../include/elements/entities/player.h"

namespace Entities
{
    Player::Player(int pos[2], int sz[2]):
    Entity(pos, sz, 0.5, 100, 20, 10),
    score(0)
    {
    }

    Player::Player():
    Entity(),
    score(0)
    {
    }

    Player::~Player()
    {
        Entity::~Entity();
    }

    int Player::getScore() const
    {
        return score;
    }

    void Player::setScore(int s)
    {
        score = s;
    }

    void Player::attack(Entity* entity)
    {
        entity->takeDamage(this);
        score += attackDamage;
    }

    void Player::rangeAttack(Entity* entity)
    {
        entity->takeDamage(this);
        score += rangedDamage;
    }

    void Player::die()
    {
        // Death logic
    }
}