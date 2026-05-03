class Solution {
public:
int characterReplacement(string s, int k) {
        if(s.size()==0||s.size()==1){
            return s.size();
        }
     int max=0; // max size of the window
     int size=1;// current size of the window   
     vector<int> alph;
     for(int i=0;i<26;i++){
        alph.push_back(0);
     }
     alph[s[0]-'A']++;
     int i=1;
     while(i<s.size()&&(k+*max_element(alph.begin(),alph.end())>size)){
            alph[s[i]-'A']++;
            size++;
            i++;
        }
        max=size;
     for(;i<s.size();i++){
        alph[s[i]-'A']++;
        if((k+*max_element(alph.begin(),alph.end())>size)){
            while((k+*max_element(alph.begin(),alph.end())>size)){
                size++;
            }
            
        }
        else{
            alph[s[i-size]-'A']--;
        }
        if(max<size){
            max=size;
        }
     }
     return max;
    }
};
