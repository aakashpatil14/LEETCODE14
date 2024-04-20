// class Solution {
// public:
//     int sumOfEncryptedInt(vector<int>& nums) {

//         int sum=0;
//         for(auto n:nums){
//             int count =0;
//             int t=0;
//             int max=0;
//             while(n){
//                 max=(max,n%10);
//                 count++;
//                 n /=10;
//             }
//             while(count){
//                 t=t*10+max;
//                 count--;
//             }
//             sum +=t;
            
//         }
//         return sum;
//     }
// };
class Solution{
    public:
int sumOfEncryptedInt(vector<int>& nums) {
    int sum = 0;
    for(auto n: nums){
        int count = 0, mx = 0, t = 0;
        while(n){
            mx = max(mx, n%10);
            n = n/10;
            count++;
        }
        while(count){
            t = t*10 + mx;
            count--;
        }
        sum += t;
    }
    return sum;
}
};