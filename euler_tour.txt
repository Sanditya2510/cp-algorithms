// this is euler tour 1, creates like this
// 1 2 3 2 4 2 1
void eulerTree(int u, int &indx) 
{ 
    vis[u] = 1; 
    Euler[indx++] = u; 
    for (auto it : adj[u]) { 
        if (!vis[it]) { 
            eulerTree(it, indx); 
            Euler[indx++] = u; 
        } 
    } 
} 
  
// Function to print Euler Tour of tree 
void printEulerTour(int root, int N) 
{ 
    int index = 0;   
    eulerTree(root, index); 
    for (int i = 0; i < (2*N-1); i++) 
        cout << Euler[i] << " "; 
} 

// For euler tour 2 it looks something like this 1 2 3 3 4 4 2 5 5 6 1
// significance is that when a nodne appears 2nd time, its subtree has been scanned
// When you want to add a value v to the subtree, maintain a fenwick tree, and do +=v 
// on in[node] and -=v on out[node]. Path sum query can be broken down to sum from root 
// to any node. For the root to node sum query, just return prefix sum of in[node] from BIT.