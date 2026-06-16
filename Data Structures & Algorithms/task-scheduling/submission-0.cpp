class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        char arr[26]={0};   // acts as a map
        for(char &i: tasks){
            arr[i-'A']++;
        }
        int max_freq=0, count=0;
        char max;
        // find the char with max frequency, and how many are there
        for(int i=0;i<26;i++){
            if(arr[i]>max_freq){
                max_freq=arr[i];
            }
        }
        for(int i=0;i<26;i++){
            if(arr[i]==max_freq){
                max=arr[i]+'A';
                count++;
            }
        }
        int op=(max_freq-1)*(n+1)+count;
        return op>tasks.size()?op:tasks.size();

    }
};
