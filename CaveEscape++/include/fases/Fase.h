#pragma once

#include <string>
#include "../gerenciadores/Gerenciador_Colisoes.h"
#include "../gerenciadores/Gerenciador_Grafico.h"
#include "../listas/ListaEntidades.h"
#include "../CriadorMapas.h"
#include "../entidades/Entidade.h"
#include "../entidades/personagens/Mago.h"

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
            void verificaVitoria();
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
            void criarProjetil(Entidades::Personagens::Inimigo* inim, const char* txt, const float tamXX, const float tamYY, const float xx, const float yy, const int sentMovX, const float vel);
            void executar(float dt);
            void desenhar(sf::RenderWindow& janela);
            virtual void salvar();
    };
}