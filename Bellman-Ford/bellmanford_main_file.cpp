#include <string.h>
#include <stdlib.h>
#include <stdio.h>

void help(){
    printf("\nO Algoritmo de Bellman-Ford é um algoritmo de busca de caminho mínimo em um digrafo (grafo orientado ou dirigido) ponderado, ou seja, cujas arestas têm peso, inclusive negativo.\n \nPara saber a distância mínima de um vértice x a outro vértice y, execute o seguinte comando:\n./floyd-warshall_main_file -f input.txt -i x -l y\n \nPara saber de um vértice x para todos, digite:\n./floyd-warshall_main_file -f input.txt -i x\n");
}

int main(int argc, char* argv[]){

    int f = 0, in, invalue, only_help = 0;
    char* inputFile;
    char* src;
    system("g++ bellmanford.cpp -o bellmanford");
    char comando[255] = "./bellmanford ";    
    
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
        if(!strcmp(argv[i], "-h")) {
            help(); 
            only_help++;
        }
    }

    if (only_help <= 0)system(comando);

    return 0;

}