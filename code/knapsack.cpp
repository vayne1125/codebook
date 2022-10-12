void knapsack(int n, int w){        //--2dim
    memset(c, 0, sizeof(c));
    for (int i = 0; i < n; ++i)  
        for (int j = 0; j <= w; ++j)
            if (j - weight[i] < 0)    
                c[i+1][j] = c[i][j];
            else                     
                c[i+1][j] = max(c[i][j],c[i][j - weight[i]] + cost[i]);
    cout << "max value:" << c[n][w];
}

void knapsack(int n, int w) {     //--1dim
    memset(c, 0, sizeof(c));
    for (int i = 0; i < n; ++i)
        for (int j = w; j - weight[i] >= 0; --j)  
            c[j] = max(c[j], c[j - weight[i]] + cost[i]);
    cout << "max value:" << c[w];
}