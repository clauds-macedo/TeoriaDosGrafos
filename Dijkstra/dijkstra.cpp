#include <bits/stdc++.h>
#include <vector>
#include <utility>
using namespace std;

void show_full_distance(std::vector<int> distTo, int n){
    for (int i = 1; i <= n; i++){
        distTo[i] < 9999 ? cout << "" << i << ":" << distTo[i] << " "
        : cout << i << ":" << "INF ";
    }
    cout << endl;
}

void show_x_to_y_distance(std::vector<int> distTo, int dest){
    cout << distTo[dest] << endl;
}

class grafo
{
public:
    int n, e;
    grafo(int n, int e, int src, int dest)
    {
        this->n = n;
        this->e = e;
        int u, v, w;
        vector<pair<int, int>> adjacent_list[n + 1];
        for (int i = 0; i < e; i++)
        {
            cin >> u;
            cin >> v;
            cin >> w;
            adjacent_list[u].push_back(make_pair(v,w));
            adjacent_list[v].push_back(make_pair(v,w));
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>,greater<pair<int, int>>> pq; //heap-minima
        vector<int> distTo(n + 1, INT_MAX);

        distTo[src] = 0;
        pq.push(make_pair(0, src)); //(dist,from)

        while (!pq.empty())
        {
            int dist = pq.top().first;
            int prev = pq.top().second;
            pq.pop();
            for (auto it : adjacent_list[prev])
            {
                int next = it.first;
                int nextDist = it.second;
                if (distTo[next] > distTo[prev] + nextDist)
                {
                    distTo[next] = distTo[prev] + nextDist;
                    pq.push(make_pair(distTo[next], next));
                }
            }
        }
        if (dest > 0) show_x_to_y_distance(distTo, dest);
        else show_full_distance(distTo, n);
    }
};

int main(int argc, char* argv[])
{
    int n, e;
    cin >> n;
    cin >> e;
    int isrc, idest, src = 1, dest = 0;
    for (int i = 0; i < argc; i++){
        if(!strcmp(argv[i], "-i")){isrc++; src = atoi(argv[i+1]); }
        if(!strcmp(argv[i], "-l")){idest++; dest = atoi(argv[i+1]); }
    }
    
    grafo g(n, e, src, dest);

}
