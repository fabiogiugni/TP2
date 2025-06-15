#ifndef ARMAZEM_HPP
#define ARMAZEM_HPP

#include "pacote.hpp"
#include "graph.hpp"
#include "fila.hpp"
#include "pilhaEncadeada.hpp"
#include "listaEncadeada.hpp"
#include "evento.hpp"

class Armazem {
public:
    Armazem(); 
    Armazem(int id);
    ~Armazem();
    
    // Método para acessar a fila de pacotes de um destino específico
    PilhaEncadeada& getSecaoDestino(int destino);
    void inserePacote(Pacote p);
    int getId();
    bool removerPacote(int destino, int pacoteId);

private:
    int id;
    // Lista encadeada para associar destinos a filas de pacotes
    struct DestinoSecao {
        int destino;    //Destino (número do vértice)
        PilhaEncadeada secao;
    };

    // Lista encadeada que vai armazenar as seções para cada destino
    ListaEncadeada<DestinoSecao> listaDestinoSecao;
};

#endif
