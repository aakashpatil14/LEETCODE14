// class Info
// {
//     public:
//         char ch;
//         int count;

//         Info(char ch, int count){
//             this->ch = ch;
//             this->count = count;
//         }
// };

// class Compare
// {
//     public:
//         bool operator()(Info* first, Info* second){
//             return first->count < second->count;
//         }
// };

// class Solution {
// public:
//     string reorganizeString(string s) {
//        // Step 1: store frequency of all characters in an array
//        int frequency[26] = {0};
//        for(int i=0; i<s.length(); i++){
//            frequency[s[i]-'a']++;
//        }

//        // Step 2: create max heap to push all characters frequency where frequency[i] > 0
//        priority_queue<Info*, vector<Info*>, Compare> maxHeap;
//        for(int i=0; i<26; i++){
//            if(frequency[i]>0){
//                Info* tempNode = new Info(i+'a', frequency[i]);
//                maxHeap.push(tempNode);
//            }
//        }

//        // Step 3: reorganize the string
//        string ans = "";
//        while(maxHeap.size() > 1){
//            // get two characters from maxHeap
//            Info* first = maxHeap.top();
//            maxHeap.pop();
//            Info* second = maxHeap.top();
//            maxHeap.pop();
           
//            // push both got characetr into ans string 
//            // update the count of both
//            ans.push_back(first->ch);
//            first->count--;
//            ans.push_back(second->ch);
//            second->count--;
           
//            // Agar dono ke count > 0 hai to fir se maxHeap me unhe push kardo
//            if(first->count > 0){
//                maxHeap.push(first);
//            }
//            if(second->count > 0){
//                maxHeap.push(second);
//            }
//        }

//        // abhi maxHeap me last character bacha huaa hai to 
//        // usse bhi push krdo ans me
//        if(maxHeap.size() == 1){
//            Info* last = maxHeap.top();
//            maxHeap.pop();

//            ans.push_back(last->ch);
//            last->count--;

//            // Agar abhi bhi last character ki frequency > 0 hai 
//            // iska mtlb string reorganize nhi ki za skti hai
//            if(last->count > 0){
//                return "";
//            }
//        }

//        // Yanha me jabhi tab pahunch paya hu jab string organize ho gyi hogi
//        return ans;
    
//     }
// }
class Solution {
    public:
    string reorganizeString(string s) {
      char mostfreqch;
      int hash[26]={0};
      int maxfreq=INT_MIN;
      for(int i=0;i<s.size();i++){
          hash[s[i]-'a']++;
      }
      for(int i=0;i<26;i++){
          if(hash[i]>maxfreq){
              maxfreq=hash[i];
              mostfreqch=i+'a';
          }
      }
        int index=0;
      while(index<s.size()&&maxfreq>0){
          s[index]=mostfreqch;
          maxfreq--;
          index +=2;
      }
      if(maxfreq!=0){
          return "";
      }
        hash[mostfreqch - 'a']=0;
      for(int i=0;i<26;i++){
          while(hash[i]>0){
              index=index>=s.size() ? 1:index;
              s[index]=i+'a';
              index+=2;
              hash[i]--;
          }
      }
        return s;
        
        
        
        
        
        
        
        
    }
};
        
        
        
        
        
        
        