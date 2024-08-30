#pragma once
#include "../Entidade.h"
#include "../personagens/Personagem.h"

 
namespace Entidades
{
    namespace Obstaculos
    {
        enum idObstaculos
        {
            Indefinido = -1,
            plat,
            esp,
            gosm
        };

        class Obstaculo : public Entidade
        {
        private:
            idObstaculos identificador;
            bool danoso;
        
        public:
            Obstaculo(const char* txt, const float tamXX, const float tamYY, const float xx, const float yy, idObstaculos id, const bool dano=false);
            Obstaculo();
            virtual ~Obstaculo();
            virtual void regularColisao(Entidade* entAlternativa, sf::Vector2f distancia_colisao);
            void colidir(Entidade* entAlternativa, sf::Vector2f distancia_colisao);
            virtual void obstacular(Personagens::Personagem* p) = 0;
            virtual void salvar(const char* caminhoSalvamento);
            virtual void executar(float dt) = 0;
        };
    }
}