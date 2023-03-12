struct node {
	ll sum, add, asg;
};
 
ll n;
vector <node> tree;
 
void build() {
	while (n & (n - 1)) n++;
	tree.resize(n * 2 - 1, { 0, 0, INF });	
}
 
void push(ll v, ll l, ll r) {
	if (v >= n - 1) return;
	ll v1 = v * 2 + 1, v2 = v * 2 + 2, sz = (r - l) / 2;
	if (tree[v].asg != INF) {
		tree[v1].add = tree[v2].add = 0;
		tree[v1].asg = tree[v2].asg = tree[v].asg;
		tree[v1].sum = tree[v2].sum = tree[v].asg * sz;
	}
	if (tree[v].add != 0) {
		tree[v1].add += tree[v].add;
		tree[v2].add += tree[v].add;
		tree[v1].sum += tree[v].add * sz;
		tree[v2].sum += tree[v].add * sz;
	}
	tree[v].add = 0;
	tree[v].asg = INF;
}
 
void assign(ll v, ll tl, ll tr, ll l, ll r, ll x) {
	push(v, tl, tr);
	if (tl >= l && tr <= r) {
		tree[v].add = 0;
		tree[v].asg = x;
		tree[v].sum = x * (tr - tl);
		return;
	}
	if (tl >= r || tr <= l) return;
	ll v1 = v * 2 + 1, v2 = v * 2 + 2, m = (tl + tr) / 2;
	assign(v1, tl, m, l, r, x);
	assign(v2, m, tr, l, r, x);
	tree[v].sum = tree[v1].sum + tree[v2].sum;
}
 
void add(ll v, ll tl, ll tr, ll l, ll r, ll x){
	push(v, tl, tr);
	if (tl >= l && tr <= r) {
		tree[v].add += x;
		tree[v].sum += x * (tr - tl);
		return;
	}
	if (tl >= r || tr <= l) return;
	ll v1 = v * 2 + 1, v2 = v * 2 + 2, m = (tl + tr) / 2;
	add(v1, tl, m, l, r, x);
	add(v2, m, tr, l, r, x);
	tree[v].sum = tree[v1].sum + tree[v2].sum;
}
 
ll get_sum(ll v, ll tl, ll tr, ll l, ll r) {
	push(v, tl, tr);
	if (tl >= l && tr <= r) return tree[v].sum;
	if (tl >= r || tr <= l) return 0;
	ll v1 = v * 2 + 1, v2 = v * 2 + 2, m = (tl + tr) / 2;
	return get_sum(v1, tl, m, l, r) + get_sum(v2, m, tr, l, r);
}
 
int main() {
	FF;
	ll k;
	cin >> n >> k;
	build();
	while (k--) {
		ll q, l, r, x;
		cin >> q;
		if (q == 1) {
			cin >> l >> r >> x;
			assign(0, 0, n, l, r, x);
		}
		if (q == 2) {
			cin >> l >> r >> x;
			add(0, 0, n, l, r, x);
		}
		if (q == 3) {
			cin >> l >> r;
			cout << get_sum(0, 0, n, l, r) << el;
		}
	}
	return 0;
}

// Присваивание, прибавление и сумма