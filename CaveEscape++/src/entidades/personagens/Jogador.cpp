#include "../../../include/entidades/personagens/Jogador.h"
#include "../../../include/entidades/personagens/Inimigo.h"

namespace Entidades
{
    namespace Personagens
    {
        Jogador::Jogador(const char* txt, const char* txt2, const float xx, const float yy):
        Personagem(idEntes::Jogador, txt ,TAM_X_JOGADOR, TAM_Y_JOGADOR, xx, yy, VIDAS_JOGADOR, VEL_MAX_JOGADOR, FORCA_JOGADOR, DURACAO_ESPERA_JOGADOR, DURACAO_ATAQUE_JOGADOR), 
        pontuacao(0),
        texturaAtaque(txt2),
        texturaPadrao(txt)
        {
        }

        Jogador::Jogador():
        Personagem(),
        pontuacao(-1)
        {
        }

        Jogador::~Jogador()
        {
            pontuacao = -1;
        }

        const int Jogador:: getPontuacao() const
        {
            return pontuacao;
        }

        void Jogador:: operator++()
        {
            pontuacao++;
        }

        void Jogador::atacar()
        {
            if(ataqueDisponivel()) 
            {
                atacando = true;
                setTextura(texturaAtaque);
                atualizaTextura();
            }
        }

        void Jogador::danificar(Inimigo* pInim)
        {
            if(pInim)
            {
                pInim->sofrerDano(forca);
                pontuacao+=10;
                atacando = false;
                setTextura(texturaPadrao);
                atualizaTextura();
            }
        }

        void Jogador::aumentarTempoExecucao(const float tempo)
        {
            if(emAtaque())
            {
                //Vai acontecendo enquanto o tempo definido de ataque não conclui.
                tempoEsperando = 0;
                tempoAtacando += tempo;

                //Caso a duração do ataque chegue no limite ele diz que o ataque chegou ao fim.
                if(tempoAtacando > duracaoAtaque)
                {
                    atacando = false;
                    setTextura(texturaPadrao);
                    atualizaTextura();
                }
            }
            else 
            {
                //Vai considerando o tempo desde a finalização do último ataque.
                tempoEsperando += tempo;
                tempoAtacando = 0;
            }
        }

        void Jogador::executar(float dt)
        {
            if(vivo)
            {
                aumentarTempoExecucao(dt);
                aplicaGravidade(dt);
                mover();
            }
        }

        void Jogador::salvar(const char* caminhoSalvamento)
        {
            Personagem::salvar(caminhoSalvamento);
            salvamento += " ";
            salvamento += std::to_string(pontuacao);
            salvamento += " ";
            salvamento += texturaAtaque;

            std::ofstream gravador(caminhoSalvamento, std::ios::app);
            if(!gravador)
            {
                std::cout<<"Erro ao salvar jogador"<<std::endl;
            }
            else
            {
                gravador << salvamento << std::endl;
            }
            gravador.close();
        }

        void Jogador::colidir(Entidade* entAlternativa, sf::Vector2f distancia_colisao)
        {
            if(entAlternativa)
            {
                if(entAlternativa->getId() == idEntes::Inimigo && atacando)
                    danificar(dynamic_cast<Inimigo*>(entAlternativa));
                if(entAlternativa->getId() == idEntes::Obstaculo)
                    regularColisao(entAlternativa, distancia_colisao);
            }
        }

        void Jogador::morrer()
        {
            vivo = false;
        }
    }
}