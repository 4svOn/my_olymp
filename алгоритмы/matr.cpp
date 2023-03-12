graph sqr_matr(graph a) {
    graph ans(2, vec(2));
	rep(i, 2) {
		rep(j, 2) {
			rep(k, 2) {
                ans[i][j] = add(ans[i][j], mul(a[i][k], a[k][j]));
			}
		}
	}
    return ans;
}

graph pow_matr(ll n) {
    graph ans(2, vec(2));
    if (n == 0) {
        ans[0][0] = ans[1][1] = 1;
        ans[0][1] = ans[1][0] = 0;
        return ans;
    }
	if (n & 1) {
        graph a = pow_matr(n - 1);
        rep(i, 2) {
            rep(j, 2) {
                rep(k, 2) {
                    ans[i][j] = add(ans[i][j], mul(a[i][k], matr[k][j]));
                }
            }
        }
        return ans;
	}
    return sqr_matr(pow_matr(n / 2));
	
}