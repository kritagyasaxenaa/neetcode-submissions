class MedianFinder {
public:
    vector<float>nums;
    MedianFinder() {
        
    }
    float median;
    int len=0;
    void addNum(int num) {
      nums.push_back(num);
      len++;
      sort(nums.begin(),nums.end());
      if(len%2!=0){
        median=nums[len/2];
      }
      else{
        median=(nums[len/2]+nums[len/2-1])/2;
      }
      return;
    }
    
    double findMedian() {
        return median;
    }
};
