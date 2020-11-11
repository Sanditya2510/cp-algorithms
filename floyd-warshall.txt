// no negative weight cycles (for then the shortest path is undefined).
// This algorithm can also be used to detect the presence of negative cycles. 
// The graph has a negative cycle if at the end of the algorithm, the distance 
// from a vertex v to itself is negative.
// nice proof on cp-algorithms

#define MAXN 100 
// Infinite value for array 
const int INF = 1e7; 
  
int dis[MAXN][MAXN]; 
int Next[MAXN][MAXN]; 


vector<int> constructPath(int u, 
                          int v) 
{ 
    if (Next[u][v] == -1) 
        return {}; 
  
    vector<int> path = { u }; 
    while (u != v) { 
        u = Next[u][v]; 
        path.push_back(u); 
    } 
    return path; 
} 
void floydWarshall(int V) 
{ 
    for (int k = 0; k < V; k++) { 
        for (int i = 0; i < V; i++) { 
            for (int j = 0; j < V; j++) { 
                if (dis[i][k] == INF 
                    || dis[k][j] == INF) 
                    continue; 
  
                if (dis[i][j] > dis[i][k] 
                                    + dis[k][j]) { 
                    dis[i][j] = dis[i][k] 
                                + dis[k][j]; 
                    Next[i][j] = Next[i][k]; 
                } 
            } 
        } 
    } 
} 