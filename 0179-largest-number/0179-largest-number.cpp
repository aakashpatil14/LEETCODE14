class Solution {
public:
      static bool mycomp(string a,string b){
            string t=a+b;
            string t2=b+a;
            return t>t2;
        }
    string largestNumber(vector<int>& nums) {
      
        vector<string> snums;
        for(auto n:nums){
            snums.push_back(to_string(n));
        }
        sort(snums.begin(),snums.end(),mycomp);
        if(snums[0]=="0"){
            return "0";
        }
        string ans="";
        for(int i=0;i<snums.size();i++){
            ans +=snums[i];
        }
        return ans;
    }
};