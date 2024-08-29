#pragma once
#include "../Entidade.h"
#include "../personagens/Personagem.h"

 
namespace Entidades
{
    namespace Obstaculos
    {
        class Obstaculo : public Entidade
        {
        private:
            bool danoso;
        
        public:
            Obstaculo(const char* txt, const float tamXX, const float tamYY, const float xx, const float yy, const bool dano=false);
            Obstaculo();
            virtual ~Obstaculo();
            virtual void regularColisao(Entidade* entAlternativa, sf::Vector2f distancia_colisao);
            void colidir(Entidade* entAlternativa, sf::Vector2f distancia_colisao);
            virtual void obstacular(Personagens::Personagem* p) = 0;
            virtual void salvar() = 0;
            virtual void executar(float dt) = 0;
        };
    }
}