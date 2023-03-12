struct seg_tree {
    ll n;
    vec tree;
    vec cnt;

    seg_tree(ll n){
        while (n & (n - 1)) n++;
        tree.resize(n * 2 - 1, 0);
        cnt.resize(n * 2 - 1, 0);
        this->n = n;
    }

    seg_tree(vec& a){
        n = a.size();
        while (n & (n - 1)) n++;
        tree.resize(n * 2 - 1, 0);
        cnt.resize(n * 2 - 1, 0);
        rep(i, a.size()){
            update(a[i], i);
        }
    }

    void update(ll x, ll i) {
        i += (n - 1);
        tree[i] = x;
        cnt[i] = 1;
        while (i > 0) {
            i = (i - 1) / 2;
            tree[i] = tree[i * 2 + 1] + tree[i * 2 + 2];
            cnt[i] = cnt[i * 2 + 1] + cnt[i * 2 + 2];
        }
    }

    ll get(ll v, ll tl, ll tr, ll l, ll r) {
        if (tl >= l && tr <= r) return tree[v];
        if (tl >= r || tr <= l) return 0;
        ll m = (tl + tr) / 2;
        return get(v * 2 + 1, tl, m, l, r) + get(v * 2 + 2, m, tr, l, r);
    }

    ll get(ll l, ll r){
        return get(0, 0, n, l, r + 1);
    }

    ll getc(ll v, ll tl, ll tr, ll l, ll r) {
        if (tl >= l && tr <= r) return cnt[v];
        if (tl >= r || tr <= l) return 0;
        ll m = (tl + tr) / 2;
        return getc(v * 2 + 1, tl, m, l, r) + getc(v * 2 + 2, m, tr, l, r);
    }

    ll getc(ll l, ll r){
        return getc(0, 0, n, l, r + 1);
    }
};
