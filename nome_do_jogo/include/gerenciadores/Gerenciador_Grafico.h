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
        const int tamanhoJanela[2];
        sf::RenderWindow janela;

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
        void executar();
        static Gerenciador_Grafico* getInstancia();
    };
}