#include "../../include/gerenciadores/GerenciadorGrafico.h"
#include "../../include/Ente.h"

namespace Gerenciadores
{
    // Inicialização de pInstancia como NULL
    GerenciadorGrafico* GerenciadorGrafico::pInstancia(NULL);

    GerenciadorGrafico::GerenciadorGrafico():
    janela(sf::VideoMode(tamanhoJanela.x, tamanhoJanela.y), "Jogo"),
    tamanhoJanela(sf::Vector2f(TAM_JANELA_X, TAM_JANELA_Y))
    {
        camera = janela.getDefaultView();
        janela.setFramerateLimit(60);
        janela.setView(camera);
    }

    GerenciadorGrafico::~GerenciadorGrafico()
    {
    }

    void GerenciadorGrafico::fecharJanela()
    {
        janela.close();
    }

    void GerenciadorGrafico::limparJanela()
    {
        janela.clear();
    }

    void GerenciadorGrafico::mostrarJanela()
    {
        janela.display();
    }

    void GerenciadorGrafico::desenhaEnte(Ente* pE)
    {
        pE->desenhar(janela);
    }

    sf::RenderWindow& GerenciadorGrafico::getJanela()
    {
        return janela;
    }

    void GerenciadorGrafico::moveCamera(const float x)
    {
        camera.setCenter(x, tamanhoJanela.y/2.0f);
        janela.setView(camera);
    }

    const sf::View GerenciadorGrafico::getCamera() const
    {
        return camera;
    }

    const bool GerenciadorGrafico::janelaAberta() const
    {
        return janela.isOpen();
    }

    sf::Texture* GerenciadorGrafico::carregarTextura(const char* caminhoTextura)
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

    const sf::Vector2f GerenciadorGrafico::getTamJanela() const
    {
        return tamanhoJanela;
    }

    // Execução efetiva do padrão de projeto singleton
    GerenciadorGrafico* GerenciadorGrafico::getInstancia()
    {
        if(!pInstancia)
        {
            pInstancia = new GerenciadorGrafico();
        }
        return pInstancia;
    } 
}