/*if we want to get Hash of str[l,r]
     H(l,r)=[H(r)-H(l-1)*p^(r-l+1)]%mod
     ex:H(1,3)=H(0,3)-H(0,0)*p^3 %mod
*/
const ll P = 75577;
const ll MOD = 998244353;
ll Hash[MXN];    //Hash[i] is the hash value of str[0,i]
void build(const string& s) {
    int val = 0;
    for (int i = 0; i < s.size(); i++) {
        val = (val * P + s[i]) % MOD;
        Hash[i] = val;
    }
}
/*prime:271,601,977,2221,5113,9151,12251,83357,115249,
859433,1398296,6972503,16769023,43112609,73939133*/
