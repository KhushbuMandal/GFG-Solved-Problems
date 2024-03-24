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
        
        int total = R*C;
        
        int start = 1;
        int end = 1e9;
        
        
        int medianOfMatrix = 0;
        
        while (start <= end){
            int mid = (start + end) / 2;
            
            
            int frequencyCount = 0;
            
            
            for (int row = 0 ; row < R ; row++){
                int index = upper_bound (matrix[row].begin() , matrix[row].end() , mid) - matrix[row].begin();
                
                frequencyCount += index;
            }
            
            
            if (frequencyCount > total/2){
                medianOfMatrix = mid;
                end = mid - 1;
            }else {
                start = mid + 1;
            }
        }
        
        return medianOfMatrix;
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