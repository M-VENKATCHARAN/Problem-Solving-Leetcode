class Solution {
    public:
        //calculate good pairs first;
        long long countBadPairs(vector<int>& nums) {
            long long ans=0;
            unordered_map<int,int>mp;
            long long n=nums.size();
    
            for(int i=0;i<n;i++){
                int val=nums[i]-i;
                ans+=mp[val];
                mp[val]++;
            }
    
            return (n*(n-1))/2-ans;
        }
    };