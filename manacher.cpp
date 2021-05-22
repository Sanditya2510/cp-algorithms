// Manacher's Algorithm
// 
// Given a string s, computes the length of the longest
// palindromes centered in each position (for parity == 1)
// or between each pair of adjacent positions (for parity == 0)
//
// Usage:
// Manacher("abacaba", 1) => {0, 1, 0, 3, 0, 1, 0}
// Manacher("a#a#b#b#a#a", 0) => {1, 0, 3, 0, 1}
vector<int> Manacher(string s, bool parity) {
    int n = s.size(), z = parity, l = 0, r = 0;
    vector<int> ret(n - !z, 0);
    
    for (int i = 0; i < n - !z; ++i) {
        if (i + !z < r) ret[i] = min(r - i, ret[l + r - i - !z]);
        int L = i - ret[i] + !z, R = i + ret[i];
        while (L - 1 >= 0 && R + 1 < n && s[L - 1] == s[R + 1]) 
            ++ret[i], --L, ++R;
        if (R > r) l = L, r = R;
    }
    
    return ret;
}


// my code
// vector<int> d1(n);
// for (int i = 0, l = 0, r = -1; i < n; i++) {
//     int k = (i > r) ? 1 : min(d1[l + r - i], r - i + 1);
//     while (0 <= i - k && i + k < n && s[i - k] == s[i + k]) {
//         k++;
//     }
//     d1[i] = k--;
//     if (i + k > r) {
//         l = i - k;
//         r = i + k;
//     }
// }

// vector<int> d2(n);
// for (int i = 0, l = 0, r = -1; i < n; i++) {
//     int k = (i > r) ? 0 : min(d2[l + r - i + 1], r - i + 1);
//     while (0 <= i - k - 1 && i + k < n && s[i - k - 1] == s[i + k]) {
//         k++;
//     }
//     d2[i] = k--;
//     if (i + k > r) {
//         l = i - k - 1;
//         r = i + k ;
//     }
// }