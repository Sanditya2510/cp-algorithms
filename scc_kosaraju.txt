// Strongly connected component is subset of vertices C 
// such that any two vertices of this subset are reachable 
// from each other, i.e. for any u,v∈C
// It is obvious, that strongly connected components do not 
// intersect each other, i.e. this is a partition of all graph vertices
// Thus we can give a definition of condensation graph GSCC as a 
// graph containing every strongly connected component as one vertex.
// The most important property of the condensation graph is that it is acyclic.

// When we transpose graph and travel in the same way as our original dfs
// call, then obviously the reverse edges would cause the control to stay inside
// the current component
    vector < vector<int> > g, gr;
    // gr transposed graph
    vector<bool> used;
    vector<int> order, component;

    void dfs1 (int v) {
        used[v] = true;
        for (size_t i=0; i<g[v].size(); ++i)
            if (!used[ g[v][i] ])
                dfs1 (g[v][i]);
        order.push_back (v);
    }

    void dfs2 (int v) {
        used[v] = true;
        component.push_back (v);
        for (size_t i=0; i<gr[v].size(); ++i)
            if (!used[ gr[v][i] ])
                dfs2 (gr[v][i]);
    }

    int main() {
        int n;
        ... reading n ...
        for (;;) {
            int a, b;
            ... reading next edge (a,b) ...
            g[a].push_back (b);
            gr[b].push_back (a);
        }

        used.assign (n, false);
        for (int i=0; i<n; ++i)
            if (!used[i])
                dfs1 (i);
        used.assign (n, false);
        for (int i=0; i<n; ++i) {
            int v = order[n-1-i];
            if (!used[v]) {
                dfs2 (v);
                ... printing next component ...
                component.clear();
            }
        }
    }