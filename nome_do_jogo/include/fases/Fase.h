#pragma once

#include <string>
#include "../gerenciadores/Gerenciador_Colisoes.h"
#include "../gerenciadores/Gerenciador_Grafico.h"
#include "../listas/ListaEntidades.h"
#include "../CriadorMapas.h"

#include "../entidades/personagens/Mago.h"

namespace Fases
{
    class Fase : public Ente
    {
        protected:
            static const int idClasse;
            static Gerenciadores::Gerenciador_Colisoes* pGColisoes;
            int tamMapa;
            Entidades::Personagens::Jogador* jog1;
            Entidades::Personagens::Jogador* jog2;
            Listas::ListaEntidades lEntidades;
            std::string caminhoTilemap;

        private:
            void gerenciarProjeteis();
            void gerenciarColisoes();
            void executarEntidades(float dt);
            const float calculaCentroCamera();

        protected:
            void inicializaColisoes();

        public:
            Fase(std::string tilemap);
            Fase();
            virtual ~Fase();
            void setJogador1(Entidades::Personagens::Jogador* jog);
            void setJogador2(Entidades::Personagens::Jogador* jog);
            void executar(float dt);
            void desenhar(sf::RenderWindow& janela);
            void salvar();
    };
}