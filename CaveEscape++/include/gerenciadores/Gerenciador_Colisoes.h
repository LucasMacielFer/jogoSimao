#pragma once
#include <algorithm>
#include <vector>
#include <list>
#include <SFML/Graphics.hpp>
#include "cmath"

#include "../entidades/obstaculos/Obstaculo.h"
#include "../entidades/personagens/Inimigo.h"

namespace Gerenciadores
{
    class Gerenciador_Colisoes
    {
        private:
            // Ponteiro estático para instância do gerenciador - Padrão de projeto Singleton
            static Gerenciador_Colisoes* pInstancia;
            Entidades::Personagens::Jogador* pJogador1;
            Entidades::Personagens::Jogador* pJogador2;
            std::vector<Entidades::Entidade*> LInimigos;
            std::list<Entidades::Entidade*> LObstaculos;

        private:
            // Construtora privada, em conformidade com o padrão de projeto Singleton
            Gerenciador_Colisoes();
            
        public:
            ~Gerenciador_Colisoes();
            const sf::Vector2f calculaColisoes(Entidades::Entidade* e1, Entidades::Entidade* e2);
            void tratarColisoesJogsObstacs();
            void tratarColisoesJogsInimgs();
            void tratarColisoesInimgsObstacs();
            void tratarColisoesImimgs();
            void incluirObstaculo(Entidades::Entidade* pO);
            void incluirInimigo(Entidades::Entidade* pI);
            void removerObstaculo(Entidades::Entidade* pO);
            void removerInimigo(Entidades::Entidade* pI);
            void limparListas();
            void setJog1(Entidades::Personagens::Jogador* pJog1);
            void setJog2(Entidades::Personagens::Jogador* pJog2);
            void executar();
            static Gerenciador_Colisoes* getInstancia();
    };
}