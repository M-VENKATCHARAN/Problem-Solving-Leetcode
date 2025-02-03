class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n=nums.size();
        int inc=1,inc_m=1,dec=1,dec_m=1;
        for(int i=0;i<n-1;i++){
            if(nums[i]<nums[i+1])
                inc++;
            else{
                inc_m=max(inc_m,inc);
                inc=1;}
            if(nums[i]>nums[i+1])
                dec++;
            else{
                dec_m=max(dec_m,dec);dec=1;}
        }
        inc_m=max(inc_m,inc);
        dec_m=max(dec_m,dec);
        return max(inc_m,dec_m);
    }
};