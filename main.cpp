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
#include <ext/pb_ds/assoc_container.hpp> // Общий файл.
#include <ext/pb_ds/tree_policy.hpp> // Содержит класс tree_order_statistics_node_update

using namespace std;
using namespace __gnu_pbds;

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
template<class T,class T2>int cmin(T &a,T2 b){return a>b?a=b,1:0;}
template<class T,class T2>int cmax(T &a,T2 b){return a<b?a=b,1:0;}
template<class T>T sqr(T a){return a*a;}
template<class T,class T2>T mmin(T a,T2 b){return a<b?a:b;}
template<class T,class T2>T mmax(T a,T2 b){return a>b?a:b;}
template<class T,class ...T2>T mmin(T a,T2 ...b){return mmin(a,mmin(b...));}
template<class T,class ...T2>T mmax(T a,T2 ...b){return mmax(a,mmax(b...));}
template<typename T> istream& operator>>(istream& in, vector<T>& a) {for(auto &x : a) in >> x; return in;}
template<typename T> ostream& operator<<(ostream& out, vector<T>& a) {for(auto &x : a) out << x << ' '; return out;}
template<typename T1, typename T2> ostream& operator<<(ostream& out, const pair<T1, T2>& x) {return out << x.f << ' ' << x.s;}
template<typename T1, typename T2> istream& operator>>(istream& in, pair<T1, T2>& x) {return in >> x.f >> x.s;}
template<typename T> void Unique(T &a) {a.erase(unique(a.begin(), a.end()), a.end());}
template<typename T> using ordered_set = tree<T, null_type,less<T>, rb_tree_tag,tree_order_statistics_node_update>;
template<typename T> using ordered_multiset = tree<T, null_type,less_equal<T>, rb_tree_tag,tree_order_statistics_node_update>;
// как set, но две новые функции — это find_by_order() и order_of_key().
// Первая возвращает итератор на k-ый по величине элемент (отсчёт с нуля), вторая — возвращает количество элементов в множестве, строго меньших, чем наш элемент.

ll gcd(ll a, ll b){
    return b == 0 ? a : gcd(b, a % b);
}

template<typename Key>
class Set : public set<Key>{
public:
    bool contains(Key key) const{
        return this->find(key) != this->end();
    }
};

void solve(){

}

signed main() {
    FF;

    ll nt;
    cin >> nt;
    while(nt--) {
        solve();
    }
//    solve();

    return 0;
}

// if you have problems, just read the stuff at the bottom

/*

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


struct seg_tree {
    ll n;
    vec tree;

    seg_tree(ll n){
        while (n & (n - 1)) n++;
        tree.resize(n * 2 - 1, 0);
        this->n = n;
    }

    void update(ll x, ll i) {
        i += (n - 1);
        tree[i] = x;
        while (i > 0) {
            i = (i - 1) / 2;
            tree[i] = max(tree[i * 2 + 1], tree[i * 2 + 2]);
        }
    }

    ll get(ll v, ll tl, ll tr, ll l, ll r) {
        if (tl >= l && tr <= r) return tree[v];
        if (tl >= r || tr <= l) return 0;
        ll m = (tl + tr) / 2;
        return max(get(v * 2 + 1, tl, m, l, r), get(v * 2 + 2, m, tr, l, r));
    }

    ll get(ll l, ll r){
        return get(0, 0, n, l, r + 1);
    }
};

 */