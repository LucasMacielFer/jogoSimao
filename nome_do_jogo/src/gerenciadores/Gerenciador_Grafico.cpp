#include "../../include/gerenciadores/Gerenciador_Grafico.h"
#include "../../include/Ente.h"

namespace Gerenciadores
{
    // Inicialização de pInstancia como NULL
    Gerenciador_Grafico* Gerenciador_Grafico::pInstancia(NULL);

    Gerenciador_Grafico::Gerenciador_Grafico():
    tamanhoJanela({1000.0f, 800.0f}),
    janela(sf::VideoMode(tamanhoJanela.x, tamanhoJanela.y), "Jogo")
    {
        janela.setFramerateLimit(60);
    }

    Gerenciador_Grafico::~Gerenciador_Grafico()
    {
    }

    void Gerenciador_Grafico::fecharJanela()
    {
        janela.close();
    }

    void Gerenciador_Grafico::limparJanela()
    {
        janela.clear();
    }

    void Gerenciador_Grafico::mostrarJanela()
    {
        janela.display();
    }

    void Gerenciador_Grafico::desenhaEnte(Ente* pE)
    {
        pE->desenhar(janela);
    }

    sf::RenderWindow& Gerenciador_Grafico::getJanela()
    {
        return janela;
    }

    void Gerenciador_Grafico::executar()
    {
    }

    // Execução efetiva do padrão de projeto singleton
    Gerenciador_Grafico* Gerenciador_Grafico::getInstancia()
    {
        if(!pInstancia)
        {
            pInstancia = new Gerenciador_Grafico();
        }
        return pInstancia;
    } 
}