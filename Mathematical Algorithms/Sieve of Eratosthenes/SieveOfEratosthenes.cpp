// OJ: https://leetcode.com/problems/count-primes/
// Author: mandanshubham
// Time: O(NloglogN)
// Space: O(N)
// Ref: https://leetcode.com/problems/count-primes/solution/

class Solution {
public:
    int countPrimes(int n) {
        if(n <= 1) return 0;
        vector<bool> prime(n, true);
        
        int count = 0;
        for(int i=2; i*i<n; i++) {
            if(!prime[i]) continue;
            
            // note that we start from `i * i` instead of `2` because all multiples of `2, 3, ..., (i-1)` must be marked already
            for(int j=i*i; j<n; j+=i)
                prime[j] = 0;
        }
      
        for(int i=2; i<n; i++) {
            if(prime[i]) count++;
        }
        return count;
    }
};
