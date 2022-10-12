//len:total people , k:cycle people
int winner(int len, int k) {  
    int g, n;
    for(g = 0, n = 1; n <= len; n++) {
        g = (g + k) % n;
    }
    return g + 1;
}