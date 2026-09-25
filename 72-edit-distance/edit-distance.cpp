class Solution 
{
public:
    int fun(string &word1, string &word2, int i, int j, vector<vector<int>>&dp)
    {
        if(i==-1) return j+1;
        if(j==-1) return i+1;
        if(dp[i][j]!=-1) return dp[i][j];
        if(word1[i]==word2[j]) return dp[i][j] = fun(word1,word2,i-1,j-1,dp);
        return dp[i][j] = 1 + min(fun(word1,word2,i-1,j-1,dp), 
                min(fun(word1,word2,i,j-1,dp), fun(word1,word2,i-1,j,dp)));
    }
    int minDistance(string word1, string word2) 
    {
        int n = word1.size();
        int m = word2.size();
        if(n==0 && m==0) return 0;
        else if(n==0) return m;
        else if(m==0) return n;
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return fun(word1,word2,n-1,m-1,dp);
    }
//please upvote...
};