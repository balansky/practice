//
// Created by andy on 02/10/18.
//

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

struct Edge{

    int src, dest, weight;
};

struct Graph{
    int V, E;
    Edge *edge;
};

Graph createGraph(int v, int e){

    Graph graph;
    graph.V = v;
    graph.E = e;
    graph.edge = new Edge[e];
    return graph;

};

struct subset{
    int parent;
    int rank;
};

int findRoot(subset subs[], int i){

    if (subs[i].parent != i)
        subs[i].parent = findRoot(subs, subs[i].parent);
    return subs[i].parent;

};

void unionSets(subset subs[], int x, int y){
    int rootX = findRoot(subs, x);
    int rootY = findRoot(subs, y);

    if (subs[rootX].rank > subs[rootY].rank)
        subs[rootY].parent = subs[rootX].parent;
    else if(subs[rootX].rank < subs[rootY].rank)
        subs[rootX].parent = subs[rootY].parent;
    else{
        subs[rootX].parent = subs[rootY].parent;
        ++subs[rootX].rank;
    }

};

int compareWeight(const void *a, const void *b){
    Edge *a1 = (Edge*) a;
    Edge *a2 = (Edge*) b;
    return a1->weight > a2->weight;
}


void KruskalMST(){
    int V = 4;  // Number of vertices in graph
    int E = 5;  // Number of edges in graph
    Graph graph = createGraph(V, E);
    Edge results[V];

    // add edge 0-1
    graph.edge[0].src = 0;
    graph.edge[0].dest = 1;
    graph.edge[0].weight = 10;

    // add edge 0-2
    graph.edge[1].src = 0;
    graph.edge[1].dest = 2;
    graph.edge[1].weight = 6;

    // add edge 0-3
    graph.edge[2].src = 0;
    graph.edge[2].dest = 3;
    graph.edge[2].weight = 5;

    // add edge 1-3
    graph.edge[3].src = 1;
    graph.edge[3].dest = 3;
    graph.edge[3].weight = 15;

    // add edge 2-3
    graph.edge[4].src = 2;
    graph.edge[4].dest = 3;
    graph.edge[4].weight = 4;

    qsort(graph.edge, E, sizeof(graph.edge[0]), compareWeight);

    subset subs [V] ;

    for(int i = 0; i < V; ++i){
        subset s;
        s.parent = i;
        s.rank = 0;
        subs[i] = s;
    }

    int e = 0;
    int k = 0;
    while( e < V -1){

        Edge next_edge = graph.edge[k++];
        int s = findRoot(subs, next_edge.src);
        int d = findRoot(subs, next_edge.dest);
        if (s != d){
            results[e++] = next_edge;
            unionSets(subs, s, d);
        }

    }

    for(int i = 0; i < e; i++){
        cout << results[i].src << "->" << results[i].dest << endl;
    }


}
