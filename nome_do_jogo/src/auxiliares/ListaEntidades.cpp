#include "auxiliares/ListaEntidades.h"

namespace Auxiliares 
{
    ListaEntidades::ListaEntidades(): lista_entidades()
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

    const unsigned int ListaEntidades::tamanho() const{ return (lista_entidades.getTamanho());}

    Entidades::Entidade* ListaEntidades::operator[](unsigned int chave)
    {
        return (lista_entidades[chave]);
    }

}