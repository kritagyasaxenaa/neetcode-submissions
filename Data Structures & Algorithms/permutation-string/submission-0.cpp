class Solution {
public:
    bool checkZero(int * arr){
         for(int i=0;i<26;i++){
            if(arr[i]>0){
                return false;
            }
        }
        return true;
    }

    bool checkInclusion(string s1, string s2) {
        if(s2.size()<s1.size()){
            return false;
        }
        int *arr= new int[26];
        for(int i=0;i<26;i++){
            arr[i]=0;
        }
        for(char i:s1){
            arr[i-'a']++;
        }
        int window=s1.size();   // window size
        int i=0;
        for(;i<window;i++){
            arr[s2[i]-'a']--;
        }
        bool temp=checkZero(arr);
            if(temp){
                return temp;
            }
        while(i<s2.size()){
            arr[s2[i]-'a']--;
            arr[s2[i-window]-'a']++;
            temp=checkZero(arr);
            if(temp){
                return temp;
            }
            i++;
        }
        return false;
    }
};
