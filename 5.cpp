class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int ind=-1;
        for(int i=0;i<s1.length();i++){
            if(s1[i]!=s2[i]){
                if(ind==-1)ind=i;
                else{
                    swap(s1[i],s1[ind]);
                    return s1==s2;
                }
            }
        }
        return s1==s2;
    }
};