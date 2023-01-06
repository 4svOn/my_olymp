struct seg_tree {
    ll n;
    vec tree;

    seg_tree(ll n){
        while (n & (n - 1)) n++;
        tree.resize(n * 2 - 1, 0);
        this->n = n;
    }

    void update(ll x, ll i) {
        i += (n - 1);
        tree[i] = x;
        while (i > 0) {
            i = (i - 1) / 2;
            tree[i] = max(tree[i * 2 + 1], tree[i * 2 + 2]);
        }
    }

    ll get(ll v, ll tl, ll tr, ll l, ll r) {
        if (tl >= l && tr <= r) return tree[v];
        if (tl >= r || tr <= l) return 0;
        ll m = (tl + tr) / 2;
        return max(get(v * 2 + 1, tl, m, l, r), get(v * 2 + 2, m, tr, l, r));
    }

    ll get(ll l, ll r){
        return get(0, 0, n, l, r + 1);
    }
};