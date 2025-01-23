#include <iostream>
#include <math.h>
#include <vector>
using namespace std;
#include <map>
#include <limits.h>
#include <unordered_map>
#include <numeric>
#include <queue>


int countServers(vector<vector<int>>& grid) {
    int m=grid.size();
    int n=grid[0].size();
    vector<int>r(m,0);
    vector<int>c(n,0);
    int res=0;
    for(int i=0;i<m;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]==1){
                r[i]++;
                c[j]++;
            }
        }
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]==1 && (r[i]>1||c[j]>1))
                res++;
        }
    }
    return res;
}