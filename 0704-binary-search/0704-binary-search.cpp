class Solution {
public:
    int bs(vector<int>& nums, int target,int s,int e){
        if(s>e){
            return -1;
        }
        int mid=s+(e-s)/2;
        if(nums[mid]==target){
            return mid;
        }
        else if(nums[mid]>target){
            return bs(nums,target,s,mid-1);   
        } else{
            return bs(nums,target,mid+1,e);
        }
    }
    
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        int s=0;
        int e=n-1;
        int ans=bs(nums,target,s,e);
        return ans;
    }
};