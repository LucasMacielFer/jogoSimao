#pragma once
#include <SFML/Graphics.hpp>

class Ente;

namespace Gerenciadores
{
    class Gerenciador_Grafico
    {
    private:
        // Ponteiro estático para instância do gerenciador - Padrão de projeto Singleton
        static Gerenciador_Grafico* pInstancia;
        static const sf::Vector2f tamanhoJanela;
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
        static Gerenciador_Grafico* getInstancia();
    };
}