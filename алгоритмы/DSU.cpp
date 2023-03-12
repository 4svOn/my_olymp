void build(ll v){
	parent[v] = v;
	size[v] = 1;
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

sort(all(edges));
rep2(i, n) build(i);
for (edge ed : edges){
	if (find_set(ed.a) != find_set(ed.b)){
		cost += ed.c;
		ostov.pb(ed);
		union_set(ed.a, ed.b);
	}
}