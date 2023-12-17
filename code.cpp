class Solution {
public:
    
    int numDistinct(string s, string t) {
        int n=s.size();
        int m=t.size();
        // vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        // int res=solve(s,t,s.size()-1,t.size()-1,dp);
        // return res;
        double dp[n+1][m+1];
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(i==0)
                {
                  if(s[i]==t[j] && j==0)
                  dp[i][j]=1;
                  else
                  dp[i][j]=0;
                }
                else if(j==0)
                {
                    if(s[i]==t[j])
                    {
                        dp[i][j]=1+dp[i-1][j];
                    }
                    else
                    dp[i][j]=dp[i-1][j];
                }
                else
                {
                    if(s[i]==t[j])
                    dp[i][j]=dp[i-1][j-1]+dp[i-1][j];
                    else
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
       
        return (int)dp[n-1][m-1];
        
        
    }
};
