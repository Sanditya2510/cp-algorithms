#include<bits/stdc++.h>
using namespace std;
#define etm cerr << "Time elapsed :" << clock() * 1000.0 / CLOCKS_PER_SEC << " ms" << '\n'
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long int
#define ull unsigned long long int
#define pb push_back
#define pii pair<int , int>
#define pdd pair<double , double>
#define pll pair<long long int,long long int>
#define vpl vector<pll >
#define vll vector<ll >
#define vb vector<bool>
#define vvbb vector<vb>
#define vi vector<int >
#define mi map<int, int>
#define mull map<ull, ull>
#define stp setprecision(20)
#define N 100005
#define rep(i,a,b,c)            for(int i=(a);i<=(b);i+=(c))
#define repb(i,a,b,c)           for(int i=(a);i>=(b);i-=(c))
#define MOD                     1000000007
#define ld                      long double
#define inf                     1e18
#define mp                      make_pair
#define vpll                    vector<pair<ll,ll>>
#define vvpll                   vector<vector<pair<ll,ll>>>
#define vvll                    vector<vector<ll>>
#define vvii			vector<vector<int>>
#define all(x)                  x.begin(),x.end()
#define fi                      first
#define se                      second
#define test                    ll T;cin>>T;while(T--)
#define show(w,size)            for(ll i=0;i<size;i++) cout<<w[i]<<" ";
#define umll                    unordered_map<ll,ll>
#define mll                     map<ll,ll>
#define countbit                __builtin_popcount // Number of set bits .
#define in                      insert
#define endl			              '\n'
//#define db(x) cout <<#x<<": "<<x<<'\n';
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
using namespace std;
#define db(...)                 __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) { cerr << name << " : " << arg1 <<'\n'; }
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
    const char* comma = strchr(names + 1, ',');
    cerr.write(names, comma - names) << " : " << arg1 << " | "; __f(comma + 1, args...);
}
ll gcd(ll a,ll b){if(a<b)return gcd(b,a);else if(b==0)return a;else return gcd(b,a%b);}
ll isPrime(ll n){ll p=(ll)sqrt(n);rep(i,2,p,1) if(n%i==0) return 0;return 1;}// reuturn 1 if prime
ll pow(ll b,ll e){if(e==0)return 1;else if(e%2==0){ll a=pow(b,e/2);return a*a;}else {ll a=pow(b,e/2);return b*a*a;}}
ll powm(ll x,ll y,ll m=MOD){x=x%m;ll res=1;while(y){if(y&1)res=res*x;res%=m;y=y>>1;x=x*x;x%=m;}return res;}
ll modInverse(ll a, ll m) { return powm(a, m-2, m);}

/*
ideas
*/

void solve(){
  
}

int main(){
  fastio;
  // int T=1;
  int T;cin>>T;
  while(T--){
    solve();
  }
  return 0;
}