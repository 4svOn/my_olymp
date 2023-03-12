void build_lca(ll v, ll p = 0, ll d = 0) {
	dist[v] = d;
	par[v].pb(p);
	rep2(i, depth) {
		par[v].pb(par[par[v][i - 1]][i - 1]);
	}
	for (ll to : gr[v]) {
		if (to == p) continue;
		build_lca(to, v, d + 1);
	}
}

ll find_lca(ll a, ll b) {
	if (dist[a] < dist[b]) swap(a, b);
	ll i = depth;
	while (dist[a] > dist[b]) {
		if (dist[par[a][i]] >= dist[b]) {
			a = par[a][i];
		}
		--i;
	}
	if (a == b) return a;
	i = depth;
	for (; i >= 0; --i) {
		if (par[a][i] != par[b][i]) {
			a = par[a][i];
			b = par[b][i];
		}
	}
	return par[a][0];
}