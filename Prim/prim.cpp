#include <bits/stdc++.h>

using namespace std;

struct edge
{
    int u, v, w;
};

void Enqueue(struct edge heap[], int size, struct edge value) //adiciona nó na fila
{
    heap[size] = value;

    int i = size;
    struct edge temp;

    while (i >= 1)
    {
        if (heap[i / 2].w > heap[i].w)
        {
            temp = heap[i / 2];
            heap[i / 2] = heap[i];
            heap[i] = temp;
            i = i / 2;
        }
        else
        {
            break;
        }
    }
}

void Heapify(struct edge heap[], int size, int index) // sorting of nodes
{
    int i = index;
    struct edge temp;

    while ((2 * i) < size)
    {

        if ((2 * i) + 1 >= size)
        {

            if (heap[i].w > heap[2 * i].w)
            {

                temp = heap[i];
                heap[i] = heap[2 * i];
                heap[2 * i] = temp;
                break;
            }
        }

        if (heap[i].w > heap[2 * i].w || heap[i].w > heap[2 * i + 1].w)
        {

            if (heap[2 * i].w <= heap[(2 * i) + 1].w)
            {
                temp = heap[2 * i];
                heap[2 * i] = heap[i];
                heap[i] = temp;
                i = 2 * i;
            }
            else if (heap[2 * i].w > heap[(2 * i) + 1].w)
            {
                temp = heap[(2 * i) + 1];
                heap[(2 * i) + 1] = heap[i];
                heap[i] = temp;
                i = (2 * i) + 1;
            }
        }
        else
        {
            break;
        }
    }
}

void DeleteNode(struct edge heap[], int size, int index) //deletar nós
{
    struct edge temp = heap[index];
    heap[index] = heap[size - 1];
    heap[size - 1] = temp;
    int i = index;
    --size;
    Heapify(heap, size, i);
}

struct edge ExtractMin(struct edge heap[], int size)
{
    struct edge min = heap[0];

    DeleteNode(heap, size, 0);

    return min;
}

void PrimsAlgorithm(vector<list<pair<int, int>>> &graph, int v, int e, int startVertex, vector<list<pair<int, int>>> &primsalgo)
{
    int current = startVertex, newVertex;
    bool color[v + 1];
    struct edge var;
    struct edge PriorityQueue[2 * e];
    int QueueSize = 0;

    int i;

    for (i = 0; i <= v; ++i)
    { //inicia os nós com a cor branca(falso)
        color[i] = false;
    }

    i = 0;

    while (i < v)
    {
        if (!color[current])
        {                          //verifica se nó atual é falso
            color[current] = true; //muda a cor do nó pra preto (true)

            list<pair<int, int>>::iterator primIterator = graph[current].begin();

            while (primIterator != graph[current].end())
            {
                if (!color[(*primIterator).first])
                {

                    var.u = current;
                    var.v = (*primIterator).first;
                    var.w = (*primIterator).second;

                    Enqueue(PriorityQueue, QueueSize, var);
                    ++QueueSize;
                }

                ++primIterator;
            }

            var = ExtractMin(PriorityQueue, QueueSize);
            --QueueSize;
            newVertex = var.v;
            current = var.u;
            if (!color[newVertex])
            {
                primsalgo[current].push_back(make_pair(newVertex, var.w));
                primsalgo[newVertex].push_back(make_pair(current, var.w));
            }
            current = newVertex;
            ++i;
        }
        else
        {

            var = ExtractMin(PriorityQueue, QueueSize);
            --QueueSize;

            newVertex = var.v;
            current = var.u;

            if (!color[newVertex])
            {
                primsalgo[current].push_back(make_pair(newVertex, var.w));
                primsalgo[newVertex].push_back(make_pair(current, var.w));
            }

            current = newVertex;
        }
    }
}

int main(int argc, char* argv[])
{
    int v, e, v1, v2, w;
    bool s_arg = false;

    scanf("%d%d", &v, &e);
    int isrc, idest, src = 1;
    
    for (int i = 0; i < argc; i++){
        if(!strcmp(argv[i], "-i")){isrc++; src = atoi(argv[i+1]); }
        if(!strcmp(argv[i], "-s")){ s_arg = true; }
    }

    vector<list<pair<int, int>>> graph(v + 1);
    vector<list<pair<int, int>>> primsalgo(v + 1);

    for (int i = 1; i <= e; ++i)
    {
        scanf("%d%d%d", &v1, &v2, &w);

        graph[v1].push_back(make_pair(v2, w));
        graph[v2].push_back(make_pair(v1, w));
    }
    
    PrimsAlgorithm(graph, v, e, src, primsalgo);

    int mst = 0; //variável q vai guardar a AGM
    for (int i = 1; i < primsalgo.size(); ++i)
    {
        list<pair<int, int>>::iterator primIterator = primsalgo[i].begin();

        while (primIterator != primsalgo[i].end())
        {
            if (i < (*primIterator).first)
            {
                if (s_arg){
                printf("(%d, %d) ", i, (*primIterator).first);}
                mst += (*primIterator).second;
            }
            ++primIterator;
        }
    }
    cout << endl;

    if (!s_arg) {cout << mst; cout << endl;}

    return 0;
}