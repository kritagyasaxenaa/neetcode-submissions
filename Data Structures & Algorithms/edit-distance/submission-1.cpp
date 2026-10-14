class Solution {
public:
    int minDistance(string word1, string word2) {
     int a=word1.size();
     a++;
     int b=word2.size();
     b++;
     vector<vector<int>>v;
     for(int i=0;i<a;i++){
        vector<int>temp(b,0);
        v.push_back(temp);
     }   
     for(int i=0;i<b;i++){
        v[0][i]=i;
     }
     for(int i=0;i<a;i++){
        v[i][0]=i;
     }
     for(int i=1;i<a;i++){
        for(int j=1;j<b;j++){
            if(word1[i-1]==word2[j-1]){
                v[i][j]=v[i-1][j-1];
            }
            else{
                v[i][j]=v[i-1][j-1]+1;
            }
            int var=min(v[i-1][j],v[i][j-1])+1;
            v[i][j]=min(v[i][j],var);
        }
     }
     return v.back().back();
    }
};
