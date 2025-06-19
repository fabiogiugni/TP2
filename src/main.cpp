#include "pacote.hpp"
#include "pilhaEncadeada.hpp"
#include "graph.hpp"
#include "armazem.hpp"
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

    int numeroArmazens = 0;
    arquivo>>numeroArmazens;

    Grafo mapaArm;
    Armazem* vetArm = new Armazem[numeroArmazens]; 


    for(int i = 0; i < numeroArmazens; i++){
        vetArm[i].setId(i);
        mapaArm.InsereVertice();
    }
    
    for(int i = 0; i < numeroArmazens; i++){
        for(int j = 0; j < numeroArmazens; j++){
            int temAresta = 0;
            arquivo>>temAresta;
            if(temAresta == 1){
                mapaArm.InsereAresta(i,j);
                vetArm[i].adicionarVizinho(j);
            }
        }
    }

    for(int i = 0; i < numeroArmazens; i++){
        vetArm[i].imprimeVizinhos();
    }

    int numeroPacotes = 0;
    arquivo>>numeroPacotes;

    Pacote* vetPac = new Pacote[numeroPacotes]; 
    
    for(int i = 0; i < numeroPacotes; i++){
        int tempo = 0;
        arquivo >> tempo;
        std::string pac;
        arquivo >> pac;  // Lê e ignora a palavra "pac"
        int id = 0;
        arquivo >> id;
        std::string org;
        arquivo >> org;  // Lê e ignora a palavra "org"
        int orgn = 0;
        arquivo >> orgn;
        std::string dst;
        arquivo >> dst;  // Lê e ignora a palavra "dst"
        int dest = 0;
        arquivo >> dest;

        Pacote p(tempo, id, orgn, dest);  // Criando o pacote
        ListaEncadeada rota = mapaArm.BFS(orgn,dest); //Calcula a rota usando BFS
        rota.imprime();
        p.setRota(&rota);
        vetPac[i] = p;
    }

    for(int i = 0; i < numeroPacotes; i++){
        vetPac[i].imprimirPacote();
    }
    for(int i = 0; i < numeroPacotes; i++){
        vetArm[vetPac[i].getOrigem()].inserePacote(vetPac[i]); //postar pacotes em suas rotas
    }
    vetArm[vetPac[1].getArmazemAtual()].removerPacote(vetPac[1].getProximoArmazem(),1);
    std::cout<<vetPac[1].getProximoArmazem()<<std::endl;
    vetPac[1].avancarRota();
    for(int i = 0; i < numeroArmazens; i++){
        vetArm[i].visualizarPacotes(2);
    }
    std::cout<<"criando escalonador"<<std::endl;
    Escalonador escal(capacidadeTransporte, latenciaTransporte, intervaloTransportes, vetPac, numeroPacotes, vetArm, numeroArmazens);
    


    std::cout<<"fim"<<std::endl;
    return 0;
}