struct DSU {
    vec parent, size;

    DSU(ll n): parent(n), size(n, 1){
        rep(i, n) parent[i] = i;
    }

    ll find_set(ll v){
        if (parent[v] == v) return v;
        return parent[v] = find_set(parent[v]);
    }

    void union_set(ll v, ll u){
        ll f = find_set(v);
        ll s = find_set(u);
        if (s == f) return;
        if (size[s] < size[f]){
            parent[s] = f;
            size[f] += size[s];
        } else {
            parent[f] = s;
            size[s] += size[f];
        }
    }
};