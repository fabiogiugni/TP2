#ifndef LISTAADJACENCIA_HPP
#define LISTAADJACENCIA_HPP

#include "listaEncadeada.hpp"
#include "pacote.hpp"
#include "armazem.hpp"

class ListaAdjacencia{
public:
    ListaAdjacencia();
    ListaAdjacencia(int vertices);
    ~ListaAdjacencia();
    void insereAresta(int v, int w);
    int grauMinimo();
    int grauMaximo();
    void imprimeVizinhos();
    void insereVertice();  // Modificado para aceitar ponteiro
    void inserePacote(Pacote* p);
    
    // Aqui vamos armazenar um array de ponteiros para armazéns
private:
    int numVertices;
    ListaEncadeada<Armazem*>* listaAdj;  // Lista de ponteiros para armazéns
    
    friend class Fila<Pacote>;
    friend class Grafo;
    friend class Armazem;
    friend class Transporte;
    friend class Escalonador;
};

#endif
