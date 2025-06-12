#include "listaAdjacencia.hpp"

ListaAdjacencia::ListaAdjacencia(){
    listaAdj = new ListaEncadeada<Armazem>[0];  // Agora aloca uma lista de objetos `Armazem`
}

ListaAdjacencia::ListaAdjacencia(int vertices) : numVertices(vertices){
    listaAdj = new ListaEncadeada<Armazem>[numVertices];  // Aloca lista de armazéns diretamente
}

ListaAdjacencia::~ListaAdjacencia(){
    delete[] listaAdj;  // Não precisa deletar objetos `Armazem` individualmente
}

void ListaAdjacencia::insereAresta(int v, int w) {
    Armazem armazemDestino(w);  // Cria o armazém com o ID `w`
    listaAdj[v].insereFinal(armazemDestino);  // Insere diretamente o objeto `Armazem`
}

int ListaAdjacencia::grauMinimo() {
    int min = listaAdj[0].tamanho;
    int atual = 0;
    for (int i = 1; i < numVertices; ++i) {
        atual = listaAdj[i].tamanho;
        if (min > atual)
            min = atual;
    }
    return min;
}

int ListaAdjacencia::grauMaximo() {
    int max = listaAdj[0].tamanho;
    int atual = 0;
    for (int i = 1; i < numVertices; ++i) {
        atual = listaAdj[i].tamanho;
        if (max < atual)
            max = atual;
    }
    return max;
}

void ListaAdjacencia::imprimeVizinhos() {
    for (int i = 0; i < numVertices; i++) {
        std::cout << "Vértice " << i << ": ";
        
        // Agora imprime o Armazém associado
        for (No<Armazem>* atual = listaAdj[i].primeiro; atual != nullptr; atual = atual->prox) {
            std::cout << "Armazém: " << atual->item.getId() << " ";  // Acessa diretamente o ID do Armazém
        }
        std::cout << std::endl;
    }
}

void ListaAdjacencia::insereVertice() {
    // Aloca novo array com tamanho maior
    ListaEncadeada<Armazem>* novaListaAdj = new ListaEncadeada<Armazem>[numVertices + 1];

    // Copia as listas de adjacência antigas para o novo array
    for (int i = 0; i < numVertices; i++) {
        novaListaAdj[i] = listaAdj[i];
    }

    // Deleta o array antigo
    delete[] listaAdj;

    // Atualiza o ponteiro adjList para o novo array e incrementa numVertices
    listaAdj = novaListaAdj;
    ++numVertices;
}

void ListaAdjacencia::inserePacote()