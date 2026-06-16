class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int>heap;
        for(int &i: stones){
            heap.push(i);
        }
        while(heap.size()>1){
            int a=heap.top();
            heap.pop();
            int b=heap.top();
            heap.pop();
            if(a==b){
                continue;
            }
            else{
                int c=abs(a-b);
                heap.push(c);
            }
        }
        if(heap.size()>0){
            return heap.top();
        }
        return 0;
    }
};
