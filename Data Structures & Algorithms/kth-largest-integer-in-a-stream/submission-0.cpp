class KthLargest {
public:
    stack <int>st;
    stack<int>residue;
    int k=-1;
    KthLargest(int a, vector<int>& nums) {
        k=a;
        sort(begin(nums),end(nums));
        for(int i=0;i<nums.size();i++){
            st.push(nums[i]);
        }
    }
    int add(int val) {
        int count=1;
        while((!st.empty())&&st.top()>=val){
            count++;
            residue.push(st.top());
            st.pop();
        }
        st.push(val);
        int ret;
        if(count<k){
            while(count<k){
                residue.push(st.top());
                st.pop();
                count++;
            }
            ret=st.top();
            while(count!=1){
                st.push(residue.top());
                residue.pop();
                count--;
            }
        }
        else{
            if(count==k){
                ret=st.top();
            }
            else{
                while(count!=k){
                    st.push(residue.top());
                    residue.pop();
                    count--;
                }
                ret=st.top();
            }
            while(count!=1){
                st.push(residue.top());
                residue.pop();
                count--;
            }
        }
        return ret;  
    }
};