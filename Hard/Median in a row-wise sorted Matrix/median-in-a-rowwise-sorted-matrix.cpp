//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int median(vector<vector<int>> &matrix, int R, int C){
        // code here     
        int start = 0;
        int end = 2000;
        
        int total = R*C;
        
        int ans = -1;
        
        while (start <= end){
            int mid = (start + end) / 2;
            
            int lessThanEqual = 0;// jo mid aaya use less than equal element kitne hai
            
            for (int row = 0 ; row < R ; row++){
                int up = upper_bound (matrix[row].begin() , matrix[row].end() , mid) - matrix[row].begin();
                lessThanEqual += up;
            }
            
            if (lessThanEqual > total/2){
                ans =  mid;
                end = mid -1;
            }else {
                start = mid +1 ;
            }
        }
        
        return ans;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int r, c;
        cin>>r>>c;
        vector<vector<int>> matrix(r, vector<int>(c));
        for(int i = 0; i < r; ++i)
            for(int j = 0;j < c; ++j)
                cin>>matrix[i][j];
        Solution obj;
        int ans=-1;
        ans=obj.median(matrix, r, c);
        cout<<ans<<"\n";        
    }
    return 0;
}
// } Driver Code Ends