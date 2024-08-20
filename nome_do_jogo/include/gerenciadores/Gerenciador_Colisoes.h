#pragma once
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
            Entidades::Personagens::Jogador* pJogador1;
            Entidades::Personagens::Jogador* pJogador2;
            std::vector<Entidades::Personagens::Inimigo*> LInimigos;
            std::list<Entidades::Obstaculos::Obstaculo*> LObstaculos;
            
        public:
            Gerenciador_Colisoes();
            ~Gerenciador_Colisoes();
            const sf::Vector2f calculaColisoes(Entidades::Entidade* e1, Entidades::Entidade* e2);
            void tratarColisoesJogsObstacs();
            void tratarColisoesJogsInimgs();
            void tratarColisoesInimgsObstacs();
            void tratarColisoesImimgs();
            void incluirObstaculo(Entidades::Obstaculos::Obstaculo* pO);
            void incluirInimigo(Entidades::Personagens::Inimigo* pI);
            void setJog1(Entidades::Personagens::Jogador* pJog1);
            void setJog2(Entidades::Personagens::Jogador* pJog2);
            void executar();
    };
}