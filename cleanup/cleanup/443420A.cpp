#include <bits/stdc++.h>
using namespace std;

// Structure for DSU rollback operations.
// type==0: union operation, type==1: deletion operation.
struct DSUOperation {
    int type; // 0 for union, 1 for deletion; if type == -1, it means no-op.
    int u;    // For union: the node attached; for deletion: the node deleted.
    int rep;  // For union: the representative that remains; for deletion: representative of deleted node.
    int parent;         // Previous parent pointer for the attached node.
    int oldSize;        // Old component size (for union).
    int oldActiveCount; // Old active count of the representative.
};

//
// DSU with rollback support.
// It stores for each node:
//  - parent and size (for union heuristic)
//  - active (true if the node hasn’t been removed)
//  - activeCount (the number of active nodes in the component)
//
struct DSU {
    int n;
    vector<int> parent, size, activeCount;
    vector<bool> active;
    vector<DSUOperation> ops;
    
    DSU(int n) : n(n) {
        parent.resize(n);
        size.assign(n, 1);
        active.assign(n, true);
        activeCount.assign(n, 1);
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }
    
    // Simple find (without path compression so that rollback is easier)
    int find(int a) {
        while(a != parent[a])
            a = parent[a];
        return a;
    }
    
    // Union two sets; record the changes so we can roll back.
    void unionSet(int a, int b) {
        a = find(a), b = find(b);
        if(a == b) {
            // record a dummy op so that rollback count remains consistent.
            ops.push_back({-1, -1, -1, -1, -1, -1});
            return;
        }
        if(size[a] < size[b])
            swap(a, b);
        DSUOperation op;
        op.type = 0;
        op.u = b;         // b is attached to a.
        op.rep = a;       // a remains representative.
        op.parent = parent[b];
        op.oldSize = size[a];
        op.oldActiveCount = activeCount[a];
        ops.push_back(op);
        parent[b] = a;
        size[a] += size[b];
        activeCount[a] += activeCount[b];
    }
    
    // "Delete" node a: mark it inactive and update its component's active count.
    void deleteNode(int a) {
        int rep = find(a);
        DSUOperation op;
        op.type = 1;
        op.u = a;
        op.rep = rep;
        op.oldActiveCount = activeCount[rep];
        ops.push_back(op);
        active[a] = false;
        activeCount[rep]--;
    }
    
    // Compute maximum active component size by scanning the DSU state.
    // (Since n is the number of nodes, scanning is acceptable in our offline framework.)
    int getMaxComponentSize() {
        int mx = 0;
        vector<bool> seen(n, false);
        for (int i = 0; i < n; i++) {
            int r = find(i);
            if (!seen[r]) {
                seen[r] = true;
                mx = max(mx, activeCount[r]);
            }
        }
        return mx;
    }
    
    // Roll back the last 'cnt' operations.
    void rollback(int cnt) {
        while(cnt--) {
            DSUOperation op = ops.back();
            ops.pop_back();
            if(op.type == -1) continue; // dummy op
            if(op.type == 0) {
                // Roll back a union operation.
                int rep = op.rep, attached = op.u;
                parent[attached] = op.parent;
                size[rep] = op.oldSize;
                activeCount[rep] = op.oldActiveCount;
            } else if(op.type == 1) {
                // Roll back a deletion.
                int rep = op.rep, node = op.u;
                active[node] = true;
                activeCount[rep] = op.oldActiveCount;
            }
        }
    }
    
    // Return the current number of recorded operations.
    int opCount() {
        return ops.size();
    }
};

//
// Edge structure
//
struct Edge {
    int u, v;
};

//
// Segment tree for offline dynamic connectivity.
// Each node of the segment tree covers a contiguous interval of queries,
// and we store a list of edges that are "active" in that interval.
//
struct SegmentTree {
    int n;
    vector<vector<Edge>> seg;
    
    SegmentTree(int n) : n(n) {
        seg.resize(4*n);
    }
    
    // Add edge 'e' to all queries in the interval [ql, qr].
    void add(int idx, int l, int r, int ql, int qr, Edge e) {
        if(ql > r || qr < l) return;
        if(ql <= l && r <= qr) {
            seg[idx].push_back(e);
            return;
        }
        int mid = (l + r) / 2;
        add(idx*2, l, mid, ql, qr, e);
        add(idx*2+1, mid+1, r, ql, qr, e);
    }
    
    void addInterval(int l, int r, Edge e) {
        if(l > r) return;
        add(1, 0, n-1, l, r, e);
    }
};

//
// Global vector to store the answer for each query (i.e. each node removal).
// ans[i] = maximum connected component size after removing node i.
vector<int> ans;

//
// DFS on the segment tree: at each node we add the stored edges (via DSU.unionSet)
// and when reaching a leaf corresponding to query 'i', we delete node i and compute the answer.
//
void dfs(int idx, int l, int r, SegmentTree &seg, DSU &dsu) {
    int beforeOps = dsu.opCount();
    // Add all edges in this segment.
    for(auto &e : seg.seg[idx])
        dsu.unionSet(e.u, e.v);
    
    if(l == r) { // Leaf: corresponds to query l (i.e. removal of node l)
        int beforeDel = dsu.opCount();
        dsu.deleteNode(l);
        ans[l] = dsu.getMaxComponentSize();
        dsu.rollback(dsu.opCount() - beforeDel); // undo the deletion
    } else {
        int mid = (l + r) / 2;
        dfs(idx*2, l, mid, seg, dsu);
        dfs(idx*2+1, mid+1, r, seg, dsu);
    }
    dsu.rollback(dsu.opCount() - beforeOps);
}

//
// Main: Reads a tree, builds the offline dynamic connectivity structure, 
// answers for every node removal query, and then outputs the candidate node (largest index)
// for which every remaining connected component is of size at most n/2.
//
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N;
    cin >> N;
    N+=1;
    vector<Edge> edges;
    // Read N-1 tree edges (assume nodes are 0-indexed; if input is 1-indexed, subtract 1)
    for (int i = 0; i < N - 1; i++) {
        int u, v;
        cin >> u >> v;
        // adjust indices if necessary (e.g., if input is 1-indexed, do u--, v--)
        if(u > v) swap(u, v); // ensure u < v
        edges.push_back({u, v});
    }
    
    // Build the segment tree for queries 0 ... N-1 (each query = removal of node i)
    SegmentTree seg(N);
    // For each edge (u,v), it is absent if the removed node equals u or v.
    // So it is present in queries where the removed node is not u and not v.
    // That gives three intervals (if nonempty): [0, u-1], [u+1, v-1], and [v+1, N-1].
    for(auto &e : edges) {
        int u = e.u, v = e.v;
        if(u > 0)
            seg.addInterval(0, u - 1, e);
        if(u + 1 <= v - 1)
            seg.addInterval(u + 1, v - 1, e);
        if(v < N - 1)
            seg.addInterval(v + 1, N - 1, e);
    }
    
    ans.assign(N, 0);
    DSU dsu(N);
    dfs(1, 0, N - 1, seg, dsu);
    
    // Now, a node v is a valid candidate (i.e. a centroid) if the maximum component size
    // after its removal is <= N/2.
    // Among valid candidates, we want the one with the largest index.
    int candidate = -1;
    for (int i = N-1; i > -1; i--) {
        if (ans[i] <= N/2){
            candidate = i;  // because we scan in increasing order, candidate ends up being the largest index
            break;
        }
    }
    
    cout << candidate << "\n";
    return 0;
}
