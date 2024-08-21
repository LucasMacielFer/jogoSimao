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
            bool danoso;
        
        public:
            Obstaculo(bool dano=false, std::string txt="", const float tamXX=10.0f, const float tamYY=10.0f, const float xx=0.0f, const float yy=0.0f);
            virtual ~Obstaculo();
            virtual void salvar() = 0;
            virtual void executar(float dt) = 0;
            virtual void obstacular(Personagens::Jogador* p) = 0;
        };
    }
}