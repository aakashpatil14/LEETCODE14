class Solution {
public:
    int lengthOfLastWord(string s) {
        int ans=0;
        int i=s.size()-1;
        while(i>=0){
            if(s[i] != ' '){
                break;
            }
            i--;
        }
        while(i>=0){
            if(s[i]==' '){
                break;
            }
            i--;
            ans++;
        }
        return ans;
    }
};