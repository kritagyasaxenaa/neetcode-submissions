class Solution {
public:
    int largestRectangleArea(vector<int>& h) {
        // ek aur hai, i can store >= h[i] of both the sides along with its index
        int sum=0;
        int max=0;
        stack<int>s;
        vector<int>left,right;
        left.push_back(0);
        s.push(h[0]);
        for(int i=1;i<h.size();i++){
            stack<int>temp;
            int count=0;
            while((!s.empty())&&s.top()>=h[i]){
                count++;
                temp.push(s.top());
                s.pop();
            }
            left.push_back(count);
            while(!temp.empty()){
                s.push(temp.top());
                temp.pop();
            }
            s.push(h[i]);
        }
        int n=h.size()-1;
        stack<int>s2;
        s2.push(h[n]);
        right.push_back(0);
        for(int i=1;i<h.size();i++){
            stack<int>temp;
            int count=0;
            while((!s2.empty())&&s2.top()>=h[n-i]){
                count++;
                temp.push(s2.top());
                s2.pop();
            }
           right.push_back(count);
            while(!temp.empty()){
                s2.push(temp.top());
                temp.pop();
            }
            s2.push(h[n-i]);
        }
        reverse(right.begin(),right.end());
        for(int i=0;i<h.size();i++){
            sum=h[i]*(left[i]+right[i]+1);
            if(sum>max){
                max=sum;
            }
        }
        return max;
    }
};
