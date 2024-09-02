#pragma once
#include <SFML/Graphics.hpp>

#define TAM_JANELA_X 1024
#define TAM_JANELA_Y 800

class Ente;

namespace Gerenciadores
{
    class GerenciadorGrafico
    {
    private:
        // Ponteiro estático para instância do gerenciador - Padrão de projeto Singleton
        static GerenciadorGrafico* pInstancia;
        const sf::Vector2f tamanhoJanela;
        sf::RenderWindow janela;
        sf::View camera;
        std::map<const char*, sf::Texture*> mapaTexturas;

    private:
        // Construtora privada, em conformidade com o padrão de projeto Singleton
        GerenciadorGrafico();

    public:
        ~GerenciadorGrafico();
        void fecharJanela();
        void mostrarJanela();
        void limparJanela();
        void desenhaEnte(Ente* pE);
        sf::RenderWindow& getJanela();
        void moveCamera(const float x);
        const sf::View getCamera() const;
        const bool janelaAberta() const;
        sf::Texture* carregarTextura(const char* caminhoTextura);
        const sf::Vector2f getTamJanela() const;
        static GerenciadorGrafico* getInstancia();
    };
}