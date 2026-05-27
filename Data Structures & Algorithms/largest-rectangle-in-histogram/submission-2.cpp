class Solution {
public:
       vector<int>left(vector<int>& h){
        vector<int>ret(h.size(),0);
        stack<int>s;
        for(int i=0;i<h.size();i++){
            int count=0;
            if(s.empty()){
                ret[i]=i;
            }
            else{
                int k=s.top();
                while(s.empty()==false&&h[i]<=h[s.top()]){
                    count++;
                    k=s.top();
                    count+=ret[k];
                    s.pop();
                }
                     ret[i]=count;
            }
            s.push(i);
        }
        return ret;
    }
    vector<int>right(vector<int>& h){
        vector<int>ret(h.size(),0);
        stack<int>s;
        int n=h.size()-1;
        for(int j=0;j<h.size();j++){
            int count=0;
            int i=n-j;
            if(s.empty()){
                ret[i]=j;
            }
            else{
                int k=s.top();
                while(s.empty()==false&&h[i]<=h[s.top()]){
                    count++;
                    k=s.top();
                    count+=ret[k];
                    s.pop();
                }
                     ret[i]=count;
            }
            s.push(i);
        }
        return ret;
    }
    int largestRectangleArea(vector<int>& h) {
        // find left next min, find right next min
        vector<int>l=left(h);
        vector<int>r=right(h);
        int max=0;
        for(int i=0;i<h.size();i++){
            int sum=h[i]*(l[i]+r[i]+1);
            if(sum>max){
                max=sum;
            }
        }
        return max;
    }
};
