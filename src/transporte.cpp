#include "transporte.hpp"

Transporte::Transporte(int capacidadeTransporte, int latenciaTransporte, int intervaloTransporte, Grafo mapa): capacidadeTransporte(capacidadeTransporte), 
latenciaTransporte(latenciaTransporte), intervaloTransporte(intervaloTransporte), mapaArmazens(mapa){}

void Transporte::calculaRota(Pacote& p){
    mapaArmazens.BFS(p);
}

void Transporte::adicionarPacoteOrigem(Pacote pacote){
    mapaArmazens.vertices.
}