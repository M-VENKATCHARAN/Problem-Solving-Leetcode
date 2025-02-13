class Solution {
    public:
        int minOperations(vector<int>& nums, int k) {
            priority_queue<long,vector<long>,greater<>>pq(nums.begin(),nums.end());
            int cnt=0;
            while(!pq.empty() && pq.top()<k){
                long x=pq.top();pq.pop();
                long y=pq.top();pq.pop();
                pq.push(min(x,y)*2+max(x,y));
                cnt++;
            }
            return cnt;
        }
    };