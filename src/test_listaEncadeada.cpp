#include <iostream>
#include "listaEncadeada.hpp" // Inclua a sua implementação aqui

// Classe Armazem simples para testes (com um ID)
class Armazem {
public:
    Armazem(int id) : id(id) {}

    int getId() const {
        return id;
    }

private:
    int id;
};

int main() {
    // Criação da lista encadeada
    ListaEncadeada<Armazem*> lista;

    // Teste 1: Inserindo elementos
    Armazem* armazem1 = new Armazem(1);
    Armazem* armazem2 = new Armazem(2);
    Armazem* armazem3 = new Armazem(3);

    std::cout << "Inserindo armazém 1 na lista..." << std::endl;
    lista.insereFinal(armazem1);
    std::cout << "Inserindo armazém 2 na lista..." << std::endl;
    lista.insereFinal(armazem2);
    std::cout << "Inserindo armazém 3 na lista..." << std::endl;
    lista.insereFinal(armazem3);

    // Teste 2: Imprimindo a lista
    std::cout << "\nLista após inserção dos armazéns:" << std::endl;
    lista.imprime();  // Imprime todos os armazéns na lista

    // Teste 3: Remover um armazém e imprimir novamente
    std::cout << "\nRemovendo o primeiro armazém..." << std::endl;
    lista.removeInicio();  // Remove o primeiro elemento

    std::cout << "\nLista após remoção do primeiro armazém:" << std::endl;
    lista.imprime();  // Imprime novamente

    // Teste 4: Verificando o tamanho da lista
    std::cout << "\nTamanho da lista: " << lista.getTamanho() << std::endl;

    // Teste 5: Remover todos os elementos e verificar a lista vazia
    std::cout << "\nRemovendo todos os armazéns..." << std::endl;
    lista.removeInicio();  // Remove o segundo armazém
    lista.removeInicio();  // Remove o terceiro armazém

    std::cout << "\nLista após remoção de todos os armazéns:" << std::endl;
    lista.imprime();  // Imprime a lista vazia
    std::cout << "Tamanho da lista: " << lista.getTamanho() << std::endl;

    // Limpeza da memória
    delete armazem1;
    delete armazem2;
    delete armazem3;

    return 0;
}
