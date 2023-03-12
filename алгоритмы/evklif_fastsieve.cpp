void evk(ll a, ll b, ll& x, ll& y) {
    if (b == 0) {
        x = 1; y = 0;
        return;
    }
    evk(b, a % b, x, y);
    ll x1 = y, y1 = x - a / b * y;
    x = x1; y = y1;
}

FOR(i, 2, n) {
		if (dl[i] == 0) {
            pr.pb(i);
            dl[i] = i;
		}
		for (ll x : pr) {
            if (x * i > n || x > dl[i]) break;
            dl[x * i] = x;
		}
	}