#include "../../../include/elements/entities/entity.h"

namespace Entities
{
    int Entity::idCounter = 0;

    Entity::Entity(int pos[2], int sz[2], const char* tp, float s, int mh, int d, int rd):
    texturePath(tp),
    speed(s),
    health(mh),
    maxHealth(mh),
    attackDamage(d),
    rangedDamage(rd),
    id(idCounter)
    {
        idCounter++;
        position = new Math::IntCoords(pos[0], pos[1]);
        size = new Math::IntCoords(sz[0], sz[1]);
    }

    Entity::Entity():
    texturePath(""),
    speed(0),
    health(0),
    maxHealth(0),
    attackDamage(0),
    rangedDamage(0),
    id(idCounter)
    {
        idCounter++;
        position = NULL;
        size = NULL;
    }

    Entity::~Entity()
    {
        delete position;
    }

    const char* Entity::getTexturePath() const
    {
        return texturePath;
    }

    Math::IntCoords* Entity::getPosition()
    {
        return position;
    }

    Math::IntCoords* Entity::getSize()
    {
        return size;
    }

    int Entity::getWidth() const
    {
        return size->getX();
    }

    int Entity::getHeight() const
    {
        return size->getY();
    }

    float Entity::getSpeed() const
    {
        return speed;
    }

    int Entity::getMaxHealth() const
    {
        int aux = maxHealth;
        return aux;
    }

    int Entity::getHealth() const
    {
        return health;
    }

    int Entity::getAttackDamage() const
    {
        return attackDamage;
    }

    int Entity::getRangedDamage() const
    {
        return rangedDamage;
    }

    void Entity::setTexturePath(const char* tp)
    {
        texturePath = tp;
    }

    void Entity::setPosition(Math::IntCoords* pos)
    {
        position = pos;
    }

    void Entity::setSize(Math::IntCoords* sz)
    {
        size = sz;
    }

    void Entity::setPosition(int pos[2])
    {
        if(position != NULL)
        {
            position->setX(pos[0]);
            position->setY(pos[1]);
        }
        else
        {
            position = new Math::IntCoords(pos[0], pos[1]);
        }
    }

    void Entity::setSpeed(float s)
    {
        speed = s;
    }

    void Entity::setHealth(int h)
    {
        health = h;
    }

    void Entity::setAttackDamage(int d)
    {
        attackDamage = d;
    }

    void Entity::setRangedDamage(int d)
    {
        rangedDamage = d;
    }

    void Entity::attack(Entity* entity)
    {
        entity->takeDamage(this);
    }

    void Entity::rangeAttack(Entity* entity)
    {
        entity->takeDamage(this);
    }

    void Entity::jump(const float gravity)
    {
        // Jumping logic
    }

    void Entity::move(int direction)
    {
        if (direction == -1)
        {
            position->setX(position->getX() - speed);
        }
        else if (direction == 1)
        {
            position->setX(position->getX() + speed);
        }
        else if (direction == -2)
        {
            position->setY(position->getX() - speed);
        }
        else if (direction == 2)
        {
            position->setY(position->getX() + speed);
        }
    }

    void Entity::takeDamage(Entity* entity)
    {
        health -= entity->getAttackDamage();
        if (health <= 0)
        {
            die();
        }
    }

    void Entity::die()
    {
        // Death logic
    }
}