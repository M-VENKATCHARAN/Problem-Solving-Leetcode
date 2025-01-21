#include <iostream>
#include <math.h>
#include <vector>
using namespace std;
#include <map>
#include <limits.h>
#include <unordered_map>
#include <numeric>

long long gridGame(vector<vector<int>>& grid) {
    int n=grid[0].size();

    long long r1cnt=accumulate(grid[0].begin(),grid[0].end(),0);
    long long r2cnt=0;
    long long res=INT_MAX;

    for(int i=0;i<n;i++){
        r1cnt-=grid[0][i]; 
        long long cur=max(r1cnt,r2cnt); //keep track of maximizing of robot1
        res=min(res,cur); //keep track of minimizing the value of robot 2
        r2cnt+=grid[1][i];
    }

    return res;
}