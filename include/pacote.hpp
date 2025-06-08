#ifndef PACOTE_HPP
#define PACOTE_HPP

#include "listaEncadeada.hpp"
#include "armazem.hpp"

class Pacote {
    public:
        Pacote();
        ~Pacote();

        void registrarAlteracao(int tempo, int novoEstado, const std::string& descricao);

    private:
        int estado;
        /* 
        1- não postado 
        2- chegada escalonada(já anotada) a um armazem 
        3- chegou a um armazem mas não foi add 
        4- armazenado em armazém 
        5- alocado para transporte 
        6- entregue
        */
        ListaEncadeada<int> rota;
        Armazem destino;
    friend class Armazem;
};

#endif