class UnionFind {
public:
    vector<int> parent, rank;
    int count;

    UnionFind(int n) : parent(n), rank(n), count(n) {
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (parent[x] != x) 
            parent[x] = find(parent[x]);
    
        return parent[x];
    }

    bool union_(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX == rootY) {
            return false;
        }

        if (rank[rootX] < rank[rootY]) {
            swap(rootX, rootY);
        }

        parent[rootY] = rootX;

        if (rank[rootX] == rank[rootY]) {
            rank[rootX]++;
        }

        count--;

        return true;
    }
};
