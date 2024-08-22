#include "../../../include/entidades/personagens/InimigoFacil.h"

namespace Entidades
{
    namespace Personagens
    {
        InimigoFacil::InimigoFacil(std::string txt,const int vd, const float vel, const int danos, const float duraEspera, const float duraAtaque, const float tamXX, const float tamYY, const float xx, const float yy): Inimigo(txt, vd, vel, danos, duraEspera, duraAtaque, tamXX, tamYY, xx, yy)
        {

        }

        InimigoFacil::~InimigoFacil()
        {
            
        }

        /*void InimigoFacil:: executar(float dt) //Estrutura levemente adaptada do código do monitor Matheus Burda. https://github.com/MatheusBurda/Desert.git. Acesso em: 21/08/2024. 
        { 
            Personagem::aumentarTempoExecucao(dt); 
            distancia_jogador = getPosJogador().x - getPosicao().x; 

            if(fabs(distancia_jogador) < ALCANCE_INIMIGO_FACIL) 
             { 
                if(distancia_jogador >= 0) 
                { 
                    if(velocidadeX < 0) 
                    { 
                        velocidadeX ++; 
                    } 
                    else 
                    { 
                        velocidadeX = 0.0f; 
                    } 
                } 
                else 
                { 
                    if(velocidadeX > 0) 
                    { 
                        velocidadeX--; 
                    } 
                    else 
                    { 
                        velocidadeX = 0.0f; 
                    } 
                } 
            }
             if (fabs(distancia_jogador) < ALCANCE_ATAQUE_INIMIGO && Personagem::ataqueDisponivel()) 
             { 
                Personagem* paux = static_cast<Personagem*> (jogadorPerseguido); 
                Personagem::atacar(paux); 
             } 
             
             aplicaGravidade(dt);
             mover(); }
             */

        void InimigoFacil::colidir(Entidade* entAlternativa, sf::Vector2f distancia_colisao)
        {
            if(entAlternativa)
                {
                    //if( entAlternativa->getId() == 0    /*"Jogador"*/ )
                    //{
                    //    Personagem* paux = static_cast<Personagem*>(entAlternativa);
                    //    if(paux && emAtaque())
                    //    {
                    //        Personagem* pAtacado = static_cast <Personagem*> (this);
                    //        paux->atacar(pAtacado);
                    //    }
                    //}
                    //else if(entAlternativa->getId() == 2  /*"Obstaculo"*/)
                    //{
                        regularColisao(entAlternativa, distancia_colisao);
                    //}
                }
        }
    }

}