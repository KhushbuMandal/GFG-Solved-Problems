//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    // your task is to complete this function
    int maxDistance(int arr[], int n)
    {
        //Code here
        int maxDistance = 0;
        unordered_map <int,int> storeElementwithIndex;
        
        for (int i = 0; i < n; i++){
            
            if (storeElementwithIndex.find(arr[i]) != storeElementwithIndex.end()){
                int tempDistance = i - storeElementwithIndex[arr[i]];
                
                if (tempDistance > maxDistance){
                    maxDistance = tempDistance;
                }
            }
            else {
                storeElementwithIndex[arr[i]] = i;
            }
        }
        
        return maxDistance;
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