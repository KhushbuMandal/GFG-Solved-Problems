//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this method*/

// arr[] : the input array containing 0s and 1s
// N : size of the input array

// return the maximum length of the subarray
// with equal 0s and 1s
class Solution{
  public:
    int maxLen(int arr[], int N)
    {
        int maxLength = 0;
        int prefixSum = 0;
        unordered_map <int , int> prefixSumIndex;
        
        for (int i = 0 ; i < N ; i++){
            if (arr[i] == 0){
                arr[i] = -1;
            }
        }
        
            
        for (int i = 0 ; i < N ; i++){
            prefixSum += arr[i];
            
            if (prefixSum == 0) maxLength = i+1;
            
            if (prefixSumIndex.find(prefixSum) != prefixSumIndex.end()){
                maxLength = max (maxLength ,i - prefixSumIndex[prefixSum]);
            }
            else prefixSumIndex[prefixSum] = i;
       }
       
       return maxLength;

    }
};


//{ Driver Code Starts.

int main()
{
    // your code goes here
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        Solution obj;
        cout << obj.maxLen(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends