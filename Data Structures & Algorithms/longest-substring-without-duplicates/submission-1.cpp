class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // kyuki it is contiguous, I would use sliding window
        int max=0;
        int size=0;
        unordered_map<char,int>m;
        for(int i=0;i<s.size();i++){
            // if adding char to the window is possible 
            char a=s[i];
            if(m[a]==0){
                m[a]++;
                size++;
                if(max<size){
                    max=size;
                }
            }
            else{   // else shrink the window until the previous instance of it is out of the window
                size++;
                while(s[i+1-size]!=a){
                         m[s[i+1-size]]--;
                    size--;
               
                }
                size--;
            }
        }
        return max;
    }
};
