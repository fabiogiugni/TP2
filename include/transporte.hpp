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
        void adicionarPacoteOrigem(Pacote* pacote);
        void avancarPacote(Pacote* p);
        void calculaRota(Pacote* p);
        
    private:
        struct Alteracao {
            int tempo;          // instante da alteração
            int novoEstado;     // novo estado do pacote
        };
        
        int capacidadeTransporte;
        int latenciaTransporte;
        int intervaloTransporte;

        Grafo mapaArmazens;

        ListaEncadeada<Alteracao> listaTransportes; //evento de transporte
};

#endif