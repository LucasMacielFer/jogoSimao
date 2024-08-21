#pragma once

#include "Inimigo.h"

namespace Entidades
{
    namespace Personagens
    {
        class InimigoFacil : public Inimigo
        {
            private:

            protected:

            public:

                InimigoFacil(std::string txt="",const int vd = 10, const float vel = 10.0f, const int danos = 1, const float duraEspera = 0.0f, const float duraAtaque = 0.0f, const float tamXX=10.0f, const float tamYY=10.0f, const float xx=0.0f, const float yy=0.0f);
                ~InimigoFacil();
                virtual void salvar();
                virtual void executar(float dt);
                virtual void colidir(Entidade* entAlternativa, sf::Vector2f distancia_colisao);
        };
    }
}