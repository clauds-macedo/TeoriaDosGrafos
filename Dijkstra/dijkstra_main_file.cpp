#include <string.h>
#include <stdlib.h>
#include <stdio.h>

void help(){
    printf("\nO Algoritmo de Dijkstra (E.W. Dijkstra) é um dos algoritmos que calcula o caminho de custo mínimo entre vértices de um grafo. Escolhido um vértice como raiz da busca, este algoritmo calcula o custo mínimo deste vértice para todos os demais vértices do grafo. Ele é bastante simples e com um bom nível de performance. Ele não garante, contudo, a exatidão da solução caso haja a presença de arcos com valores negativos.\n \nPara saber a distância mínima de um vértice x a outro vértice y, execute o seguinte comando:\n./floyd-warshall_main_file -f input.txt -i x -l y\n \nPara saber de um vértice x para todos, digite:\n./floyd-warshall_main_file -f input.txt -i x\n");
}

int main(int argc, char* argv[]){

    int f = 0, in, invalue, only_help = 0;
    char* inputFile;
    char* src;
    system("g++ dijkstra.cpp -o dijkstra");
    char comando[255] = "./dijkstra ";    
    
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