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