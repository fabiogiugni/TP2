#include "transporte.hpp"

Transporte::Transporte(int capacidadeTransporte, int latenciaTransporte, int intervaloTransporte, Grafo mapa): capacidadeTransporte(capacidadeTransporte), 
latenciaTransporte(latenciaTransporte), intervaloTransporte(intervaloTransporte), mapaArmazens(mapa){}

void Transporte::calculaRota(Pacote* p) {
    int origem = p->getOrigem();
    int destino = p->getDestino();

    // Usa o método BFS do grafo para obter a rota entre origem e destino
    ListaEncadeada<Armazem> rotaCalculada = mapaArmazens.BFS(origem, destino);

    // Atualiza o atributo rota do pacote
    p->setRota(rotaCalculada);

    // Mensagem opcional de depuração
    std::cout << "Rota calculada para pacote " << p->getId()
              << " de " << origem << " para " << destino << ":\n";
    rotaCalculada.imprime();
}


void Transporte::avancarPacote(Pacote* p) {
    int origem = p->getOrigem();
    int destino = p->getProximoArmazem().getId();  // O próximo armazém é o primeiro da rota

    // Acessa o armazém de origem
    Armazem* armazemOrigem = mapaArmazens.vertices.listaAdj[origem].primeiro->item;

    // Remove o pacote da seção de destino atual
    armazemOrigem->removerPacote(destino, p->getId());  // Remove o pacote da pilha do armazém de origem

    // Avança a rota do pacote (remove o armazém atual da lista de rota)
    p->avancarRota();

    // Acessa o próximo armazém (o destino da próxima seção)
    int proximoArmazem = p->getProximoArmazem().getId();  // O próximo armazém na rota

    // Insere o pacote no armazém de destino
    Armazem* armazemDestino = mapaArmazens.vertices.listaAdj[proximoArmazem].primeiro->item;
    armazemDestino->inserePacote(*p);  // Insere o pacote na pilha do armazém de destino
}
