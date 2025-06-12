#include <iostream>
#include "graph.hpp"

Grafo::Grafo() : vertices(0) {}

Grafo::~Grafo() {}

void Grafo::InsereVertice() {
    vertices.insereVertice();  // Insere um novo armazém na lista de adjacência
    // Agora você precisa associar os armazéns aos vértices
}

void Grafo::InsereAresta(int v, int w) {
    vertices.insereAresta(v, w);  // Insere um ponteiro para armazém na lista de adjacência
}

int Grafo::QuantidadeVertices() {
    return vertices.numVertices;
}

int Grafo::QuantidadeArestas() {
    int arestas = 0;
    for (int i = 0; i < vertices.numVertices; ++i) {
        arestas += vertices.listaAdj[i].tamanho;
    }
    return arestas / 2;
}

int Grafo::GrauMinimo() {
    return vertices.grauMinimo();
}

int Grafo::GrauMaximo() {
    return vertices.grauMaximo();
}

void Grafo::ImprimeVizinhos(int v) {
    // Agora os vizinhos são armazéns, então precisamos imprimir as informações dos armazéns
    vertices.listaAdj[v].imprime();
}


ListaEncadeada<Armazem> Grafo::BFS(Pacote& p) {
    int n = vertices.numVertices;

    // Inicializa visitados, distâncias e predecessores
    bool* visitado = new bool[n];
    int* distancia = new int[n];
    int* predecessor = new int[n];  // Vetor para armazenar o caminho (predecessores)

    // Inicializa as variáveis
    for (int i = 0; i < n; ++i) {
        visitado[i] = false;
        distancia[i] = -1;  // -1 significa não alcançado
        predecessor[i] = -1;  // -1 significa que não há predecessor
    }

    // Cria a fila de BFS e adiciona o ponto de início
    Fila<int> fila;
    visitado[p.armazemOrigem] = true;
    distancia[p.armazemOrigem] = 0;
    fila.Enfileira(p.armazemOrigem);  // Enfileira o armazém de origem

    // Realiza a BFS
    while (!fila.vazia()) {
        int v = fila.Desenfileira();  // Remove o vértice da fila
        No<Armazem*>* atual = vertices.listaAdj[v].primeiro;
        
        // Percorre os vizinhos do vértice
        while (atual != nullptr) {
            Armazem* w = atual->item;  // Vértice vizinho
            if (!visitado[w->getId()]) {  // Se o vizinho ainda não foi visitado
                visitado[w->getId()] = true;
                distancia[w->getId()] = distancia[v] + 1;
                predecessor[w->getId()] = v;  // Armazena de onde veio (v)
                fila.Enfileira(w->getId());  // Enfileira o vizinho
            }
            atual = atual->prox;
        }
    }

    // Agora vamos reconstruir a rota do pacote diretamente no atributo `rota` do pacote
    ListaEncadeada<Armazem> rota;
    int destino = p.armazemDestino;  // O destino é o armazém de destino do pacote

    // Se o destino não foi alcançado, não podemos calcular a rota
    if (distancia[destino] == -1) {
        std::cout << "Vértice " << destino << " não é alcançável a partir de " << p.armazemOrigem << std::endl;
        delete[] visitado;
        delete[] distancia;
        delete[] predecessor;
        return rota;  // Retorna uma lista vazia
    }

    // Reconstruir a rota a partir dos predecessores e preencher o atributo `rota` do pacote
    for (int v = destino; v != -1; v = predecessor[v]) {
        // Pega o armazém correspondente ao índice
        Armazem* armazem = vertices.listaAdj[v].primeiro->item;  
        
        // Cria uma cópia do armazém e adiciona à rota
        Armazem armazemCopia(*armazem);  // Cria uma cópia do armazém
        rota.insereInicio(armazemCopia);  // Adiciona a cópia à lista de rota
    }

    // Atualiza diretamente o atributo `rota` do pacote com a rota calculada
    p.rota = rota;

    // Libera a memória dos arrays de controle
    delete[] visitado;
    delete[] distancia;
    delete[] predecessor;

    return rota;  // Retorna a rota calculada (opcional, já que o pacote já tem a rota)
}