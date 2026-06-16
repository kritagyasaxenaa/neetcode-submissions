class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>>heap;
    int k;
    KthLargest(int k, vector<int>& nums) {
        // since one does not have to delete just store the top k elements in a min heap
        this->k=k;
        for(int &i : nums){
            heap.push(i);
        }    
    }
    int add(int val) {
        heap.push(val);
        while(heap.size()>k){
            heap.pop();
        }
        return heap.top();   
    }
};
