//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    
    string longestPalindrome(string S){
        // code here 
        int n = S.length();
        
        vector<vector<int>> dp(n, vector<int>(n, 0));
        
        string res ="";
        
        int maxLen = 0;
        
        int i = 0;
        while (i < n){
            
            dp[i][i] = 1; // single chracter is palindrome
            
            if (maxLen < 1){
                maxLen = 1;
                res = S[i];
            }
            
            i++;
        }
        
        i = 0;
        while (i < n-1){
            
            if (S[i] == S[i+1]){
                dp[i][i+1] = 1; 
                
                if (maxLen < 2){
                    maxLen = 2;
                    res = S.substr(i , 2);
                }
            }
            
            i++;
        }
        
        int length = 3;
        while (length <= n){
            
            int i = 0;
            
            while (i < n - length + 1){
                
                int j = i + length - 1;
                
                if (S[i] == S[j] and dp[i+1][j-1] == 1){
                    dp[i][j] = 1;
                    
                    int currLen = length;
                    
                    if (maxLen < currLen){
                        maxLen = currLen;
                        res = S.substr(i , currLen);
                    }
                }
                
                i++;
            }
            length++;
        }
        
        return res;
        
    }
};

//{ Driver Code Starts.



int main(){
    int t;
    cin>>t;
    while(t--){
        string S;
        cin>>S;
        Solution ob;
        cout<<ob.longestPalindrome(S)<<endl;
    }
    return 0;
}

// } Driver Code Ends