//#define _CRT_SECURE_NO_WARNINGS
//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")

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
#include <numeric>
#include <bitset>

using namespace std;

//#define int long long
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<ll, char> plc;
typedef pair<ull, ull> upll;
typedef pair<ll, pll> plll;
typedef pair<pll, pll> pllll;
typedef vector<vector<ll> > graph;
typedef vector<vector<plc> > graphpc;
typedef vector<vector<pll> > graphp;
typedef vector<vector<char> > graphc;
typedef vector <ll> vec;
typedef vector <char> vecc;
typedef vector <pll> vecp;
typedef vector <string> vecs;
const ld PI = 3.14159265358979323846;
const ld EPS = 0.000000001;
const ll MD_7 = 1000000007;
const ll MD_9 = 1000000009;
const ll MD = 228228227;
const ll INF = INT64_MAX;
#define pb push_back
#define eb emplace_back
#define ass assign
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
#define sz(a) (ll)(a.size())
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
#define FOR(IT, ST, N) for (ll IT = (ST); (IT) <= (N); ++(IT))
#define FORB(IT, N, ST) for (ll IT = (N); (IT) >= (ST); --(IT))

template <typename T> T mod_inv_in_range(T a, T m) {

    T x = a, y = m;
    T vx = 1, vy = 0;
    while (x) {
        T k = y / x;
        y %= x;
        vy -= k * vx;
        std::swap(x, y);
        std::swap(vx, vy);
    }
    return vy < 0 ? m + vy : vy;
}

template <typename T> T mod_inv(T a, T m) {
    a %= m;
    a = a < 0 ? a + m : a;
    return mod_inv_in_range(a, m);
}

template <int MOD_> struct Mint {
    static constexpr int MOD = MOD_;

private:
    int v;

public:

    Mint() : v(0) {}
    Mint(int64_t v_) : v(int(v_ % MOD)) { if (v < 0) v += MOD; }
    explicit operator int() const { return v; }
    friend std::ostream& operator << (std::ostream& out, const Mint& n) { return out << int(n); }
    friend std::istream& operator >> (std::istream& in, Mint& n) { int64_t v_; in >> v_; n = Mint(v_); return in; }

    friend bool operator == (const Mint& a, const Mint& b) { return a.v == b.v; }
    friend bool operator != (const Mint& a, const Mint& b) { return a.v != b.v; }

    Mint inv() const {
        Mint res;
        res.v = mod_inv_in_range(v, MOD);
        return res;
    }
    friend Mint inv(const Mint& m) { return m.inv(); }
    Mint neg() const {
        Mint res;
        res.v = v ? MOD-v : 0;
        return res;
    }
    friend Mint neg(const Mint& m) { return m.neg(); }

    Mint operator- () const {
        return neg();
    }
    Mint operator+ () const {
        return Mint(*this);
    }

    Mint& operator ++ () {
        v ++;
        if (v == MOD) v = 0;
        return *this;
    }
    Mint& operator -- () {
        if (v == 0) v = MOD;
        v --;
        return *this;
    }
    Mint& operator += (const Mint& o) {
        v -= MOD-o.v;
        v = (v < 0) ? v + MOD : v;
        return *this;
    }
    Mint& operator -= (const Mint& o) {
        v -= o.v;
        v = (v < 0) ? v + MOD : v;
        return *this;
    }
    Mint& operator *= (const Mint& o) {
        v = int(int64_t(v) * int64_t(o.v) % MOD);
        return *this;
    }
    Mint& operator /= (const Mint& o) {
        return *this *= o.inv();
    }

    friend Mint operator ++ (Mint& a, int) { Mint r = a; ++a; return r; }
    friend Mint operator -- (Mint& a, int) { Mint r = a; --a; return r; }
    friend Mint operator + (const Mint& a, const Mint& b) { return Mint(a) += b; }
    friend Mint operator - (const Mint& a, const Mint& b) { return Mint(a) -= b; }
    friend Mint operator * (const Mint& a, const Mint& b) { return Mint(a) *= b; }
    friend Mint operator / (const Mint& a, const Mint& b) { return Mint(a) /= b; }
};

template <typename T> T pow(T a, ll b) {
    T r = 1; while (b) { if (b & 1) r *= a; b >>= 1; a *= a; } return r;
}

using mint = Mint<998244353>;

vector<mint> fact(1, 1);
vector<mint> inv_fact(1, 1);

void init_facts(size_t len){
    fact.assign(len + 1, 1);
    inv_fact.assign(len + 1, 1);
    rep2(i, len) fact[i] = fact[i - 1] * mint(i);
    inv_fact[len] = inv(fact[len]);
    repb2(i, len) inv_fact[i - 1] = inv_fact[i] * mint(i);
}

mint C(ll n, ll k) {
    if (k < 0 || k > n) {
        return 0;
    }
    return fact[n] * inv_fact[k] * inv_fact[n - k];
}

void solve(){
    ll n; cin >> n;
    graph ogr(n, vec(n, -1));
    rep(i, n){
        FOR(j, i, n - 1){
            cin >> ogr[i][j];
        }
    }
    vector<vector<vector<mint>>> dp(n, vector<vector<mint>>(n, vector<mint>(2, 0)));
    //vector<vector<mint>> dp(n, vector<mint>(n, 0));
    rep(i, n) {
        if (ogr[i][i] == 2) {
            cout << 0 << el;
            return;
        }
        dp[i][i][0] = 2;
    }
    FOR(len, 2, n){
        rep(l, n - len + 1){
            ll r = l + len - 1;
            if (ogr[l][r] == 0) {
                dp[l][r][0] = dp[l][r - 1][0];
                dp[l][r][1] = dp[l][r - 1][0] + dp[l][r - 1][1] * 2;
            }
            else if (ogr[l][r] == 1){
                dp[l][r][0] = dp[l][r - 1][0];
                dp[l][r][1] = 0;
            } else {
                dp[l][r][0] = 0;
                dp[l][r][1] = dp[l][r - 1][0] +  dp[l][r - 1][1] * 2;
            }
        }
    }
    cout << dp[0][n - 1][0] + dp[0][n - 1][1] << el;
//    cout << dp[0][n - 1][0] << ' ' << dp[0][n - 1][1] << el;
}

signed main() {
    FF;
//    ll nt;
//    cin >> nt;
//    while(nt--) {
//        solve();
//    }
    solve();

    return 0;
}

// if you have problems, just read the stuff at the bottom

/*
4
1 2 0 0
1 1 1
1 1
1

3
1 2 0
1 1
1
*/

/* for inputs
ll nt;
cin >> nt;
while(nt--) {

}
*/

/*
some help:

1) cmp for set:
bool cmp(const ll& a, const ll& b) {
 ........
}
using comp = integral_constant<decltype(&cmp), &cmp>;
set <plll, comp> arr;




2) module operations

const ll md = MD_7;

ll sqr(ll a) {
    return a * a % md;
}

ll pow1(ll a, ll b) {
    if (b == 0) return 1;
    if (b % 2 == 0) return sqr(pow1(a, b / 2));
    return a * pow1(a, b - 1) % md;
}

ll div(ll a, ll b) {
    return a * pow1(b, md - 2) % md;
}

ll mul(ll a, ll b) {
    return a * b % md;
}

ll add(ll a, ll b) {
    return (a + b) % md;
}

ll sub(ll a, ll b) {
    return b > a ? a + md - b : a - b;
}

ll gcd(ll a, ll b){
    return b == 0 ? a : gcd(b, a % b);
}

vector <string> split_by_char(string &s, char c){
    int i = int(s.find(c)), prev = 0;
    vector <string> ans;
    do{
        ans.push_back(s.substr(prev, i - prev));
        prev = i + 1;
    } while ((i = int(s.find(c, prev))) != -1);
    ans.push_back(s.substr(prev, i - prev));
    return ans;
}

const int MAX_N = 1e6 + 10;
ll min_div[MAX_N];
vec get_prime_numbers(ll n){
    vec ans;
    rep(i, MAX_N) min_div[i] = 0;
    FOR(i, 2, n){
        if (!min_div[i]){
            ans.pb(i);
            min_div[i] = i;
        }
        for(ll x : ans){
            if (x * i > n || x > min_div[i]) break;
            min_div[x * i] = x;
        }
    }
    return ans;
}

struct Graph{
    graph par, gr;
    ll n;
    vecc used;
    vec s, max_way, add_one, add_more, to_add;

    void init_graph(){
        gr.assign(n, vec());
        s.assign(n, 0);
        max_way.assign(n, 0);
        add_more.assign(n, 0);
        add_one.assign(n, 0);
        to_add.assign(n, 0);
    }

    void read_graph(){
        rep1(i, n){
            ll a; cin >> a; --a;
            gr[a].pb(i);
            //gr[i].pb(a);
        }
        rep(i, n) cin >> s[i];
    }

    void dfs(ll v, ll p){
        ll mxv = 0, one = 0, more = 0, add = 0;
        for (ll to : gr[v]){
            if (v == p) continue;
            dfs(to, v);
            if (max_way[to] >= max_way[mxv]){
                mxv = to;
            }
            one += max_way[to];
            more += s[to];
        }
        max_way[v] = max_way[mxv] + s[v];
        add_one[v] = one - max_way[mxv];
        add_more[v] = more - s[mxv];
        to_add[v] = sz(gr[v]) - 1;
    }
};

 */