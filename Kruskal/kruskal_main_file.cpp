#include <iostream>
#include <algorithm>
#include<string.h>
#include <vector>
#include <fstream>
#include <stdlib.h>
// #include "kruskal.cpp"

using namespace std;

void help(){
    cout << "O algoritmo de Kruskal é um algoritmo que busca uma árvore geradora mínima para um grafo conexo com pesos." << endl << "Para saber a árvore geradora mínima e o seu respectivo custo, digite:" << endl << "./kruskal_main_file -f input.txt" << endl;
}


int main(int argc, char* argv[]){

    int f = 0, in;
    std::string inputFile, src;
    
    for (int i = 0; i < argc; i++){
        if(!strcmp(argv[i], "-h")) help();
        if(!strcmp(argv[i], "-f")){f++; inputFile = argv[i+1]; }
        if(!strcmp(argv[i], "-i")){in++; src = argv[i+1];}
    }
    if (f){
        system("g++ kruskal.cpp -o kruskal");
        try {
            system(("./kruskal < "+inputFile).c_str());
        }catch(int e){
            if (e==1) throw "Arquivo não encontrado";
        }
        if(in)system(("./kruskal < "+inputFile + " -i " + src).c_str());
    }

    return 0;

}