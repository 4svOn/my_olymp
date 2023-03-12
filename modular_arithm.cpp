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

using mint = Mint<MD_7>;

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


