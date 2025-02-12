class Solution {
    public:
    
        long sum(int num){
            long  res=0;
            while(num>0){
                res+=num%10;
                num/=10;
            }
            return res;
        }
    
        int maximumSum(vector<int>& nums) {
            unordered_map<int, pair<int, int>> mp;
            long long ans = -1;
    
            for (int num : nums) {
                long val = sum(num);
                if (mp.find(val) != mp.end()) {
                    int first=mp[val].first;
                    int second=mp[val].second;
                    if (num>first) {
                        second=first;
                        first=num;
                    } 
                    else if(num>second)
                        second=num;
                    ans=max(ans,(long long)(first + second));
                    mp[val]={first,second};
                } else {
                    mp[val]={num,-1};
                }
            }
    
            return ans;
    
        }
    };