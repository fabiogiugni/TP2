#ifndef GRAPH_HPP
#define GRAPH_HPP

#include "listaAdjacencia.hpp"
#include "fila.hpp"

/*  
    INFORMAÇÕES DAS LIGAÇÕES ENTRE OS ARMAZENS E CALCULA ROTA DO PACOTE POR BFS
 */


class Grafo{
    public:
        Grafo();
        ~Grafo();

        void InsereVertice();
        void InsereAresta(int v, int w);

        int QuantidadeVertices();
        int QuantidadeArestas();

        int GrauMinimo();
        int GrauMaximo();

        void ImprimeVizinhos(int v);
        ListaEncadeada BFS(int origem, int destino);
    private:
        
        /*  Você deve implementar ListaAdjacencia como um TAD que irá armazenar
         * os dados do grafo. Lembrando que este TAD deve ser uma lista 
         * encadeada
         */
        ListaAdjacencia vertices;
};

#endif