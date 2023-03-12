void dfs(ll v, ll p = -1, ll hh = 0) {
	up[v] = hh;
	used[v] = 1;
	for (ll to : gr[v]) {
		if (to == p) continue;
		if (!used[to]) dfs(to, v, hh + 1);
		up[v] = min(up[v], up[to]);
	}
	if (up[v] == hh && p != -1) {
		// это мост
	}
}