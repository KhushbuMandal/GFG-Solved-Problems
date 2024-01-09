//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
public:

    int isPossible (int n, int k, vector<int> &stalls , int mid){
        
        int cowsCount = 1;
        int lastposition = stalls[0];
        
        for (int i = 1 ; i < n ; i++){
            if (abs(lastposition - stalls[i]) >= mid){
                cowsCount++;
                
                if (cowsCount == k){
                    return true;
                }
                
                lastposition = stalls[i];
            }
        }
        
        return false;
        
    }

    int solve(int n, int k, vector<int> &stalls) {
    
        // Write your code here
        sort (stalls.begin() , stalls.end());
        
        int start = 0;
        
        // int mini = *min_element (stalls.begin() , stalls.end());
        int maxi = *max_element (stalls.begin() , stalls.end());
        
        
       //int end = maxi - mini;
       int end = maxi;
       
        //int end = stalls[0] - stalls[n-1];
        
        int ans = -1;
        
        if (n < k)  return -1;
        
        while (start <= end){
            int mid = (start + end) / 2;
            
            if (isPossible (n , k , stalls , mid)){
                ans = mid;
                start = mid + 1;
            }
            else {
                end = mid - 1;
            }
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input

        int n, k;
        cin >> n >> k;

        vector<int> stalls(n);
        for (int i = 0; i < n; i++) {
            cin >> stalls[i];
        }
        // char ch;
        // cin >> ch;

        Solution obj;
        cout << obj.solve(n, k, stalls) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends