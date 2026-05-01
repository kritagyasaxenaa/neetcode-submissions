class Solution {
public:
    int getSum(int a, int b) {
        long long int c=2;
        long double k=pow(c,a);
        long double m=pow(c,b);
        k=k*m;
        m=log(k)/log(2);
        return (int)m;
    }
};
