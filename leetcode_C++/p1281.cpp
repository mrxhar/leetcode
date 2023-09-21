class Solution {
public:
    int subtractProductAndSum(int n) {
        int m = 1, s = 0;
        while (n) {
            m *= (n % 10);
            s += (n % 10);
            n /= 10;
        }
        return m - s;
    }
};