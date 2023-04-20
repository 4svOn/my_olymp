template<typename T> struct seg_tree {
    struct Node{
        ll l, r;
        T val;

        Node() : l(-1), r(-1), val() {}
        Node(ll _l, ll _r) : l(_l), r(_r), val() {}
    };

    vector<Node> tree;
    ll N;

    seg_tree(ll n): N(n){
        N = n;
        ll k = 1;
        while((1 << k) < N) k++;
        N = 1 << k;
        tree.resize(2 * N);
        for (ll i = 0; i < N; i++)
            tree[N + i] = Node(i, i + 1);
        for (ll i = N - 1; i > 0; i--)
            tree[i] = Node(tree[2 * i].l, tree[2 * i + 1].r);
    }

    seg_tree(const vector<T>& a): seg_tree(sz(a)){
        for (ll i = 0; i < a.size(); i++)
            tree[N + i].val = a[i];
        for (ll i = N - 1; i > 0; i--)
            tree[i].val = tree[2 * i].val + tree[2 * i + 1].val;
    }

    void update(T x, ll v) {
        assert(0 <= v && v < N);
        v += N;
        tree[v].val = x;
        while (v > 1) {
            v >>= 1;
            tree[v].val = tree[v * 2].val + tree[v * 2 + 1].val;
        }
    }

    T _get(ll v, ll l, ll r) {
        if (l <= tree[v].l && tree[v].r <= r) return tree[v].val;
        if (l >= tree[v].r || tree[v].l >= r) return T();
        return _get(2 * v, l, r) + _get(2 * v + 1, l, r);
    }

    T get(ll l, ll r) {
        if (l >= r) return T();
        assert(0 <= l && r <= N);
        return _get(1, l, r);
    }
};