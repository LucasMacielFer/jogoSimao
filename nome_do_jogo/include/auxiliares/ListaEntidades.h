#pragma once

#include "../auxiliares/Lista.h"
#include "../entidades/Entidade.h"

namespace Auxiliares
{
    class ListaEntidades
    {
        private:

            Lista<Entidades::Entidade> lista_entidades;

        public:

            ListaEntidades();
            ~ListaEntidades();

            void acrescentarEntidade(Entidades::Entidade* pEnt);
            void removerEntidade(Entidades::Entidade* pEnt);
            void limpaLista();
            const unsigned int tamanho() const;
            Entidades::Entidade* operator[](unsigned int chave);

    };

}