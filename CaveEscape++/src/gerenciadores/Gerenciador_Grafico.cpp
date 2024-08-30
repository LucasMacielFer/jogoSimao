#include "../../include/gerenciadores/Gerenciador_Grafico.h"
#include "../../include/Ente.h"

namespace Gerenciadores
{
    // Inicialização de pInstancia como NULL
    Gerenciador_Grafico* Gerenciador_Grafico::pInstancia(NULL);

    Gerenciador_Grafico::Gerenciador_Grafico():
    janela(sf::VideoMode(tamanhoJanela.x, tamanhoJanela.y), "Jogo"),
    tamanhoJanela(sf::Vector2f(TAM_JANELA_X, TAM_JANELA_Y))
    {
        camera = janela.getDefaultView();
        janela.setFramerateLimit(60);
        janela.setView(camera);
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

    void Gerenciador_Grafico::moveCamera(const float x)
    {
        camera.setCenter(x, tamanhoJanela.y/2.0f);
        janela.setView(camera);
    }

    const sf::View Gerenciador_Grafico::getCamera() const
    {
        return camera;
    }

    const bool Gerenciador_Grafico::janelaAberta() const
    {
        return janela.isOpen();
    }

    sf::Texture* Gerenciador_Grafico::carregarTextura(const char* caminhoTextura)
    {
        if(mapaTexturas.count(caminhoTextura) <= 0)
        {
            sf::Texture* textura = new sf::Texture();
            if(!textura->loadFromFile(caminhoTextura))
            {
                std::cout<<"Erro ao carregar textura " << caminhoTextura << std::endl;
                exit(1);
            }
            mapaTexturas.insert(std::make_pair(caminhoTextura, textura));
            return textura;
        }
        else
        {
            return mapaTexturas[caminhoTextura];
        }
    }

    const sf::Vector2f Gerenciador_Grafico::getTamJanela() const
    {
        return tamanhoJanela;
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