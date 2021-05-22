// pi f

vector<int> pi(n);
rep(i, 1, n-1, 1){
    int j=pi[i-1];
    while(s[i]!=s[j] and j>0)j=pi[j-1];
    if(s[i]==s[j])j++;
    pi[i]=j;
}


// abacccabac
// 0010001234
// -211000000