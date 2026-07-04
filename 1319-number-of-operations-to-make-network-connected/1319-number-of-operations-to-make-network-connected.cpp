class DisjointSet {
public:
    vector<int> parent, size;

    DisjointSet(int n) {
        parent.resize(n);
        size.resize(n, 1);

        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int findParent(int node) {
        if (node == parent[node])
            return node;

        return parent[node] = findParent(parent[node]);
    }

    void unionBySize(int u, int v) {
        int ulp_u = findParent(u);
        int ulp_v = findParent(v);

        if (ulp_u == ulp_v)
            return;

        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        } else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {

        DisjointSet ds(n);

        int extraEdges = 0;

        for (auto it : connections) {

            int u = it[0];
            int v = it[1];

            if (ds.findParent(u) == ds.findParent(v)) {
                extraEdges++;
            } else {
                ds.unionBySize(u, v);
            }
        }

        int components = 0;

        for (int i = 0; i < n; i++) {
            if (ds.findParent(i) == i) {
                components++;
            }
        }

        int need = components - 1;

        if (extraEdges >= need)
            return need;

        return -1;
    }
};