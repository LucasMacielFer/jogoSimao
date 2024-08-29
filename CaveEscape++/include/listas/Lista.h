#pragma once

#include <iostream>

namespace Listas
{
    template< class T>
    class Lista
    {
        public:
            template < class Tipo>
            class Elemento
            {
                private:

                    Elemento<Tipo>* pProximo;
                    Elemento<Tipo>* pAnterior;
                    Tipo* pInfo;

                public:

                Elemento(): pProximo(NULL), pAnterior(NULL), pInfo(NULL)
                {

                }

                ~Elemento()
                {
                    pProximo = NULL;
                    pAnterior = NULL;
                    pInfo = NULL;
                }

                void setProximo(Elemento<Tipo>* pP)  { pProximo = pP;}

                Elemento<Tipo>* getProximo(){ return pProximo;}

                void setAnterior(Elemento<Tipo>* pA) { pAnterior = pA;}

                Elemento<Tipo>* getAnterior() { return pAnterior;}

                void setInfo(Tipo* info){ pInfo = info;}

                Tipo* getInfo(){ return pInfo;}
            };

        private:
            Elemento<T>* pPrimeiro;
            Elemento<T>* pAtual;
            unsigned int tamanho;

        public:
            Lista();
            ~Lista();

            void limpar();
            const unsigned int getTamanho() const { return tamanho;}
            //T* operator[](unsigned int chave);
            void adicionar(T* info);
            T* remover(T* info);
            Elemento<T>* getPrimeiro(){ return pPrimeiro;}

        private:
            void setElemento(Elemento<T>* pElemento);
            Elemento<T>* getAtual(){ return pAtual;}

    };

    template<class T>
    Lista<T>:: Lista(): pPrimeiro(NULL), pAtual(NULL), tamanho(0)
    {

    }

    template<class T>
    Lista<T>:: ~Lista()
    {            
        limpar();

        pPrimeiro = NULL;
        pAtual = NULL;  
        tamanho = 0;
    }

    template<class T>
    void Lista<T>::limpar()
    {

        Elemento<T>* pAux1 = NULL;
        Elemento<T>* pAux2 = NULL;

        pAux1 = pPrimeiro;
        pAux2 = pAux1;
        
        while(pAux1 != NULL)
        {
            pAux2 = pAux1->getProximo();
            delete (pAux1->getInfo());
            delete (pAux1);
            pAux1 = pAux2;
        }

        pPrimeiro = NULL;
        pAtual = NULL;

    }

    template<class T>
    void Lista<T>::setElemento(Elemento<T>* pElemento)
    {
        if(pElemento)
        {
            if(pPrimeiro == NULL)
            {
                pPrimeiro = pElemento;
                pAtual = pElemento;
            }
            else 
            {
                pAtual->setProximo (pElemento);
                pElemento->setAnterior(pAtual);
                pAtual = pElemento;
            }

            tamanho++;
        }
        else
        {
            std::cout <<"Null Insertion" << std::endl;
        }
    }

    /*
    template<class T>
    T* Lista<T>::operator[](unsigned int chave)
    {
        if(chave >= tamanho || chave < 0)
        {
            std::cout << "Invalid position" << std::endl;
            exit(1);
        }

        else 
        {
            Elemento<T>* pAux = pPrimeiro;
            for(int i = 0; i < chave; i++)
            {
                pAux = pAux->getProximo();
            }
            return (pAux->getInfo());
        }
    }
    */

    template<class T>
    void Lista<T>::adicionar(T* info)
    {
        if(info)
        {
            Elemento<T>* pEl = NULL;
            pEl = new Elemento<T>();
            pEl->setInfo(info);
            setElemento(pEl);
        }
        else
        {
            std::cout << "Empty information" << std::endl; 
        }
    }

    template<class T>
    T* Lista<T>::remover(T* info)
    {
        Elemento<T>* pAux = pPrimeiro;
        Elemento<T>* pAnt = NULL;

        while(pAux != NULL)
        {

            if (pAux && pAux->getInfo() == info)
            {
                if(pAux == pPrimeiro)
                {
                    pPrimeiro = pAux->getProximo();
                }
                else if(pAux == pAtual)
                {
                    pAtual = pAux->getAnterior();
                }
                else 
                {
                    pAnt->setProximo(pAux->getProximo());
                }

                delete (pAux);
                tamanho--;
                return info;
            }
            pAnt = pAux;
            pAux = pAux->getProximo();
        }
        return NULL;
    }
}