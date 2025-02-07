class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        unordered_map<int,int>mp;
        unordered_map<int,int>fre;
        vector<int>res;
        int cnt=0;
        for(auto it:queries){
            int x=it[0];
            int y=it[1];

            if(mp.find(x)!=mp.end()){
                int z=mp[x];
                fre[z]--;
                if(fre[z]==0)cnt--;
            }
            mp[x]=y;
            if(fre[y]==0)cnt++;
            fre[y]++;
            res.push_back(cnt);
        }
        return res;
    }
};