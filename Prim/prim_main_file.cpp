#include <string.h>
#include <stdlib.h>
#include <stdio.h>

void help(){
    printf("\nO Algoritmo de Prim empregado para encontrar uma árvore geradora mínima (minimal spanning tree) num grafo conectado, valorado e não direcionado.\n \nPara imprimir a árvore a partir de um vértice x, execute o seguinte comando:\n./prim_main_file -f input.txt -i x -s\n \nPara saber a árvore geradora mínima, digite:\n./prim_main_file -f input.txt -i x\n");
}

int main(int argc, char* argv[]){

    int f = 0, in, invalue, only_help = 0;
    char* inputFile;
    char* src;
    system("g++ prim.cpp -o prim");
    char comando[255] = "./prim ";    
    
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