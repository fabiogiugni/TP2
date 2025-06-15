#include "listaAdjacencia.hpp"

// Construtor sem parâmetros
ListaAdjacencia::ListaAdjacencia(){
    listaAdj = nullptr;  // Inicializa a lista de adjacências como null
    numVertices = 0;  // Inicializa o número de vértices como 0
}

// Construtor com número de vértices
ListaAdjacencia::ListaAdjacencia(int vertices) : numVertices(vertices) {
    listaAdj = new ListaEncadeada<Armazem*>[numVertices];  // Aloca a lista de adjacências com ponteiros para Armazem
}

// Destruidor
ListaAdjacencia::~ListaAdjacencia() {
    // Desaloca a memória de todos os armazéns
    for (int i = 0; i < numVertices; ++i) {
        for (No<Armazem*>* atual = listaAdj[i].primeiro; atual != nullptr; atual = atual->prox) {
            delete atual->item;  // Apaga o objeto Armazem alocado dinamicamente
        }
    }
    delete[] listaAdj;  // Desaloca a memória do array de listas de adjacências
}

// Insere aresta entre os vértices v e w
void ListaAdjacencia::insereAresta(int v, int w) {
    Armazem* armazemDestino = new Armazem(w);  // Cria um ponteiro para o armazém com id `w`
    listaAdj[v].insereFinal(armazemDestino);  // Insere o ponteiro do armazém na lista de adjacência de v

    // Para um grafo não direcionado, insere também a aresta inversa
    armazemDestino = new Armazem(v);  // Cria o armazém com id `v`
    listaAdj[w].insereFinal(armazemDestino);  // Insere o ponteiro do armazém na lista de adjacência de w
}

// Retorna o grau mínimo dos vértices
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

// Retorna o grau máximo dos vértices
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

// Imprime os vizinhos (armazéns) de cada vértice
void ListaAdjacencia::imprimeVizinhos() {
    for (int i = 0; i < numVertices; i++) {
        std::cout << "Vértice " << i << ": ";
        
        // Agora imprime o ID do armazém associado
        for (No<Armazem*>* atual = listaAdj[i].primeiro; atual != nullptr; atual = atual->prox) {
            std::cout << "Armazém: " << atual->item->getId() << " ";  // Acessa diretamente o ID do Armazém
        }
        std::cout << std::endl;
    }
}

// Insere um novo vértice
void ListaAdjacencia::insereVertice() {
    // Aloca novo array com tamanho maior
    ListaEncadeada<Armazem*>* novaListaAdj = new ListaEncadeada<Armazem*>[numVertices + 1];

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

void ListaAdjacencia::inserePacote(Pacote* p) {
    // Acesse o armazém correspondente ao nó de origem do pacote
    Armazem* armazemDestino = listaAdj[p->getOrigem()].primeiro->item;
    
    // Insira o pacote no armazém
    armazemDestino->inserePacote(*p);  // Desreferencia o ponteiro para passar o pacote
}
