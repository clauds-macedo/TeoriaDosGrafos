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

    int f = 0, in, invalue, only_help = 0;
    char* inputFile;
    char* src;
    system("g++ kruskal.cpp -o kruskal");
    char comando[255] = "./kruskal ";   

    for (int i = 0; i < argc; i++){
        if(!strcmp(argv[i], "-f")){
            f++; inputFile = argv[i+1]; 
            strcat(comando, "< ");
            strcat(comando, inputFile);
            only_help--;
        }

        if(!strcmp(argv[i], "-i")){
            strcat(comando, " -i ");
            strcat(comando, argv[i+1]);
        }

        if(!strcmp(argv[i], "-l")){
            strcat(comando, " -l ");
            strcat(comando, argv[i+1]);
        }

        if(!strcmp(argv[i], "-s")){
            strcat(comando, " -s ");
        }

        if(!strcmp(argv[i], "-h")) {
            help(); 
            only_help++;
        }
    }

    if (only_help <= 0)system(comando);

    return 0;

}