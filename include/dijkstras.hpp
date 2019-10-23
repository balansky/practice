#include <vector>
#include <queue>

struct Vertex{

    int weight;
    int idx;

    explicit Vertex(int idx, int w): idx(idx), weight(w){}
    Vertex():idx(0),weight(0){}

    bool operator<=(const Vertex &rhs) const{
        return this->weight <= rhs.weight;
    }

    bool operator<(const Vertex &rhs) const{
        return this->weight < rhs.weight;
    }

    bool operator>(const Vertex &rhs) const{
        return this->weight > rhs.weight;
    }

};

struct DijkstrasRoute{

    int n;

    DijkstrasRoute(int n):n(n){}

    int shortest_path(int src, int target, int **graph);
};