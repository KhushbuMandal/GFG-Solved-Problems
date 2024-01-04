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
    // how to recognize here we can use binary search here
    // what we have notice that after the sorting if array 2 then if we have find the just grater element than the 
    // x then before that element all the elements will be less than or eual to x
    
    //vector <int> a(m , 0);
    vector <int> b;
    
    for (int i = 0 ; i < n; i++){
        b.push_back (arr2[i]);
    }
    
    sort (b.begin() , b.end());
    
    vector <int> ans;
    
    for (int i = 0; i < m ; i++){
        int index = upper_bound (b.begin() , b.end() , arr1[i]) - b.begin();
        
        index--;
        
        int LessThanEqual = index - 0 + 1;
        
        ans.push_back (LessThanEqual);
        
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