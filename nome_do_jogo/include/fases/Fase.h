#pragma once

#include <string>
#include "../gerenciadores/Gerenciador_Colisoes.h"
#include "../gerenciadores/Gerenciador_Grafico.h"
#include "../listas/ListaEntidades.h"
#include "../CriadorMapas.h"

#include "../entidades/personagens/Mago.h"

#define CODIGO_PLATAFORMA 26
#define CODIGO_GOSMA 50
#define CODIGO_ESPINHO 47
#define CODIGO_CHAO 28
#define CODIGO_LOBISOMEM 59
#define CODIGO_ESQUELETO 53
#define CODIGO_MAGO -1

namespace Fases
{
    class Fase : public Ente
    {
        protected:
            static const int idClasse;
            static Gerenciadores::Gerenciador_Colisoes* pGColisoes;
            CriadorMapas* criadorDeMapas;
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
            void aleatorizaOcorrencias(bool* ocorrencias, const int max);
            void inicializaColisoes();
            void criarChao();
            void criarPlataformas(bool* plats, const int max);
            void criarEsqueletos(bool* esqs, const int max);

        public:
            Fase(std::string tilemap);
            Fase();
            virtual ~Fase();
            void setJogador1(Entidades::Personagens::Jogador* jog);
            void setJogador2(Entidades::Personagens::Jogador* jog);
            void executar(float dt);
            void desenhar(sf::RenderWindow& janela);
            virtual void salvar();
    };
}