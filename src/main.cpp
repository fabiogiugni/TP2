#include "pacote.hpp"
#include "armazem.hpp"
#include "transporte.hpp"
#include "escalonador.hpp"
#include <fstream>

int main(int argc,char *argv[]){

    Escalonador escal;
    Grafo mapaArmazens;

    // Cria um objeto ifstream para abrir o arquivo
    std::ifstream arquivo("exemplo.txt");

    // Verifica se o arquivo foi aberto corretamente
    if (!arquivo.is_open()) {
        std::cerr << "Erro ao abrir o arquivo!" << std::endl;
        return 1;  // Sai do programa se não conseguir abrir o arquivo
    }

    int capacidadeTransporte = 0;
    arquivo>>capacidadeTransporte;
    int latenciaTransporte = 0;
    arquivo>>latenciaTransporte;
    int intervaloTransportes = 0;
    arquivo>>intervaloTransportes;
    int custoRemocao = 0;
    arquivo>>custoRemocao;
    int numeroArmazens = 0;
    arquivo>>numeroArmazens;

    for(int i = 0; i < numeroArmazens; i++){
        mapaArmazens.InsereVertice();
        for(int j = 0; j < numeroArmazens; j++){
            int temAresta = 0;
            arquivo>>temAresta;
            if(!temAresta){
                mapaArmazens.InsereAresta(i,j);
            }
        }
    }
    
    /*
    1- Recebe grafo de armazens e postagem de pacotes
    2- Pacotes a serem enviados
    3- Inicialização do relojo, de tudo...
    */
}