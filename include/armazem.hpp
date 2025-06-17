#ifndef ARMAZEM_HPP
#define ARMAZEM_HPP

#include "pacote.hpp"
#include "pilhaEncadeada.hpp"
#include "fila.hpp"
#include "listaEncadeada.hpp"

class Pacote;

class Armazem {
public:
    Armazem(); 
    Armazem(int id);
    ~Armazem();
    
    PilhaEncadeada<Pacote>& getSecaoDestino(int destino);
    void inserePacote(Pacote p);
    void setId(int id);
    int getId();
    bool removerPacote(int destino, int pacoteId);

    friend std::ostream& operator<<(std::ostream& os, const Armazem& armazem);
private:
    int id;
    struct DestinoSecao {
        int destino;
        PilhaEncadeada<Pacote> secao;  // Agora PilhaEncadeada é reconhecida
    };
    ListaEncadeada<DestinoSecao> listaDestinoSecao;

};

#endif
