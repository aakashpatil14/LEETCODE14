class Solution {
public:
    int convert(string& str){
        int cnt=0;
        for(int i=0;i<str.size();i++){
            cnt +=str[i]-'0';
        }
        return cnt;
    }
    int numberOfBeams(vector<string>& bank) {
        vector<int> count;
        for(auto str:bank){
            count.push_back(convert(str));
        }
        int ans=0;
        int i=0;
        int j=1;
        while(j<count.size()){
            if(count[i]==0){
                i=j;
                j++;
                continue;
            }
            if(count[j]==0){
                j++;
                continue;
            }
           int prev= count[i]*count[j];
            ans=ans+prev;
            i=j;
            j++;
        }
        return ans;
    }
};