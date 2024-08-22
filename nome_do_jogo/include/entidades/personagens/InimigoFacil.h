#pragma once

#include "Inimigo.h"

namespace Entidades
{
    namespace Personagens
    {
        class InimigoFacil : public Inimigo
        {
            public:

                InimigoFacil(sf::Color c, const float tamXX, const float tamYY, const float xx, const float yy, const int vd, const float vel, const int f, const float duraEspera, const float duraAtaque);
                InimigoFacil(sf::Color c, const float tamXX, const float tamYY, const float xx=0.0f, const float yy=0.0f);
                InimigoFacil();
                ~InimigoFacil();
                void salvar();
                //void atacarCorpo(Personagem* pPersonagem);
                //void atacarDist(Personagem* pPersonagem); 
                //void colidir(Entidade* entAlternativa, sf::Vector2f distancia_colisao);
        };
    }
}