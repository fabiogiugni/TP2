#include "graph.hpp"
#include <cstring>

int main(int argc,char *argv[]){
    const char *operacao = argv[1];

    int numVertices;
    std::cin >> numVertices;
    Grafo grafo;

    for (int i = 0; i < numVertices; i++)
    {
        grafo.InsereVertice();
    }

    for (int i = 0; i < numVertices; i++)
    {
        int numVizinhos;
        std::cin >> numVizinhos;
        for (int j = 0; j < numVizinhos; j++)
        {
            int vizinho;
            std::cin >> vizinho;
            grafo.InsereAresta(i, vizinho);
        }
    }

    if (strcmp(operacao, "-d") == 0)
    {
        std::cout << grafo.QuantidadeVertices() << "\n";
        std::cout << grafo.QuantidadeArestas() << "\n";
        std::cout << grafo.GrauMinimo() << "\n";
        std::cout << grafo.GrauMaximo() << "\n";
    }
    else if (strcmp(operacao, "-n") == 0)
    {
        for (int v = 0; v < grafo.QuantidadeVertices(); v++)
        {
            grafo.ImprimeVizinhos(v);
        }
    }
    else if (strcmp(operacao, "-k") == 0)
    {
        int qtdVertices = grafo.QuantidadeVertices();
        int qtdArestas = grafo.QuantidadeArestas();
        int formulaCompleto = ((qtdVertices * (qtdVertices - 1)) / 2);

        bool ehCompleto = false;
        if (qtdArestas == formulaCompleto)
        {
            ehCompleto = true;
        }

        std::cout << ehCompleto << "\n";
    }

    return 0;
}