#include "../../include/fases/Fase.h"

namespace Fases
{
    const int Fase::idClasse(4);
    Gerenciadores::Gerenciador_Colisoes* Fase::pGColisoes(Gerenciadores::Gerenciador_Colisoes::getInstancia());

    void Fase::gerenciarColisoes()
    {
        pGColisoes->executar();
    }

    void Fase::executarEntidades(float dt)
    {
        // Percorrer a lista executando entidade por entidade
    }

    void Fase::criarMapa()
    {
        CriadorMapas* gerador = new CriadorMapas(caminhoTilemap);
        if(gerador)
        {
            gerador->criarMapa(lEntidades, nOFaceis, nOMedios, nODificeis, nIFaceis, nIDificeis, nIChefoes);
            delete gerador;
            gerador = NULL;
        }
    }

    Fase::Fase(std::string tilemap, const int nOF, const int nOM, const int nOD, const int nIF, const int nID, const int nIC):
    Ente(idClasse),
    caminhoTilemap(tilemap),
    jog1(NULL),
    jog2(NULL),
    nOFaceis(nOF),
    nOMedios(nOM),
    nODificeis(nOD),
    nIFaceis(nIF),
    nIDificeis(nID),
    nIChefoes(nIC)
    {
    }

    Fase::Fase():
    Ente(-1),
    caminhoTilemap(""),
    jog1(NULL),
    jog2(NULL),
    nOFaceis(0),
    nOMedios(0),
    nODificeis(0),
    nIFaceis(0),
    nIDificeis(0),
    nIChefoes(0)
    {
    }

    Fase::~Fase()
    {
        // Salvar?
        // Destruir entidade por entidade
    }

    // Será chamada pelo gerenciador grafico!
    void Fase::desenhar(sf::RenderWindow& janela)
    {
        jog1->desenhar(janela);
        jog2->desenhar(janela);
        // Percorre a lista desenhando tudo
    }

    void Fase::setJogador1(Entidades::Personagens::Jogador* jog)
    {
        jog1 = jog;
    }

    void Fase::setJogador2(Entidades::Personagens::Jogador* jog)
    {
        jog2 = jog;
    }

    void Fase::executar(float dt)
    {
        gerenciarColisoes();
        executarEntidades(dt);
    }

    void Fase::salvar()
    {
        // Logica de salvamento
    }
}