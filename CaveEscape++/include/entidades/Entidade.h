#pragma once

#include <fstream>
#include "../Ente.h"

#define GRAVIDADE 25

namespace Entidades
{
    class Entidade : public Ente
    {
        protected:
            float tamX;
            float tamY;
            float x;
            float y;
            float velocidade;
            const float maxVelocidade;
            float velocidadeX;
            float velocidadeY;
            int sentidoMovX;
        
        private:
            const char* caminhoTextura;
            sf::RectangleShape retangulo;

        protected:
            std::string salvamento;

        protected:
            void atualizaTextura();
        
        public:
            Entidade(idEntes i, const char* txt, const float tamXX, const float tamYY, const float xx, const float yy, const float vel);
            Entidade(idEntes i, const char* txt, const float tamXX, const float tamYY, const float xx, const float yy);
            Entidade(idEntes i, const char* txt, const float tamXX, const float tamYY, const float xx, const float yy, const int sentMovX, const float vel);
            Entidade();
            virtual ~Entidade();
            void setTamanho(const float xx, const float yy);
            const sf::Vector2f getTamanho() const;
            void setPosicao(const float xx, const float yy);
            const sf::Vector2f getPosicao() const;
            void setVelocidade(const float vel);
            const float getVelMax() const;
            void movimentaX(const float s);
            void aplicaGravidade(float dt);
            void aplicaGravidade(float dt, float sustentacao);
            void desenhar(sf::RenderWindow& janela);
            void mover();
            void atualizaEntidade();
            std::string getSalvamento() const;
            virtual void regularColisao(Entidade* entAlternativa, sf::Vector2f distancia_colisao) = 0;
            virtual void colidir(Entidade* entAlternativa, sf::Vector2f distancia_colisao) = 0;
            virtual void executar(float dt) = 0;
            virtual void salvar(const char* caminhoSalvamento);
    };
}