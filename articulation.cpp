#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<int> low, tin;
int n, timer=0;
vector<bool> vis;

void dfs(int u, int pu=-1){
    int ch=0;
    tin[u]=low[u]=++timer;
    for(auto v: adj[u]){
        if(v==pu)continue;
        if(vis[v]){
            low[u]=min(low[u], tin[v]);
        }
        else{
            dfs(v, u);
            ch++;
            low[u]=min(low[u], low[v]);
            if(low[v]>=tin[u] and pu!=-1)is_cutpoint(u);
        }
    }
    if(pu==-1 and ch>0)is_cutpoint(u);
}
