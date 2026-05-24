class Solution {
public:

    bool CheckAll(int* up, int* low){
        for(int i=0;i<26;i++){
            if(up[i]>0){
                return false;
            }
            if(low[i]>0){
                return false;
            }
        }
        return true;
    }
    int Check(int* up, int* low, char a){
         if(a>='A'&&a<='Z'){
                return up[a-'A'];
            }
        else if(a>='a'&&a<='z'){
                return low[a-'a'];
        }
        return 0;
    }
    string minWindow(string s, string t) {
        string r;
        int up[26]={0};
        int low[26]={0};
        bool found=false;
        for(char a: t){
            if(a>='A'&&a<='Z'){
                up[a-'A']++;
            }
            else if(a>='a'&&a<='z'){
                low[a-'a']++;
            }
        }
        int start =0, end=0;
        int front=start,rear=end;
        int mi=s.size();
       while(end<s.size()){
        char a=s[end];
            if(a>='A'&&a<='Z'){
                up[a-'A']--;
            }
            else if(a>='a'&&a<='z'){
                low[a-'a']--;
            }
        end++;

        while((!CheckAll(up,low))&&(end<s.size())){
            char a=s[end];
            if(a>='A'&&a<='Z'){
                up[a-'A']--;
            }
            else if(a>='a'&&a<='z'){
                low[a-'a']--;
            }
            end++;
        } 
        while(Check(up,low,s[start])<0&&start<=end){
            char a=s[start];
            if(a>='A'&&a<='Z'){
                up[a-'A']++;
            }
            else if(a>='a'&&a<='z'){
                low[a-'a']++;
            }
            start++;
        }
        if(CheckAll(up,low)&&mi>=end-1-start+1){
            front=start;
            rear=end-1;
            mi=rear-front+1;
            found=true;
        }
       }
       if(found)
        for(int i=front;i<=rear;i++){
            r=r+s[i];
        }
    return r;
    }
};
