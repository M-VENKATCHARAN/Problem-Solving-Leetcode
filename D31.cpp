#include <math.h>
#include <vector>
using namespace std;
#include <map>
#include <limits.h>
#include <unordered_map>
#include <numeric>
#include <queue>
#include <algorithm>

class Solution {
public:
    int getval(int i,int j,vector<vector<int>>& grid){
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size())return 0;
        return grid[i][j];
    }
    int fill(int i,int j,int clr,vector<vector<int>>& grid){
        if(getval(i,j,grid)!=1)return 0;
        grid[i][j]=clr;
        return 1+fill(i+1,j,clr,grid)+fill(i-1,j,clr,grid)+fill(i,j-1,clr,grid)+fill(i,j+1,clr,grid);
    }
    int largestIsland(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int maxi=0;
        vector<int>island_sizes={0,0};

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1)
                    island_sizes.push_back(fill(i,j,island_sizes.size(),grid));
            }
        }

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0){
                    unordered_set<int>n={
                        getval(i+1,j,grid),getval(i,j+1,grid),getval(i-1,j,grid),getval(i,j-1,grid)
                    };
                    int maxi2=1;

                    for(int clr:n){
                        maxi2+=island_sizes[clr];
                    }
                    maxi=max(maxi,maxi2);
                }
            }
        }
        return maxi==0?n*m:maxi;

    }
};