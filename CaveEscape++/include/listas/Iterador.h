#include "Lista.h"

namespace Listas
{
    template<class T>
    class Iterador
    {
        private:
            int indiceAtual;
            Lista<T>* lista;
            typename Lista<T>::template Elemento<T>* elemPrimeiro;
            typename Lista<T>::template Elemento<T>* elemAtual;
        
        public:
            Iterador(Lista<T>* l);
            ~Iterador();
            void primeiro();
            void proximo();
            const bool fimDaLista() const;
            T* getAtual() const;
    };

    template<class T>
    Iterador<T>::Iterador(Lista<T>* l):
    indiceAtual(0),
    lista(l),
    elemPrimeiro(NULL),
    elemAtual(NULL)
    {
        if(lista)
        {
            elemPrimeiro = lista->getPrimeiro();
            elemAtual = elemPrimeiro;
        }
        else
        {
            std::cout << "Ponteiro para lista eh nulo" << std::endl;
        }
    }

    template<class T>
    Iterador<T>::~Iterador()
    {
        indiceAtual = -1;
        lista = NULL;
        elemPrimeiro = NULL;
        elemAtual = NULL;
    }    

    template<class T>
    void Iterador<T>::primeiro()
    {
        elemPrimeiro = lista->getPrimeiro();
        indiceAtual = 0;
        elemAtual = elemPrimeiro;
    }

    template<class T>
    void Iterador<T>::proximo()
    {
        elemAtual = elemAtual->getProximo();
        indiceAtual++;
    }

    template<class T>
    const bool Iterador<T>::fimDaLista() const
    {
        if(indiceAtual > lista->getTamanho() - 1)
            return true;
        return false;
    }

    template<class T>
    T* Iterador<T>::getAtual() const
    {
        if(elemAtual)
            return elemAtual->getInfo();
        else
            return NULL;
    }
}