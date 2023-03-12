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
//using namespace __gnu_pbds;

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
template<typename T,typename T2>int cmin(T &a,T2 b){return a>b?a=b,1:0;}
template<typename T,typename T2>int cmax(T &a,T2 b){return a<b?a=b,1:0;}
template<typename T>T sqr(T a){return a*a;}
template<typename T,typename T2>T mmin(T a,T2 b){return a<b?a:b;}
template<typename T,typename T2>T mmax(T a,T2 b){return a>b?a:b;}
template<typename T,typename ...T2>T mmin(T a,T2 ...b){return mmin(a,mmin(b...));}
template<typename T,typename ...T2>T mmax(T a,T2 ...b){return mmax(a,mmax(b...));}
template<typename T1, typename T2> ostream& operator<<(ostream& out, const pair<T1, T2>& x) {return out << x.F << ' ' << x.S;}
template<typename T1, typename T2> istream& operator>>(istream& in, pair<T1, T2>& x) {return in >> x.F >> x.S;}
template<typename T> istream& operator>>(istream& in, vector<T>& a) {for(auto &x : a) in >> x; return in;}
template<typename T> ostream& operator<<(ostream& out, vector<T>& a) {for(auto &x : a) out << x << ' '; return out;}
template<typename T> void Unique(T &a) {a.erase(unique(a.begin(), a.end()), a.end());}
template<typename T> using ordered_set = __gnu_pbds::tree<T, __gnu_pbds::null_type,less<T>, __gnu_pbds::rb_tree_tag,__gnu_pbds::tree_order_statistics_node_update>;
template<typename T> using ordered_multiset = __gnu_pbds::tree<T, __gnu_pbds::null_type,less_equal<T>, __gnu_pbds::rb_tree_tag,__gnu_pbds::tree_order_statistics_node_update>;
// Как set, но две новые функции — это find_by_order() и order_of_key().
// Первая возвращает итератор на k-ый по величине элемент (отсчёт с нуля), вторая — возвращает количество элементов в множестве, строго меньших, чем наш элемент.

ll GCD(ll a, ll b){
    return b == 0 ? a : GCD(b, a % b);
}

ll LCM(ll a, ll b){
    return a * b / GCD(a, b);
}

template<typename Key>
class Set : public set<Key>{
public:
    bool contains(Key key) const{
        return this->find(key) != this->end();
    }
};

template <typename T> T pow(T a, ll b) {
    T r = 1; while (b) { if (b & 1) r *= a; b >>= 1; a *= a; } return r;
}

void solve(){
    ll n; cin >> n;
    vec a(n); cin >> a;
    multiset <ll> q;
    cout << 1 << ' ';
    q.insert(a[0]);
    vecc used(n + 1, 0);
    ll c = 0, ans = 1;
    rep1(i, n){
        ll w = i + 1;
        if (a[i] < w){
            if (!used[a[i]]) {
                ++c;
                used[a[i]] = 1;
            }
        } else q.insert(a[i]);
        while(!q.empty() && *q.begin() == w){
            q.erase(q.begin());
            if (!used[w]) {
                ++c;
                used[w] = 1;
            }
        }
        cout << (q.empty() ?  c + sz(q) << ' ';
    }
    cout << el;
}

signed main() {
    FF;

    ll nt; cin >> nt;
    while(nt--)
        solve();

    return 0;
}

// if you have problems, just read the stuff at the bottom

/*
4
1 2 6 7

4
1 6 7 8
*/

/*
1) cmp for set:
bool cmp(const ll& a, const ll& b) {
 ........
}
using comp = integral_constant<decltype(&cmp), &cmp>;
set <plll, comp> arr;
 */