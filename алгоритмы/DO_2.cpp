ll n;
 
struct node {
	ll sum, max, pref, suf, upd;
	node(ll sum = 0, ll max = 0, ll pref = 0, ll suf = 0, ll upd = INF) {
		this->sum = sum;
		this->max = max;
		this->pref = pref;
		this->suf = suf;
		this->upd = upd;
	}
};
 
vector <node> tree;
 
void build() {
	while (n & (n - 1)) n++;
	tree.rsz(n * 2 - 1);
}
 
void push(ll v, ll l, ll r) {
	if (tree[v].upd == INF || v >= n - 1) return;
	ll v1 = v * 2 + 1, v2 = v * 2 + 2, sz = (r - l) / 2;
	tree[v1].upd = tree[v].upd;
	tree[v2].upd = tree[v].upd;
	tree[v1].max = tree[v1].pref = tree[v1].suf = max(sz * tree[v1].upd, 0ll);
	tree[v2].max = tree[v2].pref = tree[v2].suf = max(sz * tree[v2].upd, 0ll);
	tree[v1].sum = tree[v2].sum = sz * tree[v2].upd;
	tree[v].upd = INF;
}
 
void update(ll v, ll tl, ll tr, ll l, ll r, ll x) {
	push(v, tl, tr);
	if (tl >= l && tr <= r) {
		tree[v].upd = x;
		tree[v].max = tree[v].pref = tree[v].suf = max((tr - tl) * tree[v].upd, 0ll);
		tree[v].sum = (tr - tl) * tree[v].upd;
		return;
	}
	if (tl >= r || tr <= l) return;
	ll m = (tl + tr) / 2;
	update(v * 2 + 1, tl, m, l, r, x);
	update(v * 2 + 2, m, tr, l, r, x);
	ll v1 = v * 2 + 1, v2 = v * 2 + 2;
	tree[v].pref = max(tree[v1].pref, tree[v1].sum + tree[v2].pref);
	tree[v].suf = max(tree[v2].suf, tree[v2].sum + tree[v1].suf);
	tree[v].sum = tree[v1].sum + tree[v2].sum;
	tree[v].max = max(max(tree[v1].max, tree[v2].max), tree[v1].suf + tree[v2].pref);
}
 
int main() {
	FF;
	ll k;
	cin >> n >> k;
	ll n1 = n;
	build();
	rep(i, k) {
		ll l, r, x;
		cin >> l >> r >> x;
		update(0, 0, n, l, r, x);
		cout << tree[0].max << el;
	}
	return 0;
}

// Присваивание и максимальный отрезок