#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

class aresta{

public:
    int s;
    int d;
    int w;

    aresta(){}

    aresta(int src, int des, int wei){
        s = src;
        d = des;
        w = wei;
    }
};

bool comparar_peso(aresta e1, aresta e2){
    return e1.w < e2.w;
}

int findparent(int i, int *parent){
    if (parent[i] == i)
        return i;
    return findparent(parent[i], parent);
}

class grafo{

public:
    int e, n;
    aresta *v;

    grafo(int n, int e){
        this->n = n;
        this->e = e;
        v = new aresta[e];

        for (int i = 0; i < e; i++){
            int x, y, w;
            cin >> x >> y >> w;
            aresta e(x, y, w);
            v[i] = e;
        }
    }

    aresta *unionfind(){
        int *parent = new int[n];
        for (int i = 0; i < n; i++){
            parent[i] = i;
        }
        //Ordenando arestas
        sort(v, v + e, comparar_peso);

        aresta *output;
        output = new aresta[n - 1];
        int contador = 0, i = 0;

        //Iterando através das arestas
        while (contador != n - 1){
            aresta c = v[i];
            int sourceparent = findparent(v[i].s, parent);
            int desparent = findparent(v[i].d, parent);
            if (sourceparent != desparent){
                output[contador] = c;
                parent[sourceparent] = desparent;
                contador++;
            }
            i++;
        }
        int soma = 0;
        cout << endl
             << "-------Árvore geradora mínima-------\n";
        //Saída do código
        for (int i = 0; i < n - 1; i++){
            cout << output[i].s << "	" << output[i].d << "	" << output[i].w << endl;
            soma += output[i].w;
        }
        cout << "\nO custo da árvore é: " << soma << endl;
        return output;
    }
};

int main(int argc, char* argv[])
{
    int n, e;
    //Leitura das variáveis e chamando as classes para execução do código
    int f, in =0;
    std::string inputFile, src;
    
    for (int i = 0; i < argc; i++){
        if(!strcmp(argv[i], "-f")){f++; inputFile = argv[i+1]; }
        if(!strcmp(argv[i], "-i")){in++; src = argv[i+1];}
    }
    cout << src;
    
    cin >> n;
    cin >> e;
    grafo g(n, e);
    aresta *agm = g.unionfind();

}
