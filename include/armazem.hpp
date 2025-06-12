#ifndef ARMAZEM_HPP
#define ARMAZEM_HPP

#include "pacote.hpp"
#include "graph.hpp"
#include "fila.hpp"
#include "listaEncadeada.hpp"
#include "evento.hpp"

class Armazem {
public:
    Armazem(int id);
    ~Armazem();
    
    // Método para acessar a fila de pacotes de um destino específico
    Fila<Pacote>& getSecaoDestino(int destino);
    void inserePacote(Pacote p);
    int getId();

private:
    int id;
    // Lista encadeada para associar destinos a filas de pacotes
    struct DestinoSecao {
        int destino;    //Destino (número do vértice)
        Fila<Pacote> secao;
    };

    // Lista encadeada que vai armazenar as seções para cada destino
    ListaEncadeada<DestinoSecao> listaDestinoSecao;
};

#endif
