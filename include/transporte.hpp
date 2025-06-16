#ifndef TRANSPORTE_HPP
#define TRANSPORTE_HPP

#include "pacote.hpp"
#include "graph.hpp"
#include "evento.hpp"

class Transporte{
    public:
        Transporte(int capacidadeTransporte, int latenciaTransporte, int intervaloTransporte, Grafo mapa);
        ~Transporte();

        void insereVertice();

        // Método para adicionar pacotes na seção de origem
        void inserirPacoteOrigem(Pacote* p);
        void avancarPacote(Pacote* p);
        void processarChegada(Evento& evento);

        
    private:

        void calculaRota(Pacote* p);
        
        int capacidadeTransporte;
        int latenciaTransporte;
        int intervaloTransporte;

        Grafo mapaArmazens;

        friend class Escalonador;
};

#endif