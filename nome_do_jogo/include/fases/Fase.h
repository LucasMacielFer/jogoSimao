#pragma once

#include <string>
#include "../gerenciadores/Gerenciador_Colisoes.h"
#include "../gerenciadores/Gerenciador_Grafico.h"
#include "../listas/ListaEntidades.h"

namespace Fases
{
    class Fase
    {
        private:
            const int nOFaceis;
            const int nOMedios;
            const int nODificeis;
            const int nIFaceis;
            const int nIDificeis;
            const int nIChefoes;
            static Gerenciadores::Gerenciador_Grafico pGGrafico;
            static Gerenciadores::Gerenciador_Colisoes pGColisoes;
            Entidades::Personagens::Jogador* jog1;
            Entidades::Personagens::Jogador* jog2;
            //CriadorMapas criadorMapa;
            Listas::ListaEntidades* lEntidades;
            std::string caminhoText;
            std::string caminhoTilemap;

        private:
            void gerenciarColisoes();
            void executarEntidades();

        public:
            Fase(std::string text, std::string tile, const int nOF, const int nOM, const int nOD, const int nIF, const int nID, const int nIC);
            ~Fase();
            void setJogador1();
            void setJogador2();
            void executar();
    };
}