#include <bits/stdc++.h>
using namespace std;
using Long = long long;

const int MX = 1e5 + 5;
const int LG = 32 - __builtin_clz(MX);

struct SparseTable {
    pair<int, int> st[2 * MX][LG + 1]; //<min depth , node>

    void build(vector<pair<int, int>> &A) { // O(n log n)
        int n = A.size();
        for (int i = 0; i < n; i++) {
            st[i][0] = A[i];
        }
        for (int j = 1; (1 << j) <= n; j++) {
            for (int i = 0; i + (1 << j) <= n; i++) {
                st[i][j] = min(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
            }
        }
    }

    int query(int l, int r) { // O(1)
        int sz = r - l + 1;
        int lg = 31 - (__builtin_clz(sz));
        return min(st[l][lg], st[r - (1 << lg) + 1][lg]).second;
    }
} st;

struct Graph {
    vector<int> adj[MX];
    vector<pair<int, int>> euler;
    int first[MX];
    int depth[MX];
    int tIn[MX];
    int tOut[MX];
    int timer;

    void clear(int n) {
        for (int i = 1; i <= n; i++) {
            adj[i].clear();
        }
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void dfs(int u = 0, int p = -1) { // O(n)
        tIn[u] = timer++;
        first[u] = euler.size();
        euler.push_back({depth[u], u});
        for (int v : adj[u]) {
            if (v != p) {
                depth[v] = depth[u] + 1;
                dfs(v, u);
                euler.push_back({depth[u], u});
            }
        }
        tOut[u] = timer++;
    }

    void precalculate(int root = 1) { // O(n logn)
        euler.clear();
        depth[root] = 0;
        timer = 0;
        dfs(root);
        st.build(euler);
    }

    int lca(int u, int v) { // O(1) - Index 1
        int l = min(first[u], first[v]);
        int r = max(first[u], first[v]);
        return st.query(l, r);
    }

    bool isAncestor(int u, int v) { // is u ancestor of v ?
        return tIn[u] <= tIn[v] && tOut[u] >= tOut[v];
    }

    bool onPath(int A, int B, int C) { // is C on AB path ?
        int x = lca(A, B);
        if (C == x) return true;
        return isAncestor(C, A) xor isAncestor(C, B);
    }
} G;
