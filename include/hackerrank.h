//
// Created by andy on 26/09/18.
//

#ifndef PRACTICE_HACKERRANK_H
#define PRACTICE_HACKERRANK_H
//#include <bits/stdc++.h>
#include <vector>
#include <list>
#include <bits/stdc++.h>
//#include <vector>

using namespace std;

int hourglassSum(vector<vector<int>>);

vector<int> rotLeft(vector<int>, int);

int minimumBribes(vector<int>);

vector<int> gradingStudents(vector<int>);

void countApplesAndOranges(int s, int t, int a, int b, vector<int> apples, vector<int> oranges);


struct Graph{

    int V;
    list<pair<int, int>> *edges;

    Graph(int v){
        V = v;
        edges = new list<pair<int, int>> [v];

    }

    ~Graph(){
        delete [] edges;
    }

    void addEdge(int s, int d, int w){
        edges[s].push_back(make_pair(d, w));
        edges[d].push_back(make_pair(s, w));
    }

};

int findShortest(int graph_nodes, vector<int> graph_from, vector<int> graph_to, vector<long> ids, int val);

int colleageEqual(vector<int> arr);

int sherlockcost(vector<int> B);

int commonChild(string s1, string s2);

string reverseShuffleMerge(string s);


void KruskalMST();
#endif //PRACTICE_HACKERRANK_H
