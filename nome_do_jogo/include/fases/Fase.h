#pragma once

#include <string>
#include "../gerenciadores/Gerenciador_Colisoes.h"
#include "../gerenciadores/Gerenciador_Grafico.h"
#include "../listas/ListaEntidades.h"
#include "../CriadorMapas.h"

namespace Fases
{
    class Fase : public Ente
    {
        private:
            static const int idClasse;
            static Gerenciadores::Gerenciador_Colisoes* pGColisoes;
            const int nOFaceis;
            const int nOMedios;
            const int nODificeis;
            const int nIFaceis;
            const int nIDificeis;
            const int nIChefoes;
            Entidades::Personagens::Jogador* jog1;
            Entidades::Personagens::Jogador* jog2;
            Listas::ListaEntidades lEntidades;
            std::string caminhoTilemap;

        private:
            void inicializaColisoes();
            void gerenciarColisoes();
            void executarEntidades(float dt);
            void criarMapa();
            const float calculaCentroCamera();

        public:
            Fase(std::string tilemap, const int nOF, const int nOM, const int nOD, const int nIF, const int nID, const int nIC);
            Fase();
            ~Fase();
            void setJogador1(Entidades::Personagens::Jogador* jog);
            void setJogador2(Entidades::Personagens::Jogador* jog);
            void executar(float dt);
            void desenhar(sf::RenderWindow& janela);
            void salvar();
    };
}