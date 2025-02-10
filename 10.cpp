class Solution {
    public:
        string clearDigits(string s) {
            stack<char>st;
            string res="";
            int i=0;
            while(i<s.length()){
                if(!isdigit(s[i]))
                    st.push(s[i]);
                else{
                    if(!st.empty())st.pop();
                }
                i++;
            }
    
            while(!st.empty()){
                res+=st.top();
                st.pop();
            }
            reverse(res.begin(),res.end());
            return res;
        }
    };