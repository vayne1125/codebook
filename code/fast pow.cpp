ll mypow(ll x,ll y,ll m){    //x^y % m
    ll ret = 1 % m;
    while(y){
        if(y&1)    ret = ret * x % m;
        x = x * x % m
        y >>= 1;
    }
    return ret;
}