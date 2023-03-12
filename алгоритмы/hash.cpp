	// P - какое-то простое число
// st = массив степеней P
ll P = 317;
vector <ull> st;

void build_st(ll max_n) {
	st.pb(1);
	rep(i, max_n) {
		st.pb(st.back() * 317 % MD_7);
	}
}

vector <ull> get_hash(string& s) {
	ll n = sz(s);
	vector <ull> arr(n);
	arr[0] = (ull)(s[0]);
	rep1(i, n) {
		arr[i] = (arr[i - 1] * P + (ull)(s[i])) % MD_7;
	}
	return arr;
}

// [l, r]
ull get_subhash(vector <ull>& hash, ll l, ll r) {
	if (l > 0) {
		ll a = hash[r];
		ll b = hash[l - 1] * st[r - l + 1] % MD_7;
		if (a >= b) return a - b;
		return a - b + MD_7;
	}
	return hash[r];
}