//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    // your task is to complete this function
    int maxDistance(int arr[], int n)
    {
        unordered_map <int , int> frequency;
        
        int maxDist = 0;
        
        for (int idx = 0 ; idx < n ; idx++){
            
            if (frequency.find (arr[idx]) != frequency.end()){
                maxDist = max (maxDist , idx - frequency[arr[idx]]);
            }
            
            else frequency[arr[idx]] = idx;
        }
        
        return maxDist;
    
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.maxDistance(arr,n)<<endl;
    }
    return 0;
}
// } Driver Code Ends