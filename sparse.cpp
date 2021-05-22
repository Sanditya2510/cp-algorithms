//construction
ll f(ll a, ll b){
    //maybe min, max, sum, prod etc.
}
void init(){
    ll st[MAXN][K + 1];

    for (int i = 0; i < N; i++)
        st[i][0] = array[i];

    for (int j = 1; j <= K; j++)
        for (int i = 0; i + (1 << j) <= N; i++)
            st[i][j] = f(st[i][j-1] ,st[i + (1 << (j - 1))][j - 1]);
}

//for non-idempotent functions f(A)=A
ll query(ll L, ll R){
    long long sum = 0;
    for (int j = K; j >= 0; j--) {
        if ((1 << j) <= R - L + 1) {
            sum += st[L][j];
            L += 1 << j;
        }
    }
}

//for idempotent functions
ll query(ll L, ll R){
    int j = log[R - L + 1];
    int minimum = min(st[L][j], st[R - (1 << j) + 1][j]);
}