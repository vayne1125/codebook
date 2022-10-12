const ll P1 = 75577;
const ll P2 = 12721;  
const ll MOD = 998244353;
pair<ll, ll> Hash[MXN]; 
void build(const string& s) {
    pair<ll, ll> val = make_pair(0, 0);
    for (int i = 0; i < s.size(); i++) {
        val.first = (val.first * P1 + s[i]) % MOD;
        val.second = (val.second * P2 + s[i]) % MOD;
        Hash[i] = val;
    }
}