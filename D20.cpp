#include <iostream>
#include <math.h>
#include <vector>
using namespace std;
#include <map>
#include <unordered_map>

int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
    int m1=mat.size();
    int n1=mat[0].size();
    int n=arr.size();

    unordered_map<int,pair<int,int>>mp;

    for(int i=0;i<m1;i++){
        for(int j=0;j<n1;j++){
            mp[mat[i][j]]={i,j};
        }
    }
    vector<int>rcnt(m1,0);
    vector<int>ccnt(n1,0);
    for(int i=0;i<n;i++){
        int val=arr[i];
        int r = mp[val].first;
        int c = mp[val].second;

        rcnt[r]++;
        ccnt[c]++;

        if(rcnt[r]==n1||ccnt[c]==m1)return i;
    }
    return -1;
}