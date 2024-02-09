//{ Driver Code Starts
// Counts Palindromic Subsequence in a given String
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    /*You are required to complete below method */
    long long int  countPS(string str)
    {
       //Your code here
       int n = str.length();
       
       int mod = 1e9+7;
       
       vector<vector<int>> dp(n, vector<int>(n, 0));
       
       int i = 0;
       while (i < n){
           
           dp[i][i] = 1; // string length 1 is also palindromic subsequence
           
           i++;
       }
       
       i = 0;
       while (i < n-1){
           
           if (str[i] == str[i+1]){
               dp[i][i+1] = 3;
           }else {
               dp[i][i+1] = 2;
           }
           
           i++;
       }
       
       int length=3;
       
       while (length <= n){
           
           int i = 0;
           
           while (i < n-length + 1){
               
               int j = i + length -1;
               
               if (str[i] != str[j]){
                   dp[i][j] = dp[i][j-1] + dp[i+1][j] - dp[i+1][j-1];
               }
               else {
                   dp[i][j] = dp[i][j-1] + dp[i+1][j] + 1;
               }
               
               dp[i][j]=dp[i][j]%mod;
               
               i++;
           }
           
           length ++;
       }
       
       return (dp[0][n-1]+mod)%mod;
    }
     
};

//{ Driver Code Starts.
// Driver program
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string str;
        cin>>str;
        Solution ob;
        long long int ans = ob.countPS(str);
        cout<<ans<<endl;
    } 
}
// } Driver Code Ends