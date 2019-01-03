//
// Created by andy on 18/08/18.
//

//#include <bits/stdc++.h>

#include "hackerrank.h"
#include <iostream>
#include <limits>
#include <algorithm>
#include <set>
#include <algorithm>    // std::min_element, std::max_element
#include <map>
#include <set>

using namespace std;

// Complete the hourglassSum function below.

int hourglassSum(vector<vector<int>> arr) {
    auto vsize = arr.size();
    auto hsize = arr[0].size();
    int max_s = numeric_limits<int>::min();
    for(int a = 1; a < vsize -1; a++){
        for(int b = 1; b < hsize - 1; b++){
            int s = arr[a][b] + arr[a-1][b-1] + arr[a-1][b] + arr[a-1][b+1] + arr[a+1][b-1] + arr[a+1][b] + arr[a+1][b+1];
            if( s > max_s)
            {
                max_s = s;
            }
        }
    }
    return max_s;

}

vector<int> rotLeft(vector<int> a, int d) {
    vector<int> res;
    unsigned long arrSize = a.size();
    for(auto i = d; i < arrSize; i++){
        res.push_back(a[i]);
    }
    for (auto j = 0; j < d; j++){
        res.push_back(a[j]);
    }
    return res;
}

int minimumBribes(vector<int> q) {
    unsigned long qSize = q.size();
    int numSwap = 0;
    bool isChoao = false;
    for(int i = 0; i < qSize-1; i++){
        int qstick = q[i];
        if(qstick - 1 > i and qstick - 1 - i <= 2){
            int tmp = q[i+1];
            q[i+1] = qstick;
            q[i] = tmp;
            numSwap += 1;
        }
        else if(qstick - 1 - i > 2){
            isChoao = true;
            break;
        }
    }

    if(isChoao){
        cout << "Too chaotic" << endl;
        return -1;
    }
    else{
        cout << numSwap << endl;
        return numSwap;
    }
}

vector<int> gradingStudents(vector<int> grades){
    vector<int> roundGrads;
    for(auto iter = grades.begin(); iter < grades.end(); ++iter){
        if (*iter < 38 || *iter % 5 < 3){
            roundGrads.push_back(*iter);
        }
        else {
            int round = 5 - (*iter % 5) + *iter;
            roundGrads.push_back(round);
        }
    }
    return roundGrads;
}

void countApplesAndOranges(int s, int t, int a, int b, vector<int> apples, vector<int> oranges) {
    int appleCount = 0;
    int orangeCount = 0;
    for (auto iter = apples.begin(); iter < apples.end(); ++iter){
        int aDist = *iter + a;
        if (aDist >= s and aDist <= t){
            ++appleCount;
        }
    }
    cout << appleCount << endl;
    for (auto iter = oranges.begin(); iter < oranges.end(); ++iter){
        int bDist = *iter + b;
        if (bDist >= s and bDist <= t){
            ++orangeCount;
        }
    }
    cout << orangeCount << endl;
}

string kangaroo(int x1, int v1, int x2, int v2) {
    int s = 0;
    int diff = 0;
    if (x1 > x2){
        diff = x1 - x2;
        s = v2 - v1;
    }
    else if (x1 < x2){
        diff = x2 - x1;
        s = v1 - v2;
    }
    else{
        s = 1;
    }
    if (s > 0 and diff % s == 0)
        return "YES";
    else
        return "NO";

}

Graph createGraph(int V, vector<int> &graph_from, vector<int> &graph_to){
    Graph g(V);

    for(int i =0; i < graph_from.size(); i++){
        int src = graph_from[i] - 1;
        int dst = graph_to[i] - 1;
        g.addEdge(src, dst, 1);
    }

    return g;
}

int findShortest(int graph_nodes, vector<int> graph_from, vector<int> graph_to, vector<long> ids, int val) {

    Graph g = createGraph(graph_nodes, graph_from, graph_to);
    auto it = find(ids.begin(), ids.end(), val);
    auto st = find(it+1, ids.end(), val);
    if (it != ids.end() && st != ids.end()){
        long pos = distance(ids.begin(), it);
        long tpos = distance(ids.begin(), st);

        set<pair<int, int>> setds;
        vector<int> dist(graph_nodes, numeric_limits<int>::max());

        dist[pos] = 0;
        setds.insert(make_pair(0, pos));
        while(!setds.empty()){

            pair<int,int> tmp = *setds.begin();
            setds.erase(setds.begin());

            int u = tmp.second;

            if(u == tpos)
                break;

            for(auto iter = g.edges[u].begin(); iter != g.edges[u].end(); iter++){

                int d = (*iter).first;
                int w = (*iter).second;
                int ud = dist[u] + w;
                if(dist[d] > ud) {

                    if (dist[d] != numeric_limits<int>::max()) {
                        setds.erase(setds.find(make_pair(dist[d], d)));
                    }
                    dist[d] = ud;
                    setds.insert(make_pair(ud, d));
                }

            }

        }
        return dist[tpos];


    }
    else{
        return -1;
    }

}


int colleageEqual(vector<int> arr) {
    auto min_iter = std::min_element(arr.begin(), arr.end());
    auto max_iter = std::max_element(arr.begin(), arr.end());
    if (*min_iter == *max_iter)
        return 0;
    int min_a = *min_iter;
    int min_ops = -1;
    for(int i = 0; i <= 4; i ++){
//        if (min_a < 0)
//            break;
        int ops = 0;
        for(auto iter = arr.begin(); iter < arr.end(); ++iter){
            int diff = *iter - min_a;
            int five_ops = diff / 5;
            int two_ops = (diff % 5) / 2;
            int one_ops = (diff % 5) % 2;
            ops += (five_ops + two_ops + one_ops);
        }
        if (min_ops < 0 or ops < min_ops)
            min_ops = ops;
        --min_a;
    }
    return min_ops;
}

int sherlockcost(vector<int> B) {
    int low = 0;
    int high = 0;
    for (auto iter = B.begin()+1; iter < B.end(); ++iter){
        int highTolow = abs(*(iter-1) - 1);
        int lowTohigh = abs(1 - *iter);
        int highTohigh = abs(*(iter-1) - *iter);
        int nextLow = max(low + 0, high + highTolow);
        int nextHigh = max(high + highTohigh, low + lowTohigh);
        low = nextLow;
        high = nextHigh;
    }
    return max(high, low);
}


set<string> subStrings(set<string> strs){
    set<string> subStrs;
    for (auto iter = strs.begin(); iter != strs.end(); ++iter){
        for(int i = 0; i < (*iter).size(); ++ i){
            string s1 = (*iter).substr(0, i - 0);
            string s2 = (*iter).substr(i+1);
            string s3 = s1 + s2;
            subStrs.insert(s3);
        }
    }
    return subStrs;
}

// Complete the commonChild function below.
int commonChild(string s1, string s2) {

//    int matrix [int(s1.size()+1)][int(s2.size()+1)] ;
    vector < vector <int> > matrix(s2.length()+1,vector<int>(s1.length()+1));
//    for (int i = 0; i <= s1.size(); i++)
//        matrix[0][i] = 0;
//    for (int j = 0; j <= s2.size(); j++)
//        matrix[j][0] = 0;
    for (int j = 1; j <= s1.size(); j++){
        for (int i = 1; i <= s2.size(); i++){
            if (s1[i-1] == s2[j-1])
                matrix[j][i] = (matrix[j-1][i-1] + 1);
            else
                matrix[j][i] = max(matrix[j-1][i], matrix[j][i-1]);
        }
    }
    return matrix[s1.size()][s2.size()];



}

string reverseShuffleMerge(string s) {
    map<char, int> counter;
    map<char, int> reqs;
    for (auto iter = s.begin(); iter < s.end(); ++iter){
        ++counter[*iter];
    }
    for (map<char,int>::iterator it=counter.begin(); it!=counter.end(); ++it)
        reqs[((*it).first)] = ((*it).second/2);

    vector <char> vs;

    for(int i = s.size()-1; i >=0; --i ){
        char c = s[i];
        if(vs.size() == 0){
            vs.push_back(c);
            --reqs[c];
            --counter[c];
        }
        else if(reqs[c] == 0){
            --counter[c];
            continue;
        }
        else{
            while(!vs.empty()){
                char last = *(vs.end()-1);
                if(c < last && reqs[last] + 1 <= counter[last]){
                    ++reqs[last];
                    vs.pop_back();
                }
                else
                    break;
            }
            vs.push_back(c);
            --reqs[c];
            --counter[c];
        }
    }

    // sort (vs.begin(), vs.end());
    string res (vs.begin(), vs.end());
    return res;

}

bool DFS(int src, int &n,  vector<vector<int>> &edges, vector<int> &machines, vector<vector<int>> &paths, vector<int> &visited){
    bool res = false;
    visited.push_back(src);
    for(int i = 0; i < n; i++){
        int w = edges[src][i];
        bool is_visited = find(visited.begin(), visited.end(), i) != visited.end();
        if(!is_visited && w >= 0 && find(machines.begin(), machines.end(), i) == machines.end()){
            bool has_machine = DFS(i, n, edges, machines, paths, visited);
            if(has_machine){
                vector<int> p = {w, src, i};
                paths.push_back(p);
                res = true;
                break;
            }
        }
        else if(w >= 0 && !is_visited){
            vector<int> p = {w, src, i};
            paths.push_back(p);
            res = true;
            cout << src << "->" << i << " : " << w << endl;
            // machines.erase(find(machines.begin(), machines.end(), i));
            break;
        }
    }
    return res;
}

bool cmp(vector<int> a, vector<int>b){
    return a[0] < b[0];
}


int minTime(int n, vector<vector<int>> roads, vector<int> machines) {
    vector<vector<int>> edges(n, vector<int>(n, -1));
    int result = 0;
    for(auto it = roads.begin(); it != roads.end(); it++){
        int src = (*it)[0];
        int dst = (*it)[1];
        int weights = (*it)[2];
        edges[src][dst] = weights;
        edges[dst][src] = weights;
    }
    for(auto it = machines.begin(); it != machines.end(); it++){
        vector<vector<int>>paths;
        vector<int> visited;

        bool has_machines = DFS((*it), n, edges, machines, paths, visited);

        if(has_machines)
        {
            auto m = min_element(paths.begin(), paths.end(), cmp);
            edges[(*m)[1]][(*m)[2]] = -1;
            edges[(*m)[2]][(*m)[1]] = -1;
            result += (*m)[0];
        }

        // machines.erase(it);
    }
    return result;

}

int perms(int n, map<int, int> &cache){
    if(n == 0)
        return 1;

    if(cache.find(n) != cache.end())
        return cache[n];

    int result = 0;
    if(n >= 1){
        result += perms(n-1, cache);
    }
    if(n >= 2){
        result += perms(n-2, cache);
    }
    if(n >= 3){
        result += perms(n-3, cache);
    }
    cache[n] = result;
    return result;
}

int stepPerms(int n) {

    map<int, int> cache;
    int result = perms(n, cache);
    return result;

}

int supD(string n, map<string, int>& cache){
    if (cache.find(n) != cache.end()){
        return cache[n];
    }
    else{
        int sup = 0;
        for(auto it = n.begin(); it != n.end(); it++){
            sup += ((int)(*it) - '0');
        }
        cache[n] = sup;
        return sup;
    }
}

int superDigit(string n, int k) {
    map<string, int> cache;
    int s = 0;
    for(int i = 0; i < k; i++){
        s += supD(n, cache);
    }
    while(s > 10){

        s = supD(to_string(s), cache);
    }
    return s;

}
