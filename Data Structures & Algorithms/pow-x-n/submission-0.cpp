class Solution {
public:
    double myPow(double x, int n) {
        // square and multiply 
        if(n==0){
            return 1;
        }
        double ret=1;
        double a=x;
        if(n>0)
        while(n!=0){
            if(n&1){
                ret=ret*a;
            }
            n=n/2;
            a=a*a;
        }
        else{// n<0
            n=-n;
            a=1/x;
        while(n!=0){
                if(n&1){
                    ret=ret*a;
                }
                n=n/2;
                a=a*a;
            }
        }
        return ret;
    }
};
