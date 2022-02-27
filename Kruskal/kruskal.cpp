#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;
bool s_arg = false;
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

bool comparar_peso(aresta e1, aresta e2)
{
    return e1.w < e2.w;
}

int findparent(int i, int *parent)
{
    if (parent[i] == i)
        return i;
    return findparent(parent[i], parent);
}

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

    aresta *unionfind()
    {
        int *parent = new int[n];
        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
        }
        // Ordenando arestas
        sort(v, v + e, comparar_peso);

        aresta *output;
        output = new aresta[n - 1];
        int contador = 0, i = 0;

        // Iterando através das arestas
        while (contador != n - 1)
        {
            aresta c = v[i];
            int sourceparent = findparent(v[i].s, parent);
            int desparent = findparent(v[i].d, parent);
            if (sourceparent != desparent)
            {
                output[contador] = c;
                parent[sourceparent] = desparent;
                contador++;
            }
            i++;
        }
        int soma = 0;
        int temp;
        //bubble sort para organizar o resultado
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = 0; j < n - 2; j++)
            {
                if (output[j].s > output[j + 1].s)
                {
                    temp = output[j].s;
                    output[j].s = output[j + 1].s;
                    output[j + 1].s = temp;
                    temp = output[j].d;
                    output[j].d = output[j + 1].d;
                    output[j + 1].d = temp;
                }
                if (output[j].s == output[j + 1].s)
                {
                    if (output[j].d > output[j + 1].d)
                    {
                        temp = output[j].d;
                        output[j].d = output[j + 1].d;
                        output[j + 1].d = temp;
                    }
                }
            }
        } // Saída do código
        for (int i = 0; i < n - 1; i++)
        {
            if (s_arg)
                cout << "(" << output[i].s << ","
                     << " " << output[i].d << ")"
                     << " ";
            soma += output[i].w;
        }
        if (!s_arg)
            cout << soma << endl;
        return output;
    }
};

int main(int argc, char *argv[])
{
    int n, e;
    // Leitura das variáveis e chamando as classes para execução do código
    int src = 1;

    for (int i = 0; i < argc; i++)
    {
        if (!strcmp(argv[i], "-i"))
        {
            src = atoi(argv[i + 1]);
        }
        if (!strcmp(argv[i], "-s"))
        {
            s_arg = true;
        }
    }

    cin >> n;
    cin >> e;
    grafo g(n, e);
    aresta *agm = g.unionfind();
}
