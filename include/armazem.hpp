#ifndef ARMAZEM_HPP
#define ARMAZEM_HPP

#include "pilhaEncadeada.hpp"
#include "pacote.hpp"

/*  
    USA INFORMAÇÕES DE GRAFO (ROTA) PARA MOVIMENTAR PACOTES
 */

 class Pacote;

class Armazem {
public:
    Armazem(); 
    Armazem(int id);
    ~Armazem();
    
    // Método para obter a pilha associada ao armazem vizinho
    PilhaEncadeada& getSecaoDestino(int destinoId);
    PilhaEncadeada& getSecaoDestinoTransporte(int vizinhoId);

    // Insere um pacote na seção apropriada (associado a um vizinho)
    void inserePacote(Pacote Pac);
    void inserePacoteTransporte(Pacote p, int vizinhoId);
    // Define o ID do armazém
    void setId(int id);

    // Retorna o ID do armazém
    int getId();

    // Remove um pacote específico de uma seção de destino (vizinho)
    void removerPacote(int vizinhoId, int pacoteId);

    // Verifica se o armazém tem pacotes para um vizinho específico
    bool temPacotes(int vizinhoId);

    // Retorna o número de pacotes para um vizinho específico
    int quantidadePacotes(int vizinhoId);

    // Limpa todos os pacotes de um destino (vizinho)
    void esvaziarSecao(int vizinhoId);

    // Exibe os pacotes de uma seção (vizinho)
    void visualizarPacotes(int vizinhoId);

    // Adiciona um vizinho ao armazém
    void adicionarVizinho(int idVizinho);

    void imprimeVizinhos() const;

private:
    int id;
    int numVizinhos;  // Número de vizinhos
    int* vizinhos;  // Vetor de IDs de vizinhos
    PilhaEncadeada* pilhasPacotes;  // Vetor de pilhas de id's de pacotes
    PilhaEncadeada* pilhasTransporte; //Vetor de pilhas de id's de pacotes em transporte
    friend class Escalonador;
};

#endif
