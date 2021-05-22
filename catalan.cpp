//1 1 2 5 14 42 132 429 1430 4862
// A Dynamic Programming based solution to compute nCr % p 
#include <bits/stdc++.h> 
using namespace std; 
 
// c[i]=sum(c[k]*c[n-k-1]) for k=0....n-1
// alternate c[i]=(1/(n+1))*2nCn

const int MOD = ....
const int MAX = ....
int catalan[MAX];
void init() {
    catalan[0] = catalan[1] = 1;
    for (int i=2; i<=n; i++) {
        catalan[i] = 0;
        for (int j=0; j < i; j++) {
            catalan[i] += (catalan[j] * catalan[i-j-1]) % MOD;
            if (catalan[i] >= MOD) {
                catalan[i] -= MOD;
            }
        }
    }
}
