#pragma once

#include "Lista.h"
#include "Iterador.h"
#include "../entidades/Entidade.h"

namespace Listas
{
    class ListaEntidades
    {
        private:

            Lista<Entidades::Entidade> lista_entidades;
            Iterador<Entidades::Entidade> iterador_entidades;

        public:

            ListaEntidades();
            ~ListaEntidades();

            void acrescentarEntidade(Entidades::Entidade* pEnt);
            void removerEntidade(Entidades::Entidade* pEnt);
            void limpaLista();
            void irAoPrimeiro();
            void percorreExecutando(float dt);
            void percorreDesenhando(sf::RenderWindow& janela);
            Entidades::Entidade* passoPercorrer();
            const bool fim() const;
            const unsigned int tamanho() const;
    };
}