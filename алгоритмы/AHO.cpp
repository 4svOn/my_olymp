struct node {
	vec go, nxt;
	ll suffLink, charToPar, par, up;
	bool term;

	node() {
		term = false;
		nxt.ass(101, 0);
		go.ass(101, 0);
		suffLink = 1;
		par = 1;
		charToPar = 0;
		up = 1;
	}
};

ll sz = 2;
vector <node> tree(2);

void add_string(string & s) {
	ll v = 1;
	for (char ch : s) {
		//ll c = alph[ch];
		ll c = ch - 32;
		if (tree[v].nxt[c] == 0) {
			tree.pb(node());
			tree[sz].par = v;
			tree[sz].charToPar = c;
			tree[v].nxt[c] = sz++;
		}
		v = tree[v].nxt[c];
	}
	tree[v].term = 1;
}

void build_links() {
	deque<ll> q;
	tree[1].suffLink = tree[1].up = 1;
	rep(i, 100) {
		if (tree[1].nxt[i]) {
			q.pb(tree[1].nxt[i]);
			tree[1].go[i] = tree[1].nxt[i];
		} else {
			tree[1].go[i] = 1;
			
		}
	}
	while(!q.empty()) {
		ll v = q.front(); q.popf();
		if (tree[v].par == 1) tree[v].suffLink = tree[v].up = 1;
		else {
			tree[v].suffLink = tree[tree[tree[v].par].suffLink].go[tree[v].charToPar];
			tree[v].up = tree[tree[v].suffLink].term ? tree[v].suffLink : tree[tree[v].suffLink].up;
		}
		rep(i, 100) {
			if (tree[v].nxt[i]) {
				tree[v].go[i] = tree[v].nxt[i];
				q.pb(tree[v].go[i]);
			} else {
				tree[v].go[i] = tree[tree[v].suffLink].go[i];
			}
		}
	}
}
