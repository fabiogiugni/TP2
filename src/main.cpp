#include "pacote.hpp"
#include "armazem.hpp"
#include "transporte.hpp"
#include "escalonador.hpp"
#include <fstream>

int main(int argc,char *argv[]){

    int tempo = 0;

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


    Grafo mapaArm;

    int numeroArmazens = 0;
    arquivo>>numeroArmazens;

    for(int i = 0; i < numeroArmazens; i++){
        mapaArm.InsereVertice();
    }
    
    for(int i = 0; i < numeroArmazens; i++){
        for(int j = 0; j < numeroArmazens; j++){
            int temAresta = 0;
            arquivo>>temAresta;
            if(temAresta == 1){
                mapaArm.InsereAresta(i,j);
            }
        }
    }

    
    mapaArm.ImprimeVizinhos();




    Transporte transp(capacidadeTransporte, latenciaTransporte, intervaloTransportes, mapaArm);

    int numeroPacotes = 0;
    arquivo>>numeroPacotes;
    return 0;
    
    for(int i = 0; i < numeroPacotes; i++){
        int tempo = 0;
        std::cin>>tempo;
        std::string pac;
        std::cin >> pac;  // Lê e ignora a palavra "pac"
        int id = 0;
        std::string org;
        std::cin >> org;  // Lê e ignora a palavra "org"
        int orgn = 0;
        std::cin>>orgn;
        std::string dst;
        std::cin >> dst;  // Lê e ignora a palavra "dst"
        int dest = 0;
        std::cin>>dest;

        Pacote* p = new Pacote(tempo, id, orgn, dest);  // Criando o pacote

        // Calculando a rota do pacote (usando o método `calculaRota` da classe Transporte)
        transp.inserirPacoteOrigem(p);

    }
    std::cout<<"fim"<<std::endl;
    return 0;
}