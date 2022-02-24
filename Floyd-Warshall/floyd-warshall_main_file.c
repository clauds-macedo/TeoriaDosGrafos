#include <string.h>
#include <stdlib.h>
#include <stdio.h>

void help(){
    printf("\nO algorítmo de Floyd é um algoritmo que resolve o problema de calcular o caminho mais curto entre todos os pares de vértices em um grafo orientado (com direção) e valorado (com peso).\n \nPara saber a distância mínima de um vértice x a outro vértice y, execute o seguinte comando:\n./floyd-warshall_main_file -f input.txt -i x -l y\n \nPara saber de um vértice x para todos, digite:\n./floyd-warshall_main_file -f input.txt -i x\n");
}

int main(int argc, char* argv[]){

    int f = 0, in, invalue, only_help = 0;
    char* inputFile;
    char* src;
    system("gcc floyd-warshall.c -o floyd-warshall");
    char comando[255] = "./floyd-warshall ";    
    
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