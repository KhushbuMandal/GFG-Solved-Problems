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
        
        int start = 1;
        int end = 2000;
        int median = 0;
        
        int total = R*C;  // to count the number of element
        
        while (start <= end){
            int mid = (start + end) / 2;
            
            int lessThanEqual = 0;
            
            for (int row = 0 ; row < R ; row++){
                int it = upper_bound (matrix[row].begin() , matrix[row].end() , mid) - matrix[row].begin();
                lessThanEqual += it;
            }
            
            if (lessThanEqual > total/2){
                median = mid;
                end = mid-1;
            }else { // if (lessThanEqual < total/2)
                start = mid + 1;
            }
        }
        
        return median;
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