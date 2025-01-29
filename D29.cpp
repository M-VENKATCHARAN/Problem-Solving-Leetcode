#include <math.h>
#include <vector>
using namespace std;
#include <map>
#include <limits.h>
#include <unordered_map>
#include <numeric>
#include <queue>
#include <algorithm>


bool bfs(vector<vector<int>>& edges,unordered_map<int,vector<int>>&mp,int a,int b){
    int n=edges.size();
    queue<int>q;
    vector<int>vis(n+1,0);
    q.push(a);

    while(!q.empty()){
        int x=q.front();
        q.pop();
        vis[x]=1;

        if(x==b)return true;

        for(int y:mp[x]){
            if(!vis[y])q.push(y);
        }
    }
    return false;
}


vector<int> findRedundantConnection(vector<vector<int>>& edges) {
    int n=edges.size();

    unordered_map<int,vector<int>>mp;

    for(int i=0;i<n;i++){
        int a=edges[i][0];
        int b=edges[i][1];

        if(mp.find(a)!=mp.end() && mp.find(b)!=mp.end() && bfs(edges,mp,a,b))return edges[i];

        mp[a].push_back(b);
        mp[b].push_back(a);
    }
    return {};
}