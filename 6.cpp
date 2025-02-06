class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int>mp;
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int prod=nums[i]*nums[j];
                mp[prod]++;
            }
        }

        for(auto it:mp){
            int x=it.second;
            if(x>1){
                cnt+=(x*(x-1))/2;
            }
        }
        return cnt*8;
    }
};