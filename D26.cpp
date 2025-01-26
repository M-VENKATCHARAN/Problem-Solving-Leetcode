
#include <math.h>
#include <vector>
using namespace std;
#include <map>
#include <limits.h>
#include <unordered_map>
#include <numeric>
#include <queue>
#include <algorithm>

// any node has one outgoing edge
// any node can have at max 2 neighbors

// if there is cycle of len>2 no branching
// if there is cycle of len=2 branching can occur(max len) ,if there are multiple like this we can attach mutiples.

int maximumInvitations(vector<int>& fav) {
    int n=fav.size();
    vector<int>ind(n,0);
    vector<int>dep(n,1);
    int cyc=0,cyc2=0;

    for(int i=0;i<n;i++){
        ind[fav[i]]++;
    }
    queue<int>q;
    for(int i=0;i<n;i++){
        if(ind[i]==0){
            q.push(i);
        }
    }

    while(!q.empty()){
        int x=q.front();
        q.pop();
        int y=fav[x];

        dep[y]=max(dep[y],dep[x]+1);
        if(--ind[y]==0)q.push(y);
    }

    for(int i=0;i<n;i++){
        if(ind[i]==0)continue;

        int len=0,cur=i;
        while(ind[cur]!=0){
            ind[cur]=0;
            len++;
            cur=fav[cur];
        }
        if(len==2){
            cyc2+=dep[cur]+dep[fav[cur]];
        }
        else{
            cyc=max(cyc,len);
        }

    }
    return max(cyc,cyc2);

}

