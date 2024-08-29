#include "listas/ListaEntidades.h"

namespace Listas 
{
    ListaEntidades::ListaEntidades():
    lista_entidades(),
    iterador_entidades(&lista_entidades)
    {
    }

    ListaEntidades::~ListaEntidades()
    {
        lista_entidades.limpar();
    }

    void ListaEntidades::acrescentarEntidade(Entidades::Entidade* pEnt)
    {
        if(pEnt)
        {
            lista_entidades.adicionar(pEnt);
        }
        else
        {
            std::cout << "Tentativa de inserir entidade nula" << std::endl;
        }
    }

    void ListaEntidades::removerEntidade(Entidades::Entidade* pEnt)
    {
        if(pEnt)
        {
            lista_entidades.remover(pEnt);
        }
        else
        {
            std::cout << "Tentativa de remover entidade nula" << std::endl;
        }
    }

    void ListaEntidades::limpaLista()
    {
        lista_entidades.limpar();
    }

    void ListaEntidades::irAoPrimeiro()
    {
        iterador_entidades.primeiro();
    }

    Entidades::Entidade* ListaEntidades::passoPercorrer()
    {
        if(!iterador_entidades.fimDaLista())
        {
            Entidades::Entidade* e = iterador_entidades.getAtual();
            iterador_entidades.proximo();
            return e;
        }
        return NULL;
    }

    void ListaEntidades::percorreExecutando(float dt)
    {
        iterador_entidades.primeiro();
        while(!iterador_entidades.fimDaLista())
        {
            if(iterador_entidades.getAtual())
                (iterador_entidades.getAtual())->executar(dt);
            iterador_entidades.proximo();
        }
    }

    void ListaEntidades::percorreDesenhando(sf::RenderWindow& janela)
    {
        iterador_entidades.primeiro();
        while(!iterador_entidades.fimDaLista())
        {
            if(iterador_entidades.getAtual())
                (iterador_entidades.getAtual())->desenhar(janela);
            iterador_entidades.proximo();
        }
    }

    const bool ListaEntidades::fim() const
    {
        return iterador_entidades.fimDaLista();
    }

    const unsigned int ListaEntidades::tamanho() const
    {
        return (lista_entidades.getTamanho());
    }
}