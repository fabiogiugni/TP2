#include "pacote.hpp"
#include "tadsAuxiliares.hpp"
#include "graph.hpp"
#include "armazem.hpp"
#include "escalonador.hpp"
#include <fstream>

int main(int argc,char *argv[]){

    // Cria um objeto ifstream para abrir o arquivo
    if (argc < 2) {
        std::cerr << "Uso: " << argv[0] << " <nome_do_arquivo.wkl>" << std::endl;
        return 1;
    }

    // Usa o argumento da linha de comando como nome do arquivo
    std::ifstream arquivo(argv[1]);

    // Verifica se o arquivo foi aberto corretamente
    if (!arquivo.is_open()) {
        std::cerr << "Erro ao abrir o arquivo!"<< argv[1] << std::endl;
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

    int numeroPacotes = 0;
    arquivo>>numeroPacotes;

    Pacote* vetPac = new Pacote[numeroPacotes]; 
    
    for(int i = 0; i < numeroPacotes; i++){
        int tempo = 0;
        arquivo >> tempo;
        std::string pac;
        arquivo >> pac;  // Lê e ignora a palavra "pac"
        int id = i;
        arquivo >> id; //Aparentemente o id é o i.
        id = i;
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
        p.setRota(&rota);
        vetPac[i] = p;
    }

    int tempoMin = 999999;//achando o tempoMinimo da primeira postagem para ditar os transportes 
    for(int i = 0; i < numeroPacotes; i++){
        if(vetPac[i].getTempoPostagem() < tempoMin){
            tempoMin = vetPac[i].getTempoPostagem();
        }
    }   
    Escalonador escal(capacidadeTransporte, latenciaTransporte, intervaloTransportes, custoRemocao, vetPac, numeroPacotes, vetArm, numeroArmazens);
    escal.processaEventos(tempoMin);
    delete[] vetArm;
    delete[] vetPac;
    return 0;
}