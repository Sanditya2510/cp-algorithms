// Tarjans algo for finding articulation point
// An articulation point (or cut vertex) is defined as a 
// vertex which, when removed along with associated edges, 
// makes the graph disconnected (or more precisely, increases 
// the number of connected components in the graph).
// for some node u in dfs if its connected to v and neither
// v or any of its descendants in dfs has any back-edge to ancestor
// of u, then v is an  articulation point.But this is when u!=root  
// if u=root, then This vertex will be the point of articulation if 
// and only if this vertex has more than one child in the DFS tree. 
int n; // number of nodes
vector<vector<int>> adj; // adjacency list of graph

vector<bool> visited;
vector<int> tin, low;//low[i] is the min time which I can reach from my subgraph.
int timer;

void dfs(int v, int p = -1) {
    visited[v] = true;
    tin[v] = low[v] = timer++;
    int children=0;
    for (int to : adj[v]) {
        if (to == p) continue;
        if (visited[to]) {
            low[v] = min(low[v], tin[to]);//back-edge, so we find the lowest time to reach the current  node
        } else {
            dfs(to, v);
            low[v] = min(low[v], low[to]);
            if (low[to] >= tin[v] && p!=-1)
                IS_CUTPOINT(v);//its a cutpoint change to whatever needs to be done
            ++children;
        }
    }
    if(p == -1 && children > 1)
        IS_CUTPOINT(v);//its a cutpoint change to whatever needs to be done
}

void find_cutpoints() {
    timer = 0;
    visited.assign(n, false);
    tin.assign(n, -1);
    low.assign(n, -1);
    for (int i = 0; i < n; ++i) {
        if (!visited[i])
            dfs (i);
    }
}
