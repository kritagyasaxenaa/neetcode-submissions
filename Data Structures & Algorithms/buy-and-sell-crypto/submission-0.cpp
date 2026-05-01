class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit=0;
        auto maxx=max_element(prices.begin(),prices.end());
        for(auto it=prices.begin();it!=prices.end();it++){
            if(*maxx-*it>profit){
                profit=*maxx-*it;
            }
            if(it+1>maxx){
                maxx=max_element(it+1,prices.end());
            }
        }
        return profit;   
    }
};