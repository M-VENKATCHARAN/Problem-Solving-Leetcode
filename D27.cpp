#include <math.h>
#include <vector>
using namespace std;
#include <map>
#include <limits.h>
#include <unordered_map>
#include <numeric>
#include <queue>
#include <algorithm>

// Store outdegree nodes and indegree
// while queue not empty store prereq of each node
// check if quereies are valid 

class Solution {
public:
    vector<bool> checkIfPrerequisite(int num, vector<vector<int>>& pre, vector<vector<int>>& queries) {
        int n=num;
        vector<vector<int>>out(n);
        vector<int>ind(n,0);

        for(vector<int>a:pre){
            out[a[0]].push_back(a[1]);
            ind[a[1]]++;
        }
        queue<int>q;
        for(int i=0;i<n;i++){
            if(ind[i]==0){
                q.push(i);
            }
        }
        vector<unordered_set<int>>pre1(n);
        while(!q.empty()){
            int x=q.front();
            q.pop();

            for(auto y:out[x]){
                pre1[y].insert(x);
                for(int z:pre1[x]){
                    pre1[y].insert(z);
                }
                if(--ind[y]==0)q.push(y);
            }
        }
        vector<bool>ans;
        int n2=queries.size();
        for(int i=0;i<n2;i++){
            ans.push_back(pre1[queries[i][1]].count(queries[i][0]));
        }
        return ans;
    }
};