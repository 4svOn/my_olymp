struct treap {
	ll y, sz, v, mn;
	struct treap *l, *r;
	treap(ll v = 0, ll y = rand(), ll sz = 1, treap *l = nullptr, treap *r = nullptr) {
		this->y = y;
		this->sz = sz;
		this->v = v;
		this->mn = v;
		this->l = l;
		this->r = r;
	}
};

ll get_size(treap* my) {
	return my == nullptr ? 0 : my->sz;
}

ll get_min(treap *my) {
	return my == nullptr ? INF : my->mn;
}

void update(treap *my) {
	if (my == nullptr) return;
	my->sz = get_size(my->r) + get_size(my->l) + 1;
	my->mn = min(get_min(my->l), get_min(my->r));
	my->mn = min(my->mn, my->v);
}

treap* merge(treap *L, treap *R) {
	if (L == nullptr) return R;
	if (R == nullptr) return L;
	if (L->y > R->y) {
		R->l = merge(L, R->l);
		update(R);
		return R;
	} else {
		L->r = merge(L->r, R);
		update(L);
		return L;
	}
}

void split(ll x, treap* my, treap *&L, treap*& R) {
	L = R = nullptr;
	if (my == nullptr) return;
	ll my_sz = get_size(my->l) + 1;
	if (my_sz <= x) {
		split(x - my_sz, my->r, my->r, R);
		L = my;
	} else {
		split(x, my->l, L, my->l);
		R = my;
	}
	update(my);
}

treap* insert(treap* my, ll x, ll pos) {
	treap *L = nullptr, *R = nullptr;
	split(pos, my, L, R);
	return merge(L, merge(new treap(x), R));
}

treap* del(treap* my, ll pos) {
	treap* l, * r, * rl, * rr;
	split(pos, my, l, r);
	split(1, r, rl, rr);
	return merge(l, rr);
}