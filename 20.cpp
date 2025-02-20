class Solution {
    public:
    
    //a new binary string can only be new if it has at least 1 bit that's different compared to every other binary string. 
        string findDifferentBinaryString(vector<string>& nums) {
            string res="";
            int n=nums.size();
            int val=0;
            for(int i=0;i<n;i++){
                if(nums[i][i]-'0'==1)
                    res=res+to_string(0);
                else 
                    res=res+to_string(1);
            }
            return res;
        }
};