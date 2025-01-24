#include <iostream>
#include <math.h>
#include <vector>
using namespace std;
#include <map>
#include <limits.h>
#include <unordered_map>
#include <numeric>
#include <queue>
#include <algorithm>

vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
    int n=graph.size();
    vector<vector<int>>rgraph(n);
    vector<int>ind(n,0);
    vector<int>res;
    for(int i=0;i<n;i++){
        for(auto v:graph[i]){
            rgraph[v].push_back(i);
            ind[i]++;
        }
    }
    queue<int>q;
    for(int i=0;i<n;i++){
        if(ind[i]==0)q.push(i);
    }

    while(!q.empty()){
        int x=q.front();
        q.pop();
        res.push_back(x);
        for(auto y:rgraph[x]){
            ind[y]--;
            if(ind[y]==0)q.push(y);
        }
    }
    sort(res.begin(),res.end());
    return res;
}