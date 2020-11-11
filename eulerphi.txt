//euler phi for a number
int phi(int n) {
    int result = n;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            while (n % i == 0)
                n /= i;
            result -= result / i;
        }
    }
    if (n > 1)
        result -= result / n;
    return result;
}

// Euler totient function from 1 to n in  O(nloglogn)
void phi_1_to_n(int n) {
    vector<int> phi(n + 1);
    phi[0] = 0;
    phi[1] = 1;
    for (int i = 2; i <= n; i++)
        phi[i] = i;

    for (int i = 2; i <= n; i++) {
        if (phi[i] == i) {
            for (int j = i; j <= n; j += i)
                phi[j] -= phi[j] / i;
        }
    }
}

// a^n≡a^(n mod(ϕ(m)))(modm) when a and m are coprime
// This allows computing xnmodm for very big n, especially if n is the result of another computation, as it allows to compute n under a modulo.

// x^n≡x^(ϕ(m)+[nmodϕ(m)])modm
// There is a less known version of the last equivalence, that allows computing xnmodm efficiently for not coprime x and m. For arbitrary x,m and n≥log2m: