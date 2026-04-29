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
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
           vector<vector<string>>op;
            string temp="\0";
           for(int i=0;i!=strs.size();i++){
            vector<string>alpha;
            alpha.push_back(strs[i]);
            int j=i+1;
                while(j!=strs.size()){
                    if(isAnagram(strs[i],strs[j])){
                        alpha.push_back(strs[j]);
                        strs.erase(strs.begin()+j,strs.begin()+j+1);
                    }
                    else j++;
                }
                op.push_back(alpha);
           }
           return op;
    }
};
