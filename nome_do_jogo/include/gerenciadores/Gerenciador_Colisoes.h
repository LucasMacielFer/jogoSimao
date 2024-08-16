#pragma once

#include <SFML/Graphics.hpp>
#include "auxiliares/ListaEntidades.h"
#include "cmath"

namespace Gerenciadores
{
    class Gerenciador_Colisoes
    {
        private:
            Auxiliares::ListaEntidades* listaPersonagens;
            Auxiliares::ListaEntidades* listaObstaculos;
        public:

            Gerenciador_Colisoes();
            Gerenciador_Colisoes(Auxiliares::ListaEntidades* lPersonagens, Auxiliares::ListaEntidades* lObstaculos);
            ~Gerenciador_Colisoes();
            //const sf::Vector2f calculadora_colisoes(Entidades::Entidade* entidade1, Entidades::Entidade* entidade2);
            //void executar();

    };

}