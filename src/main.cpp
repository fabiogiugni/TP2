#include "pacote.hpp"
#include "armazem.hpp"
#include "transporte.hpp"
#include "escalonador.hpp"
#include <fstream>

int main(int argc,char *argv[]){

    // Cria um objeto ifstream para abrir o arquivo
    std::ifstream arquivo("exemplo.txt");

    // Verifica se o arquivo foi aberto corretamente
    if (!arquivo.is_open()) {
        std::cerr << "Erro ao abrir o arquivo!" << std::endl;
        return 1;  // Sai do programa se não conseguir abrir o arquivo
    }

    int capacitadeTransporte = 0;
    int latenciaTransporte = 0;
    int intervaloTransportes = 0;
    int custoRemocao = 0;
    int numeroArmazens = 0;

    for(int i = 0; i < numeroArmazens; i++){
        
    }
    /*
    1- Recebe grafo de armazens e postagem de pacotes
    2- Pacotes a serem enviados
    3- Inicialização do relojo, de tudo...
    */
}