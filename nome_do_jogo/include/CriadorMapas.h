#pragma once

#include <fstream>
#include "nlohmann/json.hpp"
#include "listas/ListaEntidades.h"
#include "entidades/obstaculos/Plataforma.h"
#include "entidades/obstaculos/Gosma.h"
#include "entidades/obstaculos/Espinho.h"

// O carregamento de mapas através de tilemaps no formato JSON foi implementado
// Baseado nos códigos da equipe do PETECO. Disponível em: https://github.com/Nixxye/Project-Simas-PETECO/tree/main/Tilemap

class CriadorMapas
{
    private:
        nlohmann::json mapa;

    public:
        CriadorMapas(std::string tilemap);
        ~CriadorMapas();
        void carregarMapa(std::string tilemap);
        void criarMapa(Listas::ListaEntidades* lista, int nOF, const int nOM, const int nOD, const int nIF, const int nID, const int nIC);
        Entidades::Entidade* criarEntidade(const int posX, const int posY, const int tipo);
};