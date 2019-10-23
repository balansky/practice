#include<dijkstras.hpp>

int DijkstrasRoute::shortest_path(int src, int target, int **graph){
    std::priority_queue<Vertex, std::vector<Vertex>, std::greater<Vertex>> q;
    std::vector<bool>visted(n, false);
    std::vector<int> results(n);

    Vertex s(src, 0);
    q.push(s);
    while(!q.empty()){
        Vertex m = q.top();
        q.pop();
        if(visted[m.idx]) 
            continue;
        visted[m.idx] = true;
        results[m.idx] = m.weight;
        for(int i = 0; i < n; i++){
            if(!visted[i] && graph[m.idx][i] != 0){
                Vertex neighbour(i, m.weight + graph[m.idx][i]);
                q.push(neighbour);
            }
        }
    }
    return results[target];
}