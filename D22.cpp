#include <iostream>
#include <math.h>
#include <vector>
using namespace std;
#include <map>
#include <limits.h>
#include <unordered_map>
#include <numeric>
#include <queue>


vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
    int m=isWater.size();
    int n=isWater[0].size();

    queue<pair<int,int>>q;
    vector<vector<int>> res(m,vector<int>(n,-1));
    vector<vector<int>> dir={{0,1},{1,0},{0,-1},{-1,0}};

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(isWater[i][j]==1){
                res[i][j]=0;
                q.push({i,j});
            }
        }
    }

    while(!q.empty()){
        int r=q.front().first;
        int c=q.front().second;
        q.pop();
        for(auto it:dir){
            int r1=r+it[0];
            int c1=c+it[1];

            while(r1>=0 && c1>=0 && r1<m && c1<n && res[r1][c1]==-1){
                    res[r1][c1]=res[r][c]+1;
                    q.push({r1,c1});
            }
        }
    }
    return res;
}