// prefix function, pi[i] is the length of the 
// longest proper prefix of the substring s[0…i]
// which is also a suffix of this substring. 
// pi[i+1]<=pi[i]+1, we basically find the occurences
// of the patterns in string, If the character dont match
// maybe they will on the previous occurence of this pattern
// txt-abababccc
// pat-abababf
//     0012340
vector<int> prefix_function(string s) {
    int n = (int)s.length();
    vector<int> pi(n);
    for (int i = 1; i < n; i++) {
        int j = pi[i-1];
        while (j > 0 && s[i] != s[j])
            j = pi[j-1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }
    return pi;
}