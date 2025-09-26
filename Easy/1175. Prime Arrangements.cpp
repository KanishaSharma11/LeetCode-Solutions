class Solution {
public:
    int numPrimeArrangements(int n) {
        const  int MOD = 1000000007;
        if(n == 0){
            return 1;
        }

        vector<bool> is_prime(n + 1, true);
        is_prime[0] = is_prime[1] = false;
        for(int i = 2; i * i <= n; i++){
            if(is_prime[i]){
                for(int j = i * i; j <= n; j+=i){
                    is_prime[j] = false;
                }
            }
        }

        int P = 0;
        for(int i = 2; i <= n; i++){
            if(is_prime[i]){
                ++P;
            }
        }

        long long factP = 1;
        for(int i = 1; i <= P; i++){
            factP = factP * i % MOD;
        }

        int rest = n - P;
        long long  factR = 1;
        for(int i = 1; i <= rest; i++){
            factR = factR * i % MOD;
        }

        long long ans = factP * factR % MOD;
        return (int)ans;
    }
};
