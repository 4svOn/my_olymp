void dfs(ll v, ll p = -1, ll hh = 0) {
	up[v] = hh;
	h[v] = hh;
	used[v] = 1;
	ll ch = 0;
	for (ll to : gr[v]) {
		if (to == p) continue;
		if (!used[to]) {
			dfs(to, v, hh + 1);
			up[v] = min(up[v], up[to]);
			++ch;
			if (up[to] >= hh && p != -1) {
				// точка сочленения
			}
		}
		else {
			up[v] = min(up[v], h[to]);
		}
	}
	if (ch > 1 && p == -1) {
		// точка сочленения
	}
}