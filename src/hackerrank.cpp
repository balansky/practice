//
// Created by andy on 18/08/18.
//

//#include <bits/stdc++.h>

#include "hackerrank.h"
#include <iostream>
#include <limits>
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
