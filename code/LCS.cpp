dp[i][j]=dp[i-1][j-1]+1 (s[i]==t[j])
         max(dp[i-1][j],dp[i][j-1]) (s[i]!=t[j])
init:dp[i][-1]=dp[-1][j]=0