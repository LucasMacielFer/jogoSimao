#pragma once

#include <SFML/Graphics.hpp>
#include "../listas/ListaEntidades.h"
#include "cmath"

namespace Gerenciadores
{
    class Gerenciador_Colisoes
    {
        private:
            Listas::ListaEntidades* listaPersonagens;
            Listas::ListaEntidades* listaObstaculos;
        public:

            Gerenciador_Colisoes();
            Gerenciador_Colisoes(Listas::ListaEntidades* lPersonagens, Listas::ListaEntidades* lObstaculos);
            ~Gerenciador_Colisoes();
            const sf::Vector2f calculadora_colisoes(Entidades::Entidade* entidade1, Entidades::Entidade* entidade2);
            void executar();

    };

}