#pragma once
#include "../Entidade.h"
#include "../personagens/Jogador.h"

 
namespace Entidades
{
    namespace Obstaculos
    {
        class Obstaculo : public Entidade
        {
        private:
            static const unsigned int idClasse;
            bool danoso;
        
        public:
            Obstaculo(sf::Color c, const float tamXX, const float tamYY, const float xx, const float yy, const bool dano=false);
            Obstaculo();
            virtual ~Obstaculo();
            virtual void salvar() = 0;
            virtual void executar(float dt) = 0;
            virtual void obstacular(Personagens::Jogador* p) = 0;
        };
    }
}