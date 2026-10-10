class Solution {
public:
    string longestPalindrome(string s) {
        // if palindrome is of odd length:
        string ret;
        int len=0;
        for(int i=0;i<s.size();i++){
            int l=i,r=i;
            while(l>=0&&r<s.size()&&s[l]==s[r]){
                l--,r++;
            }
            l++,r--;
            if(len<r-l+1){
                len=r-l+1;
                ret=s.substr(l,r-l+1);
            }
        }
        // if string of even length
        for(int i=0;i<s.size();i++){
            int l=i,r=i+1;
             while(l>=0&&r<s.size()&&s[l]==s[r]){
                l--,r++;
            }
            l++,r--;
            if(len<r-l+1){
                len=r-l+1;
                ret=s.substr(l,r-l+1);
            }
        }
        return ret;
    }
};
