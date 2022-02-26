#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <bits/stdc++.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

using namespace std;
int INF = 1000000000;
int dist[1500];

void showDistance(int dist[], int n)
{
    for (int i = 0; i < n; ++i)
        dist[i] != INF ? printf("%d:%d ", i, dist[i])
        : printf("%d:INF ", i);
    cout << endl;
}

void show_x_to_y_distance(int dist[], int dest){
    cout << dist[dest] << endl;
}

void inf(int n)
{                          //infinitar as distâncias
	for(int i = 0; i < n; ++i){
		dist[i] = INF;
	}
}

class aresta
{

public:
    int s;
    int d;
    int w;

    aresta() {}

    aresta(int src, int des, int wei)
    {
        s = src;
        d = des;
        w = wei;
    }
};

class grafo
{

public:
    int e, n;
    aresta *v;

    grafo(int n, int e)
    {
        this->n = n;
        this->e = e;
        v = new aresta[e];

        for (int i = 0; i < e; i++)
        {
            int x, y, w;
            cin >> x >> y >> w;
            aresta e(x, y, w);
            v[i] = e;
        }
    }

    void bellman_ford(grafo grafo, int src, int dest)
    {
        int n = this->n;
        int e = this->e;
        vector<int> dis[n];

        inf(n);

        for (int i = 0; i < n; i++)
            dis[i].push_back(INT_MAX);
        dist[src] = 0;

        for (int i = 1; i <= n - 1; i++)
        {

            for (int j = 0; j < e; j++)
            {
                int u = grafo.v[j].s;
                int v = grafo.v[j].d;
                int weight = grafo.v[j].w;
                if (dist[u] != INT_MAX && dist[u] + weight < dist[v])
                    dist[v] = dist[u] + weight;
            }
        }

        for (int i = 0; i < e; i++)
        {
            int u = grafo.v[i].s;
            int v = grafo.v[i].d;
            int weight = grafo.v[i].w;
            if (dist[u] != INT_MAX && dist[u] + weight < dist[v])
            {
                printf("Found negative weight cycle");
                return;
            }
        }


        dest == 0 ? showDistance(dist, n)
        : show_x_to_y_distance(dist, dest);
        ;
    }
};

int main(int argc, char *argv[])
{
    int n, e;
    // Leitura das variáveis e chamando as classes para execução do código
    int f, isrc = 0, idest = 0, src, dest;
    std::string inputFile;

    for (int i = 0; i < argc; i++)
    {
        if (!strcmp(argv[i], "-f"))
        {
            f++;
            inputFile = argv[i + 1];
        }
        if (!strcmp(argv[i], "-i"))
        {
            idest++;
            src = atoi(argv[i + 1]);
        }
        if(!strcmp(argv[i], "-l")){
            idest++; 
            dest = atoi(argv[i+1]); 
        }
    }

    cin >> n;
    cin >> e;
    grafo g(n, e);
    g.bellman_ford(g, src, dest);
    return 0;
}