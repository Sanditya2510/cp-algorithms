//hash for same strings are same but converse is not
//true
long long compute_hash(string const& s) {
    const int p = 31;//53 if a-z, A-Z
    const int m = 1e9 + 9;
    long long hash_value = 0;
    long long p_pow = 1;
    for (char c : s) {
        hash_value = (hash_value + (c - 'a' + 1) * p_pow) % m;
        p_pow = (p_pow * p) % m;
    }
    return hash_value;
}
//check cp-algorithms page for subtring hash calculation
// for substring hash s[i....j]=(hash[j]-hash[i-1])*modinv(pow(p, i)) mod m