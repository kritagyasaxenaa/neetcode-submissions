class MedianFinder {
public:
// use 2 heaps
    priority_queue<float>max;
    priority_queue<float, vector<float>, greater<float>>min;
    int min_len=0;
    int max_len=0;
    MedianFinder() {
    }
    void addNum(int num) {
        if(min_len==0){
            min.push(num);
            min_len++;
            return;
        }
        if(num>=min.top()){
            min.push(num);
            min_len++;
        }
        else{
            max.push(num);
            max_len++;
        }
        if(min_len-max_len>1){
            max.push(min.top());
            min.pop();
            min_len--;
            max_len++;
        }
        if(max_len-min_len>1){
            min.push(max.top());
            max.pop();
            max_len--;
            min_len++;
        }
      return;
    }
    
    double findMedian() {
        float median;
        if(min_len>max_len){
            return min.top();
        }
        if(max_len>min_len){
            return max.top();
        }
        median=max.top()+min.top();
        median=median/2;
        return median;
    }
};
