#pragma once

#include <string>
#include "../../texto/ElementoTexto.h"
#include "../../gerenciadores/GerenciadorColisoes.h"
#include "../../gerenciadores/GerenciadorGrafico.h"
#include "../../gerenciadores/GerenciadorEventos.h"
#include "../../listas/ListaEntidades.h"
#include "../../CriadorMapas.h"
#include "../../entidades/Entidade.h"
#include "../../entidades/personagens/Inimigo.h"
#include "../../observadores/ObservadorJogador.h"
#include "../Estado.h"

namespace Observadores
{
    class ObservadorFase;
}

namespace Estados
{
    namespace Fases
    {
        class Fase : public Ente, public Estado
        {
            protected:
                static Gerenciadores::GerenciadorColisoes* pGColisoes;
                static Gerenciadores::GerenciadorEventos* pGEventos;
                CriadorMapas* criadorDeMapas;
                int tamMapa;
                Entidades::Personagens::Jogador* jog1;
                Entidades::Personagens::Jogador* jog2;
                Listas::ListaEntidades lEntidades;
                std::string caminhoTilemap;
                Texto::ElementoTexto* vidasJ1;
                Texto::ElementoTexto* vidasJ2;
                Texto::ElementoTexto* pontosJ1;
                Texto::ElementoTexto* pontosJ2; 
                Observadores::ObservadorFase* pObs;

            private:
                void constroiHud();
                void verificaJogsVivos();
                void verificaVitoria();
                void gerenciarProjeteis();
                void gerenciarColisoes();
                void executarEntidades(float dt);
                void setJogador1(Entidades::Personagens::Jogador* jog);
                void setJogador2(Entidades::Personagens::Jogador* jog);
                const float calculaCentroCamera();

            protected:
                void aleatorizaOcorrencias(bool* ocorrencias, const int max);
                void inicializaColisoes();
                void criarChao();
                void criarJogadores(const int numJogs);
                // CriarPlataformas é virtual pois a fase 2 tem plataformas com espinhos, que são SEMPRE geradas.
                // A solução geral para criar plataformas (utilizada pela fase 1) está implementada nesta classe.
                virtual void criarPlataformas(bool* plats, const int max);
                void criarEsqueletos(bool* esqs, const int max);
                virtual void vencer() = 0;

            public:
                Fase(std::string tilemap, idEstados id, const int numJogs);
                Fase();
                virtual ~Fase();
                void criarProjetil(Entidades::Personagens::Inimigo* inim, const char* txt, const float tamXX, const float tamYY, const float xx, const float yy, const int sentMovX, const float vel);
                void executar(float dt);
                void desenhar(sf::RenderWindow& janela);
                void setAtivo(const bool at);
                virtual void pausar();
                virtual void salvarJogada(const char* caminhoSalvamento);
        };
    }
}