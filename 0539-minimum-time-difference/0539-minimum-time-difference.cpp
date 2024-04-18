class Solution {
public:
    int convert(string& time){
        int hrs=stoi(time.substr(0,2));
        int min=stoi(time.substr(3,2));
        return 60*hrs+min;
    }
    int findMinDifference(vector<string>& timePoints) {
        vector<int> mini;
        for(auto time:timePoints){
           mini.push_back(convert(time));
        }
        sort(mini.begin(),mini.end());
        int ans=INT_MAX;
        for(int i=0;i<mini.size()-1;i++){
            ans=min(ans,mini[i+1]-mini[i]);
        }
        int lastdiff=mini[0]+1440-mini[mini.size()-1];
        ans=min(ans,lastdiff);
        return ans;
        
    }
};