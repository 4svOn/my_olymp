ll GCD(ll a, ll b){
    return b == 0 ? a : GCD(b, a % b);
}

ll LCM(ll a, ll b){
    return a * b / GCD(a, b);
}

template <typename T>
T pow(T a, ll b) {
    T r = 1; while (b) { if (b & 1) r *= a; b >>= 1; a *= a; } return r;
}

template <class C, class P>
constexpr auto FindIfPtr(C&& c, P pred) {
    auto found = find_if(c.begin(), c.end(), pred);
    return found == c.end() ? nullptr : &*found;
}

template <class C, class P>
constexpr size_t FindIndexIf(C&& c, P p) {
    using std::begin;
    using std::end;
    auto it = find_if(c.begin(), c.end(), p);
    return it == c.end() ? -1 : (it - c.begin());
}

bool isPrime(ll n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;

    // Проверяем делители вида 6k ± 1
    // Все простые числа > 3 имеют вид 6k ± 1
    for (ll i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) {
            return false;
        }
    }
    return true;
}

vector <string> split_by_char(string &s, char c) {
    if (s.empty()) return {};
    int i = int(s.find(c)), prev = 0;
    vector <string> ans;
    do {
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