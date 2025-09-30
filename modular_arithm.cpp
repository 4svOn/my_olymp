struct mint;
ll MOD = MD_7;

template <typename T> T mod_inv_in_range(T a, ll mod = MOD) {
    T x = a, y = mod;
    T vx = 1, vy = 0;
    while (x) {
        T k = y / x;
        y %= x;
        vy -= k * vx;
        std::swap(x, y);
        std::swap(vx, vy);
    }
    return vy < 0 ? mod + vy : vy;
}

template <typename T> T mod_inv(T a, ll mod = MOD) {
    a %= mod;
    a = a < 0 ? a + mod : a;
    return mod_inv_in_range(a, mod);
}

struct mint {
private:
    int v;

public:

    mint() : v(0) {}
    mint(int v_) : v(v_ % MOD) { if (v < 0) v += MOD; }
    mint(int64_t v_) : v(int(v_ % MOD)) { if (v < 0) v += MOD; }
    explicit operator int() const { return v; }
    friend std::ostream& operator << (std::ostream& out, const mint& n) { return out << int(n); }
    friend std::istream& operator >> (std::istream& in, mint& n) { int64_t v_; in >> v_; n = mint(v_); return in; }

    friend bool operator == (const mint& a, const mint& b) { return a.v == b.v; }
    friend bool operator != (const mint& a, const mint& b) { return a.v != b.v; }

    mint inv() const {
        mint res;
        res.v = mod_inv_in_range(v);
        return res;
    }
    friend mint inv(const mint& m) { return m.inv(); }
    mint neg() const {
        mint res;
        res.v = v ? MOD-v : 0;
        return res;
    }
    friend mint neg(const mint& m) { return m.neg(); }

    mint operator- () const {
        return neg();
    }
    mint operator+ () const {
        return mint(*this);
    }

    mint& operator ++ () {
        v ++;
        if (v == MOD) v = 0;
        return *this;
    }
    mint& operator -- () {
        if (v == 0) v = MOD;
        v --;
        return *this;
    }
    mint& operator += (const mint& o) {
        v -= MOD-o.v;
        v = (v < 0) ? v + MOD : v;
        return *this;
    }
    mint& operator -= (const mint& o) {
        v -= o.v;
        v = (v < 0) ? v + MOD : v;
        return *this;
    }
    mint& operator *= (const mint& o) {
        v = int(int64_t(v) * int64_t(o.v) % MOD);
        return *this;
    }
    mint& operator /= (const mint& o) {
        return *this *= o.inv();
    }

    friend mint operator ++ (mint& a, int) { mint r = a; ++a; return r; }
    friend mint operator -- (mint& a, int) { mint r = a; --a; return r; }
    friend mint operator + (const mint& a, const mint& b) { return mint(a) += b; }
    friend mint operator - (const mint& a, const mint& b) { return mint(a) -= b; }
    friend mint operator * (const mint& a, const mint& b) { return mint(a) *= b; }
    friend mint operator / (const mint& a, const mint& b) { return mint(a) /= b; }
};

// template <typename T> T pow(T a, ll b) {
//     T r = 1; while (b) { if (b & 1) r *= a; b >>= 1; a *= a; } return r;
// }

vector<mint> fact(1, 1);
vector<mint> inv_fact(1, 1);

void init_facts(ll len){
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

vector<vector<mint>> dp_binom;

void init_binom_dp(ll len) {
    dp_binom.assign(len + 2, vector<mint>(len + 2, 0));
    dp_binom[0][0] = 1;
    rep2(n, len) {
        dp_binom[n][0] = 1;
        rep2(k, n + 1) {
            dp_binom[n][k] = dp_binom[n - 1][k - 1] + dp_binom[n - 1][k];
        }
    }
}

mint C_dp(ll n, ll k) {
    if (k < 0 || k > n) {
        return 0;
    }
    k = min(k, n - k);
    return dp_binom[n][k]; 
}

mint C_raw(ll n, ll k) {
    if (k < 0 || k > n) return 0;
    k = min(k, n - k);
    mint result = 1;
    rep2(i, k) {
        result = result * (n - k + i) / i;
    }
    return result;
}
