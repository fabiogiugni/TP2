#ifndef PACOTE_HPP
#define PACOTE_HPP

#include "listaEncadeada.hpp"
#include "armazem.hpp"


/*  
    ARMAZENA INFORMAÇÕES SOBRE OS PACOTES, ACHO Q CLASSE EVENTO VAI DE RALO
 */

class Armazem;

class Pacote {
    public:
        Pacote();
        Pacote(int tempo, int ident, int org, int dest);
        ~Pacote();
        int getOrigem();
        int getId();
        int getDestino();
        void setRota(ListaEncadeada novaRota);
        void avancarRota();  // Avança para o próximo armazém
        Armazem* getProximoArmazem() const;  // Acessa o próximo armazém (sem remover)
        bool chegouAoDestino() const;       // Verifica se a rota acabou

    private:
        int tempoChegada;
        int id;
        int armazemOrigem;
        int armazemDestino;
        int estadoPacote;
        /* 
        1- não postado 
        2- chegada escalonada(já anotada) a um armazem 
        3- chegou a um armazem mas não foi add 
        4- armazenado em armazém 
        5- alocado para transporte 
        6- entregue
        */
        ListaEncadeada rota;
    friend class Armazem;
    friend class Grafo;
    friend class Transporte;
};

#endif