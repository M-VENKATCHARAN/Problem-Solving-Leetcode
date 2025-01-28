#include <math.h>
#include <vector>
using namespace std;
#include <map>
#include <limits.h>
#include <unordered_map>
#include <numeric>
#include <queue>
#include <algorithm>

vector<vector<int>>dir={{0,1},{0,-1},{1,0},{-1,0}};

int bfs(vector<vector<int>>& grid,int i,int j){
    int m=grid.size();
    int n=grid[0].size();
    vector<vector<int>>vis(m,vector<int>(n,0));
    queue<pair<int,int>>q;
    q.push({i,j});
    int ans=0;
    ans+=grid[i][j];
    grid[i][j]=0;

    while(!q.empty()){
        auto [r,c]=q.front();
        q.pop();
        for(auto it:dir){
            int r1=r+it[0];
            int c1=c+it[1];
            if(r1>=0 && c1>=0 && r1<m && c1<n && grid[r1][c1]!=0 && !vis[r1][c1]){
                vis[r1][c1]=1;
                ans+=grid[r1][c1];
                grid[r1][c1]=0;
                q.push({r1,c1});
            }
        }
    }   
    return ans;
}

int findMaxFish(vector<vector<int>>& grid) {

    int m=grid.size();
    int n=grid[0].size();


    int ans=0;

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j]!=0){
                ans=max(ans,bfs(grid,i,j));
            }
        }
    }

    return ans;
}