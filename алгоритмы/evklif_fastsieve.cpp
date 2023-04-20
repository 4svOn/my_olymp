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

// функция эйлера
void sieve() {
    phi[1] = 1;
    FOR(i, 2, C) {
        if (dl[i] == 0) {
            pr.pb(i);
            dl[i] = i;
            phi[i] = i - 1;
        }
//        cout << i << ' ' << dl[i] << ' ' << phi[i] << ':' << el;
        for (ll p : pr) {
//            cout << p << ": " << el;
            if (p * i > C || p > dl[i]) break;
//            cout << '(' << p * i << ' ' << dl[p * i] << ' ' << phi[p * i] << ')' << " -> ";
            dl[p * i] = p;
            if (p == dl[i]) {
                phi[p * i] = phi[i] * p;
            } else phi[p * i] = phi[i] * (p - 1);
//            cout << '(' << p * i << ' ' << dl[p * i] << ' ' << phi[p * i] << ')' << el;
        }
//        cout << el;
    }
}