#ifndef ARMAZEM_HPP
#define ARMAZEM_HPP

#include "pacote.hpp"
#include "graph.hpp"
#include "fila.hpp"
#include "listaEncadeada.hpp"
#include "evento.hpp"

class Armazem {
public:
    Armazem();
    ~Armazem();

    // Método para adicionar pacotes na seção de destino
    void adicionarPacoteDestino(int destino, const Pacote& pacote);
    
    // Método para acessar a fila de pacotes de um destino específico
    Fila<Pacote>& getSecaoDestino(int destino);

private:
    // Lista encadeada para associar destinos a filas de pacotes
    struct DestinoSecao {
        int destino;    //Destino (número do vértice)
        Fila<Pacote> secao;
    };

    // Lista encadeada que vai armazenar as seções para cada destino
    ListaEncadeada<DestinoSecao> listaDestinoSecao;
    
    ListaEncadeada<Evento> listaAlteracoes; // evento de armazenamento
};

#endif
