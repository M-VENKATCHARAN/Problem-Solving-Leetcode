class Solution {
    public:
    
        void func(vector<bool>&res,unordered_set<string>&st,string &tiles,string &temp){
            st.insert(temp);
    
            for(int i=0;i<tiles.size();i++){
                if(res[i])continue;
    
                
                temp.push_back(tiles[i]);
                res[i]=true;
                func(res,st,tiles,temp);
                res[i]=false;
                temp.pop_back();    
            }   
        }
        int numTilePossibilities(string tiles) {
            vector<bool>res(tiles.size(),false);
            unordered_set<string>st;
            string temp="";
            func(res,st,tiles,temp);
            return st.size()-1; //skip ""
        }
    };