#ifndef ARMAZEM_HPP
#define ARMAZEM_HPP

#include "pilhaEncadeada.hpp"
#include "pacote.hpp"

/*  
    USA INFORMAÇÕES DE GRAFO (ROTA) PARA MOVIMENTAR PACOTES
 */

class Armazem {
public:
    Armazem(); 
    Armazem(int id);
    ~Armazem();
    
    // Método para obter a pilha associada ao vizinho (destino específico)
    PilhaEncadeada& getSecaoDestino(int vizinhoId);

    // Insere um pacote na seção apropriada (associado a um vizinho)
    void inserePacote(Pacote p);

    // Define o ID do armazém
    void setId(int id);

    // Retorna o ID do armazém
    int getId();

    // Remove um pacote específico de uma seção de destino (vizinho)
    bool removerPacote(int vizinhoId, int pacoteId);

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
    int* vizinhos;  // Vetor de IDs de vizinhos
    PilhaEncadeada* pilhasVizinhos;  // Vetor de pilhas associadas aos vizinhos
    int numVizinhos;  // Número de vizinhos
};

#endif
