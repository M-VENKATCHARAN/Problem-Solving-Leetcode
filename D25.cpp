// make-lexicographically-smallest-array-by-swapping-elements

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
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n=nums.size();
        vector<pair<int,int>>index;
        for(int i=0;i<n;i++){
            index.push_back({nums[i],i});
        }
        sort(index.begin(),index.end());
        vector<vector<int>>s={{index[0].second}};
        for(int i=1;i<n;i++){
            if(index[i].first-index[i-1].first<=limit){
                s.back().push_back(index[i].second);
            }
            else{
                s.push_back({index[i].second});
            }
        }

        for(auto it:s){
            vector<int>sorted;
            for(int x:it)sorted.push_back(nums[x]);
            sort(sorted.begin(),sorted.end());
            sort(it.begin(),it.end());
            for(int i=0;i<it.size();i++){
                nums[it[i]]=sorted[i];
            }
        }
        return nums;
    }
};