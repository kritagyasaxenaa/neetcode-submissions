class Solution {
public:
    int reverse(int x) {
    long long int m=x;
       long long int k=0;
        bool sign=(x<0);
        if(sign)
            m=-m;
    while(m!=0){
        k=k*10;
        k=k+(m%10);
        m=m/10;
        if(k>2147483647)
            return 0;
    }   
    if(sign)
        k=-k;
    return (int)k;
    }
};