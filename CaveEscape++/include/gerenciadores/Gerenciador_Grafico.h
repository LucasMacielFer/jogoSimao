#pragma once
#include <SFML/Graphics.hpp>

#define TAM_JANELA_X 1024
#define TAM_JANELA_Y 800

class Ente;

namespace Gerenciadores
{
    class Gerenciador_Grafico
    {
    private:
        // Ponteiro estático para instância do gerenciador - Padrão de projeto Singleton
        static Gerenciador_Grafico* pInstancia;
        const sf::Vector2f tamanhoJanela;
        sf::RenderWindow janela;
        sf::View camera;
        std::map<const char*, sf::Texture*> mapaTexturas;

    private:
        // Construtora privada, em conformidade com o padrão de projeto Singleton
        Gerenciador_Grafico();

    public:
        ~Gerenciador_Grafico();
        void fecharJanela();
        void mostrarJanela();
        void limparJanela();
        void desenhaEnte(Ente* pE);
        sf::RenderWindow& getJanela();
        void moveCamera(const float x);
        const bool janelaAberta() const;
        sf::Texture* carregarTextura(const char* caminhoTextura);
        const sf::Vector2f getTamJanela() const;
        static Gerenciador_Grafico* getInstancia();
    };
}