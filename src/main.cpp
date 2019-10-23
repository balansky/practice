#include <iostream>
#include <binarytree.hpp>
#include <limits>
#include <dijkstras.hpp>

using namespace std;

int cut_rod(int *p, int n){
    int r[n+1];
    r[0] = 0;
    for(int i = 1; i <= n; i++){
        int max_p = std::numeric_limits<int>::min();
        for(int j = 0; j < i; j++){
            max_p = max(max_p, p[i - j - 1] + r[j]);
        }
        r[i] = max_p;
    }
    return r[n];
}


int main(int argc, char *argv[]){

    // int n = 2;
    // int p[5] = {1, 5, 8, 9, 10};
    // int max_p = cut_rod(p, n);
    // std::cout << max_p << std::endl;
    // std::cout << "hello" << std::endl;
    int V = 9;

    int graph[V][V] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 }, 
                        { 4, 0, 8, 0, 0, 0, 0, 11, 0 }, 
                        { 0, 8, 0, 7, 0, 4, 0, 0, 2 }, 
                        { 0, 0, 7, 0, 9, 14, 0, 0, 0 }, 
                        { 0, 0, 0, 9, 0, 10, 0, 0, 0 }, 
                        { 0, 0, 4, 14, 10, 0, 2, 0, 0 }, 
                        { 0, 0, 0, 0, 0, 2, 0, 1, 6 }, 
                        { 8, 11, 0, 0, 0, 0, 1, 0, 7 }, 
                        { 0, 0, 2, 0, 0, 0, 6, 7, 0 } }; 
    
    int **pGraph = new int*[V];
    for (int i = 0; i < V; i++){
        pGraph[i] = new int[V];
        for(int j = 0; j < V; j++){
            pGraph[i][j] = graph[i][j];
        }
    }

    DijkstrasRoute dj(V);
    int w = dj.shortest_path(0, 4, pGraph);
    

    for(int i = 0; i < V; i++){
        delete pGraph[i];
    }
    delete pGraph;


    Tree tree;
    tree.add_value(10);
    tree.add_value(20);
    tree.add_value(5);
    tree.add_value(4);
    tree.add_value(1);
    // tree.add_value(100);
    // tree.remove_value(4);
    std::cout << "Tree Height: " << tree.node_height(tree.root) << std::endl;
    
    tree.inorder_print(tree.root);

    return 0;
}