#define _CRT_SECURE_NO_WARNINGS
//#pragma GCC optimize("Ofast")

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <cstdio>
#include <type_traits>

using namespace std;

#define int long long
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<ull, ull> upll;
typedef pair<ll, pll> plll;
typedef vector<vector<ll> > graph;
typedef vector<vector<pll> > graphp;
typedef vector <ll> vec;
typedef vector <char> vecc;
typedef vector <pll> vecp;
const ld PI = 3.14159265358979323846;
const ld EPS = 0.000000001;
const ll MD_7 = 1000000007;
const ll MD_9 = 1000000009;
const ll MD = 228228227;
const ll INF = INT64_MAX;
#define pb push_back
#define mp make_pair
#define pf push_front
#define popb pop_back
#define popf pop_front
#define ins insert
#define rsz resize
#define F first
#define S second
#define UM unordered_map
#define US unordered_set
#define FIXED(a) cout << fixed << setprecision(a);
#define sz(a) (int)(a.size())
#define all(a) a.begin(), a.end()
#define el '\n'
#define elf '\n' << flush
#define nope cout << "NO" << el
#define yep cout << "YES" << el
#define FF ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define rep(I, N) for (ll I = 0; I < (N); ++I)
#define rep1(I, N) for (ll I = 1; I < (N); ++I)
#define rep2(I, N) for (ll I = 1; I <= (N); ++I)
#define repb(I, N) for (ll I = (N) - 1; I >= 0; --I)
#define repb1(I, N) for (ll I = (N) - 1; I >= 1; --I)
#define repb2(I, N) for (ll I = (N); I >= 1; --I)

ull p = 1234, q = 4321;
vector <ull> st1;
vector <ull> st2;
vector <vector <ull> > map_hor;
ll map2[1005][1005];
ll lksh2[1005][1005];
vector <vector <ull> > lksh_hor;
vector <string> map1;
vector <string> lksh;
ll n, m, n1, m1;

ll MODMIN(ll a, ll b) {
	if (a >= b) return a - b;
	return a - b + MD_7;
}

ull SUBHASH1(ll i1, ll j1, ll i, ll j) {
	ull res = map2[i][j];
	if (i1 > 0) res = MODMIN(res, map2[i1 - 1][j] * st2[i - i1 + 1] % MD_7);
	if (j1 > 0) res = MODMIN(res, map2[i][j1 - 1] * st1[j - j1 + 1] % MD_7);
	if (i1 > 0 && j1 > 0) res = (res + (map2[i1 - 1][j1 - 1] * st1[j - j1 + 1] % MD_7) * st2[i - i1 + 1] % MD_7) % MD_7;
	return res;
}

ull SUBHASH2(ll i1, ll j1, ll i, ll j) {
	ull res = lksh2[i][j];
	if (i1 > 0) res = MODMIN(res, lksh2[i1 - 1][j] * st2[i - i1 + 1] % MD_7);
	if (j1 > 0) res = MODMIN(res, lksh2[i][j1 - 1] * st1[j - j1 + 1] % MD_7);
	if (i1 > 0 && j1 > 0) res = (res + (lksh2[i1 - 1][j1 - 1] * st1[j - j1 + 1] % MD_7) * st2[i - i1 + 1] % MD_7) % MD_7;
	return res;
}


void ugol() {
	map2[0][0] = (int)(map1[0][0]);
	rep1(i, n) {
		map2[i][0] = (map2[i - 1][0] * q % MD_7 + (int)(map1[i][0])) % MD_7;
	}
	rep1(i, m) {
		map2[0][i] = (map2[0][i - 1] * p % MD_7 + (int)(map1[0][i])) % MD_7;
	}

	lksh2[0][0] = (int)(lksh[0][0]);
	rep1(i, n1) {
		lksh2[i][0] = (lksh2[i - 1][0] * q % MD_7 + (int)(lksh[i][0])) % MD_7;
	}
	rep1(i, m1) {
		lksh2[0][i] = (lksh2[0][i - 1] * p % MD_7 + (int)(lksh[0][i])) % MD_7;
	}

	rep1(i, n) {
		rep1(j, m) {
			map2[i][j] = (MODMIN((map2[i][j - 1] * p % MD_7 + map2[i - 1][j] * q % MD_7) % MD_7, (map2[i - 1][j - 1] * q % MD_7) * p % MD_7) + (int)(map1[i][j])) % MD_7;
		}
	}

	rep1(i, n1) {
		rep1(j, m1) {
			lksh2[i][j] = (MODMIN((lksh2[i][j - 1] * p % MD_7 + lksh2[i - 1][j] * q % MD_7) % MD_7, (lksh2[i - 1][j - 1] * q % MD_7) * p % MD_7) + (int)(lksh[i][j])) % MD_7;
		}
	}
}

bool check(ll i1, ll j1) {
	ll l1 = 0, r1 = n1;
	while (r1 - l1 > 1) {
		ll m = (r1 + l1) / 2;
		ull a = SUBHASH2(0, 0, m - 1, m1 - 1);
		ull b = SUBHASH1(i1, j1, i1 + m - 1, j1 + m1 - 1);
		if (a == b) l1 = m;
		else r1 = m;
	}

	ll l2 = 0, r2 = n1;
	while (r2 - l2 > 1) {
		ll m = (r2 + l2) / 2;
		ull a = SUBHASH2(n1 - m, 0, n1 - 1, m1 - 1);
		ull b = SUBHASH1(i1 + (n1 - m), j1, i1 + n1 - 1, j1 + m1 - 1);
		if (a == b) l2 = m;
		else r2 = m;
	}
	if (l1 + l2 + 1 < n1) return false;

	l1 = 0, r1 = m1;
	while (r1 - l1 > 1) {
		ll m = (r1 + l1) / 2;
		ull a = SUBHASH2(0, 0, n1 - 1, m - 1);
		ull b = SUBHASH1(i1, j1, i1 + n1 - 1, j1 + m - 1);
		if (a == b) l1 = m;
		else r1 = m;
	}
	
	l2 = 0, r2 = m1;
	while (r2 - l2 > 1) {
		ll m = (r2 + l2) / 2;
		ull a = SUBHASH2(0, m1 - m, n1 - 1, m1 - 1);
		ull b = SUBHASH1(i1, j1 + (m1 - m), i1 + n1 - 1, j1 + m1 - 1);
		if (a == b) l2 = m;
		else r2 = m;
	}
	if (l1 + l2 + 1 < m1) return false;
	return true;
}

signed main() {
	FF;
	st1.rsz(1005);
	st2.rsz(1005);
	st1[0] = 1;
	st2[0] = 1;
	for (ll i = 1; i < 1005; i++) {
		st1[i] = (st1[i - 1] * p) % MD_7;
		st2[i] = (st2[i - 1] * q) % MD_7;
	}
	cin >> n >> m;
	map1.resize(n);
	rep(i, n) {
		cin >> map1[i];
	}
	cin >> n1 >> m1;
	lksh.resize(n1);
	rep(i, n1) {
		cin >> lksh[i];
	}
	ugol();
	ll c = 0;
	for (ll i = 0; i + n1 <= n; i++) {
		for (ll j = 0; j + m1 <= m; j++) {
			if (check(i, j)) c++;
		}
	}
	cout << c;
	return 0;
}

/* MESSAGE TO ME
БЕЗУМИЕ - ЭТО ЗАСЫЛАТЬ ЗАДАЧУ, ИЗМЕНИВ ОДИН СИМВОЛ, В НАДЕЖДЕ НА ОК
НО ТЫ, СОБАКА СУТУЛАЯ,ПОДУМАЙ ЕЩЁ РАЗ, ДОКАЖИ ПРАВИЛЬНОСТЬ СВОЕГО РЕШЕНИЯ, ПЕРЕПИШИ КОД ЗАНОВО(на крайний случай) И ПОТОМ ЗАСЫЛАЙ
*/

// if you have problems, just read the stuff at the bottom

/* for inputs
ll nt;
cin >> nt;
while(nt--) {

}

1 8
0 0
6 6
3 11
11 5
3 6
1 1
1 11
11 1
5 6
*/

/*
some help:

1) cmp for set:
 bool cmp(const ll& a, const ll& b) {
	 ........
 }
 using comp = integral_constant<decltype(&cmp), &cmp>;
 set <plll, comp> arr;

*/







/*  stuff you should look for:
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN

*/