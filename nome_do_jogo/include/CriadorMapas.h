#pragma once

#include <fstream>
#include "nlohmann/json.hpp"
#include "listas/ListaEntidades.h"
#include "entidades/obstaculos/Plataforma.h"
#include "entidades/obstaculos/Gosma.h"
#include "entidades/obstaculos/Espinho.h"
#include "entidades/personagens/Lobisomem.h"
#include "entidades/personagens/Esqueleto.h"

#define CODIGO_PLATAFORMA 26
#define CODIGO_GOSMA 50
#define CODIGO_ESPINHO 47
#define CODIGO_CHAO 28
#define CODIGO_LOBISOMEM 59
#define CODIGO_ESQUELETO 53
#define CODIGO_MAGO -1


// O carregamento de mapas através de tilemaps no formato JSON foi implementado
// Baseado nos códigos da equipe do PETECO. Disponível em: https://github.com/Nixxye/Project-Simas-PETECO/tree/main/Tilemap

class CriadorMapas
{
    private:
        nlohmann::json mapa;
        int tamMapa;

    private:
        void carregarMapa(std::string tilemap);

    public:
        CriadorMapas(std::string tilemap);
        ~CriadorMapas(); 
        void criarChao(Listas::ListaEntidades* lista);
        void criarTipo(Listas::ListaEntidades* lista, const int idMapa, const bool* ocorrencias, const int max);
        const int getTamMapa() const;
        Entidades::Entidade* criarEntidade(const int posX, const int posY, const int tipo);
};