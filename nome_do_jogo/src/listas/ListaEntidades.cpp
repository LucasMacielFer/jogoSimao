#include "listas/ListaEntidades.h"

namespace Listas 
{
    ListaEntidades::ListaEntidades():
    lista_entidades(),
    iterador_entidades(&lista_entidades)
    {
        iterador_entidades.primeiro();
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
        Entidades::Entidade* e = iterador_entidades.getAtual();
        iterador_entidades.proximo();
        return e;
    }

    void ListaEntidades::percorreExecutando(float dt)
    {
        iterador_entidades.primeiro();
        while(!iterador_entidades.fimDaLista())
        {
            (iterador_entidades.getAtual())->executar(dt);
            iterador_entidades.proximo();
        }
    }

    const bool ListaEntidades::fim() const
    {
        return iterador_entidades.fimDaLista();
    }

    const unsigned int ListaEntidades::tamanho() const{ return (lista_entidades.getTamanho());}
}