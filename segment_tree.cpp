template<typename T> struct seg_tree {
    struct Node{
        int l, r;
        T val;

        Node() : l(-1), r(-1), val() {}
        Node(int _l, int _r) : l(_l), r(_r), val() {}
    };

    vector<Node> tree;
    int N;

    seg_tree(int n): N(n){
        N = n;
        int k = 1;
        while((1 << k) < N) k++;
        N = 1 << k;
        tree.resize(2 * N);
        for (int i = 0; i < N; i++)
            tree[N + i] = Node(i, i + 1);
        for (int i = N - 1; i > 0; i--)
            tree[i] = Node(tree[2 * i].l, tree[2 * i + 1].r);
    }

    seg_tree(const vector<T>& a): seg_tree(a.size()){
        for (int i = 0; i < N; i++)
            tree[N + i].val = a[i];
        for (int i = N - 1; i > 0; i--)
            tree[i].val = tree[2 * i].val + tree[2 * i + 1].val;
    }

    void update(T x, int v) {
        assert(0 <= v && v < N);
        v += (N - 1);
        tree[v].val = x;
        while (v > 1) {
            v >>= 1;
            tree[v].val = tree[v * 2 + 1].val + tree[v * 2 + 2].val;
        }
    }

    T _get(int v, int l, int r) {
        if (l <= tree[v].l && tree[v].r <= r) return tree[v].val;
        if (l >= tree[v].r || tree[v].l >= r) return T();
        return _get(2 * v, l, r) + _get(2 * v + 1, l, r);
    }

    T get(int l, int r) {
        if (l >= r) return T();
        assert(0 <= l && r <= N);
        return _get(1, l, r);
    }
};