#include "../include/CriadorMapas.h"

CriadorMapas::CriadorMapas(std::string tilemap)
{
    carregarMapa(tilemap);
}

CriadorMapas::~CriadorMapas()
{
}

void CriadorMapas::carregarMapa(std::string tilemap)
{
    std::ifstream arquivo(tilemap);
    if(!arquivo.is_open()){
        std::cerr << "Erro ao abrir o mapa (caminho mapa)" << std::endl;
        return;
    }

    arquivo >> mapa;
    arquivo.close();
}

const int CriadorMapas::criarMapa(Listas::ListaEntidades* lista, const int nOF, const int nOM, const int nOD, const int nIF, const int nID, const int nIC)
{
    // Pega as informações do mapa
    int sizeTiled = mapa["tilewidth"]; //tamhno do tile
    int heightTiled = mapa["tileheight"];
    int width = mapa["width"];
    int height = mapa["height"]; // altura do mapa
    int posX = 0;
    int posY = 0;
    int indice = 0;

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int tileId = mapa["layers"][0]["data"][indice++];
            if(tileId != 0){
                posX = x * sizeTiled;
                posY = y * heightTiled;
                lista->acrescentarEntidade(criarEntidade(posX, posY, tileId));
            }
        }
    }

    return (width-1)*sizeTiled;
}

Entidades::Entidade* CriadorMapas::criarEntidade(const int posX, const int posY, const int tipo)
{
    switch(tipo)
    {
        case 9:
            return new Entidades::Obstaculos::Plataforma("assets/textures/plat1.png", posX, posY, true);
            break;

        case 7:
            return new Entidades::Obstaculos::Plataforma("assets/textures/plat1.png", posX, posY, false);
            break;

        case 25:
            return new Entidades::Obstaculos::Gosma("assets/textures/gosma.png", 0.3, posX, posY);
            break;

        case 22:
            return new Entidades::Obstaculos::Espinho("assets/textures/espinho.png", 10, posX, posY);
            break;

        default:
            return NULL;
            break;
    }
}