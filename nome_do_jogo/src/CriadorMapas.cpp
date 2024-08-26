#include "../include/CriadorMapas.h"

CriadorMapas::CriadorMapas(std::string tilemap):
contTamanho(0),
contPlataformas(0),
contGosmas(0),
contEspinhos(0),
contLobisomens(0),
contEsqueletos(0)
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

const int CriadorMapas::criarMapa(Listas::ListaEntidades* lista, const bool* plats, const bool* gosmas, const bool* esps, const bool* lobs, const bool* esqs)
{
    // Pega as informações do mapa
    int sizeTiled = mapa["tilewidth"]; //tamhno do tile
    int heightTiled = mapa["tileheight"];
    int width = mapa["width"];
    int height = mapa["height"]; // altura do mapa
    int posX = 0;
    int posY = 0;
    int indice = 0;

    for (int y = 0; y < height; y++) 
    {
        for (int x = 0; x < width; x++) 
        {
            int tileId = mapa["layers"][0]["data"][indice++];
            if(tileId != 0 && tileId != CODIGO_LOBISOMEM && tileId != CODIGO_ESQUELETO)
            {
                posX = x * sizeTiled;
                posY = y * heightTiled;
                lista->acrescentarEntidade(criarEntidade(posX, posY, tileId));

                switch (tileId)
                {
                case CODIGO_PLATAFORMA:
                    if(plats[contPlataformas])
                    {
                        lista->acrescentarEntidade(criarEntidade(posX, posY, tileId));
                    }
                    if(contTamanho++ >= 3)
                    {
                        contTamanho = 0;
                        contPlataformas++;
                    }
                    break;

                case CODIGO_CHAO:
                    lista->acrescentarEntidade(criarEntidade(posX, posY, tileId));
                    break;

                case CODIGO_GOSMA:
                    if(gosmas[contGosmas])
                    {
                        lista->acrescentarEntidade(criarEntidade(posX, posY, tileId));
                    }
                    else
                    {
                        lista->acrescentarEntidade(criarEntidade(posX, posY, CODIGO_CHAO));
                    }
                    if(contTamanho++ >= 3)
                    {
                        contTamanho = 0;
                        contGosmas++;
                    }
                    break;

                case CODIGO_ESPINHO:
                    if(esps[contEspinhos])
                    {
                        lista->acrescentarEntidade(criarEntidade(posX, posY, tileId));
                    }
                    contEspinhos++;
                    break;

                default:
                    break;
                }
            }
        }
    }

    return (width-1)*sizeTiled;
}

Entidades::Entidade* CriadorMapas::criarEntidade(const int posX, const int posY, const int tipo)
{
    switch(tipo)
    {
        case CODIGO_CHAO:
            return new Entidades::Obstaculos::Plataforma("assets/textures/plat1.png", posX, posY, true);
            break;

        case CODIGO_PLATAFORMA:
            return new Entidades::Obstaculos::Plataforma("assets/textures/plat1.png", posX, posY, false);
            break;

        case CODIGO_GOSMA:
            return new Entidades::Obstaculos::Gosma("assets/textures/gosma.png", 0.3, posX, posY);
            break;

        case CODIGO_ESPINHO:
            return new Entidades::Obstaculos::Espinho("assets/textures/espinho.png", 10, posX, posY);
            break;

        default:
            return NULL;
            break;
    }
}