// brute force approach This brute-force approach works only for small positive numbers and fails for many cases in LeetCode 29 (Divide Two Integers):
class Solution {
public:
    int divide(int dividend, int divisor) {
        int sum = 0;
        int count = 0;
        while(sum + divisor <= dividend){
            count++;
            sum += divisor;
        }
        return count;
    }
};

// optimal approach 

class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend== divisor) return 1;
        bool sign = true;
        if(dividend>=0 && divisor<0)  sign = false;
        else if(dividend<0 && divisor>0) sign = false;

        long long  n = abs((long long)dividend) , d = abs((long long)divisor);

        long long ans = 0;

        while(n>=d){
            int count = 0;
            while(n>=(d<<(count+1))){
                count++;
            }
            ans += (1LL<<count);
            n = n - (d*(1LL<<count));
        }
        if(ans == (1LL<<31) && sign) return INT_MAX;
        if(ans == (1LL<<31) && !sign) return INT_MIN;
        return sign ? ans : (-1 * ans);
    }
};