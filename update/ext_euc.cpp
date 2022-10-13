// ax + by = gcd(a, b)
int ext_euc(int a, int b, int &x, int &y){
    if(!b){
        x = 1; y = 0;//S0, T0
        return a;
    }
    int d = ext_euc(b, a % b, y, x);
    y -= a / b * x; //Si,Ti, Si*Ti <= 0
    return d;
}
q = ext_euc(a, b, x, y);
