#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int min(int a, int b){
    return a < b ? a : b;
}

void floyd_warshall_algorithm(int p[10][10], int n){
    int i, j, k;
    for (k = 1; k <= n; k++)
        for (i = 1; i <= n; i++)
            for (j = 1; j <= n; j++)
                if (i == j)
                    p[i][j] = 0;
                else
                    p[i][j] = min(p[i][j], p[i][k] + p[k][j]);
}

void transitive_closure(int n, int i, int j, int p[i][j]){
    for (i = 1; i <= n; i++){
        for (j = 1; j <= n; j++)
            printf("%d \t", p[i][j]);
        printf("\n");
    }
}

void show_adjacent_matrix(int i, int n, int j, int p[i][j]){
    for (i = 1; i <= n; i++){
        for (j = 1; j <= n; j++) printf("%d \t", p[i][j]);
        printf("\n");
    }
}

void show_shortest_path(int src, int n, int i, int j, int p[i][j]){
    for (int i = src; i <= n; i++){
        for (j = 1; j <= n; j++){
            if (i != j)
                printf("\n(%d,%d)=%d", i, j, p[i][j]);
        }
    }
    printf("\n");
}

void source_to_dest(int src, int dest, int n, int i, int j, int p[i][j]){

     for(i=1;i<=n;i++){
    	for(j=1;j<=n;j++){
    		if(i == src && j == dest){
				printf("\nFrom %d to %d: %d\n",i,j, p[i][j]);
			}
		}
	}

}

void main(int argc, char* argv[]){
    int n, e, i, j;
    int src, dest;
    scanf("%d%d", &n, &e); // número de vértices e arestas
    //tratando parametros
    int isrc, idest;
    for (int i = 0; i < argc; i++){
        if(!strcmp(argv[i], "-i")){isrc++; src = atoi(argv[i+1]); }
        if(!strcmp(argv[i], "-l")){idest++; dest = atoi(argv[i+1]); }
    }

    int p[10][10];
    for (i = 1; i <= n; i++){
        for (j = 1; j <= n; j++)
            p[i][j] = 999;
    }

    int w, u, v;
    for (i = 1; i <= e; i++)
    {
        // vértices, arestas e peso
        scanf("%d%d%d", &u, &v, &w);
        p[u][v] = w;
    }
    // Matriz adjacente obtida
    printf("Obtained adjacent matrix\n");
    show_adjacent_matrix(i, n, j, p);

    floyd_warshall_algorithm(p, n);

    printf("\nTransitive closure:\n");
    transitive_closure(n, src, j, p);
    if (src && dest) source_to_dest(src, dest, n, i, j, p);
    else {
        printf("\nShortest paths from %d:", src);
        show_shortest_path(src, n, i, j, p);
    }
    
}