#include <iostream>
#include <stack>
#include <queue>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <climits>
#include <string>
#include <unordered_map>
#include <map>
#include <set>
#include <ctime>
#include <algorithm>
#include <cstring>
using namespace std;

int odd=0;
int even=0;

void dfs(int u, vector<bool>& visited, vector<int>& disc, vector<int>& low,
int parent, stack<pair<int, int> >& stk, vector<vector<int> >& adjList){
static int time=1;
disc[u] = low[u] = time++;
visited[u] = true;
int child=0;
int count=0;
for (auto& ele: adjList[u]){
if (!visited[ele]){
child++;
stk.push({u, ele});
dfs(ele, visited, disc, low, u, stk, adjList);
low[u] = min(low[u], low[ele]);

if ((parent==-1 && child>1) || (parent!=-1 && low[ele]>=disc[u])){
while (stk.top().first != u && stk.top().second != ele){
cout<<stk.top().first<<" "<<stk.top().second<<"       ";
stk.pop();
}
cout<<stk.top().first<<" "<<stk.top().second<<"      ";
cout<<endl;
stk.pop();
}
}else if (ele != parent && disc[ele]<low[u]){
low[u] = disc[ele];
stk.push({u, ele});
}
}
}

int main() {
int n, m;
cin >> n >> m;
vector<vector<int> > adjList(n+1);
for (int i=0;i<m;i++){
int a, b;
cin >> a >> b;
adjList[a].push_back(b);
adjList[b].push_back(a);
}

vector<bool> visited(n+1, false);
vector<int> disc(n+1, INT_MAX);
vector<int> low(n+1, INT_MAX);
stack<pair<int, int> > stk;
for (int i=0;i<n;i++){
if (!visited[i]){
int count=0;
dfs(i, visited, disc, low, -1, stk, adjList);
while (!stk.empty()){
cout<<stk.top().first<<" "<<stk.top().second<<"      ";
stk.pop();
}
// if (count != 0)
// if (count&1) odd++;
// else even++;
}
}

// cout << odd << " " << even << endl;
return 0;
}