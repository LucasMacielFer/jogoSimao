#include "gerenciadores/Gerenciador_Colisoes.h"
//#include "auxiliares/ListaEntidades.h"

namespace Gerenciadores
{
    Gerenciador_Colisoes::Gerenciador_Colisoes() : listaPersonagens(NULL), listaObstaculos(NULL)
    {

    }

    Gerenciador_Colisoes::Gerenciador_Colisoes(Listas::ListaEntidades* lPersonagens, Listas::ListaEntidades* lObstaculos):
    listaPersonagens(lPersonagens), listaObstaculos(lObstaculos)
    {

    }

    Gerenciador_Colisoes::~Gerenciador_Colisoes()
    {
        listaPersonagens = NULL;
        listaObstaculos = NULL;
    }

    const sf::Vector2f Gerenciador_Colisoes::calculadora_colisoes(Entidades::Entidade* entidade1, Entidades::Entidade* entidade2)
    {
        if(entidade1 && entidade2)
        {
            sf::Vector2f posicao1 = entidade1->getPosicao();
            sf::Vector2f posicao2 = entidade2->getPosicao();

            sf::Vector2f tamanho1 = entidade1->getTamanho();
            sf::Vector2f tamanho2 = entidade2->getTamanho();

            //Calculo da distância relativa entre os centros de cada entidade.
            float dist_centro_em_x = fabs((posicao1.x + tamanho1.x/2.0f) - (posicao2.x + tamanho2.x/2.0f));
            float dist_centro_em_y = fabs((posicao1.y + tamanho1.y/2.0f) - (posicao2.y + tamanho2.y/2.0f));

            //Um vetor que indica que ocorre colisão se os dois parâmetros são negativos.
            return sf::Vector2f(dist_centro_em_x - ((tamanho1.x/2.0f) + (tamanho2.x/2.0f)), dist_centro_em_y - ((tamanho1.y/2.0f) + (tamanho2.y/2.0f)) );
        }
        else
        {
            std::cout << "Ponteiros nulos comparados na calculadora" << std::endl;
            exit(1);
        }
    }

    void Gerenciador_Colisoes::executar()
    {

        //Percorre os personagens e verifica colisão com outros personagens.
        if(listaPersonagens)
        {
            for(int i = 0; i < listaPersonagens->tamanho(); i++)
            {
                Entidades::Entidade* entidade1 = listaPersonagens->operator[](i);

                for(int j = i + 1; j < listaPersonagens->tamanho(); j++)
                {
                    Entidades::Entidade* entidade2 = listaPersonagens->operator[](j);
                    sf::Vector2f distancia_colisao = calculadora_colisoes(entidade1, entidade2);

                    if(distancia_colisao.x < 0.0f && distancia_colisao.y < 0.0f)
                    {
                        //entidade1->colidir(entidade2, distancia_colisao);, metodo ainda precisa ser definido na classe entidade
                    }
                }
            }
        }
        //Percorre os personagens e verifica colisão com algum objeto.

        if(listaPersonagens && listaObstaculos)
        {
            for(int k = 0; k < listaPersonagens->tamanho(); k++)
            {
                Entidades::Entidade* entidade1 = listaPersonagens->operator[](k);

                for(int l = 0; l < listaObstaculos->tamanho(); l++)
                {
                    Entidades::Entidade* entidade2 = listaObstaculos->operator[](l);
                    sf::Vector2f distancia_colisao = calculadora_colisoes(entidade1, entidade2);

                    if(distancia_colisao.x < 0.0f && distancia_colisao.y < 0.0f)
                    {
                        //entidade1->colidir(entidade2, distancia_colisao);, metodo ainda precisa ser definido na classe entidade
                    }
                }
            }
        }

    }
}