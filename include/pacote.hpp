#ifndef PACOTE_HPP
#define PACOTE_HPP

#include "listaEncadeada.hpp"
#include "armazem.hpp"


/*  
    ARMAZENA INFORMAÇÕES SOBRE OS PACOTES, ACHO Q CLASSE EVENTO VAI DE RALO
 */

class Pacote {
    public:
        Pacote();
        Pacote(int tempo, int ident, int org, int dest);
        ~Pacote();
        int getOrigem();
        int getId();
        int getDestino();
        int getChavePacote();
        void setRota(ListaEncadeada* novaRota);
        void avancarRota();  // Avança para o próximo armazém
        int getArmazemAtual() const;    //Acessa o armazém atual
        int getProximoArmazem() const;  // Acessa o próximo armazém (sem remover)
        bool chegouAoDestino() const;       // Verifica se a rota acabou
        void imprimirPacote() const;  // Imprime as informações do pacote

    private:
        int chavePacote;
        int tempo; //6 digitos
        int id; //6digitos
        int armazemOrigem;
        int armazemDestino;
        int tipoTransporte; // 1- armazenamento 2- transporte
        /* 
        1- não postado 
        2- chegada escalonada(já anotada) a um armazem 
        3- chegou a um armazem mas não foi add 
        4- armazenado em armazém 
        5- alocado para transporte 
        6- entregue
        */
        ListaEncadeada* rota;
    friend class Armazem;
    friend class Grafo;
    friend class Escalonador;
};

#endif