//{ Driver Code Starts
// C++ implementation of For each element in 1st 
// array count elements less than or equal to it
// in 2nd array
#include <bits/stdc++.h>
 
using namespace std;


// } Driver Code Ends
// function to count for each element in 1st array,
// elements less than or equal to it in 2nd array
class Solution{
  public:
    vector<int> countEleLessThanOrEqual(int arr1[], int arr2[], 
                                 int m, int n)
    {
    //Your code goes here
    vector <int> a;
    vector <int> b;
    
    
    vector <int> result;
    
    for (int i = 0 ; i < n; i++){
        b.push_back(arr2[i]);
    }
    
    for (int i = 0 ; i < m; i++){
        a.push_back(arr1[i]);
    }
    
    sort (b.begin() , b.end());
    
    
    for (int i = 0 ; i < m ; i++){
        
       // int x = a[i];
        
        int index = upper_bound (b.begin() , b.end() , a[i]) - b.begin();
        
        result.push_back(index);
        
    }
    
    return result;
    
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m,n;
        cin>>m>>n;
        int arr1[m],arr2[n];
        for(int i=0;i<m;i++)
        cin>>arr1[i];
        for(int j=0;j<n;j++)
        cin>>arr2[j];
        Solution obj;
        vector <int> res = obj.countEleLessThanOrEqual(arr1, arr2, m, n);
        for (int i = 0; i < res.size (); i++) cout << res[i] << " ";
        
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends