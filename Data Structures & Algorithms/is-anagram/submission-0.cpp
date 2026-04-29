class Solution {
public:
    bool isAnagram(string s, string t) {
        int arr[26]={0};
      for(char a:s){
        arr[a-'a']++;
      }
      for(char a:t){
        arr[a-'a']--;
      }
      for(int i:arr){
            if(i!=0){
                return false;
            }
      }
      return true;
    }
};
