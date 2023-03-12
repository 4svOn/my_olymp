graph gr, rev_gr;
vector <US <ll> > new_gr;
vecc used;
vec order, comps;

void dfs(ll v) {
	used[v] = 1;
	for (ll to : gr[v]) {
		if (!used[to])
			dfs(to);
	}
	order.pb(v);
}

void rev_dfs(ll v, ll comp) {
	used[v] = 1;
	comps[v] = comp;
	for (ll to : rev_gr[v]) {
		if (!used[to])
			rev_dfs(to, comp);
	}
}

signed main() {
	FF;
	ll n, m;
	cin >> n >> m;
	gr.resize(n + 1);
	rev_gr.resize(n + 1);
	used.resize(n + 1, 0);
	comps.resize(n + 1, 0);
	rep(i, m) {
		ll a, b;
		cin >> a >> b;
		gr[a].pb(b);
		rev_gr[b].pb(a);
	}
	rep2(i, n) {
		if (!used[i]) 
			dfs(i);
	}
	used.assign(n + 1, 0);
	reverse(all(order));
	ll comp = 1;
	for (ll v : order) {
		if (!used[v]) {
			rev_dfs(v, comp);
			comp++;
		}
	}
	new_gr.resize(comp);
	rep2(v, n) {
		for (ll to : gr[v]) {
			if (comps[v] != comps[to]) new_gr[comps[v]].insert(comps[to]);
		}
	}
	return 0;
}