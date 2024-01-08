//{ Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template in C++

class Solution 
{
    public:
    //Function to find minimum number of pages.
    
    bool isPossible (int A[], int N, int M , int mid){
        int studentCount = 1;
        int pageSum = 0;
        
        for (int i = 0 ; i < N ; i++){
            if (pageSum + A[i] <= mid){
                pageSum += A[i];
            }else {
                studentCount ++;
                if (studentCount > M || A[i] > mid){
                    return false;
                }
               // pageSum = 0;
                pageSum = A[i];
            }
        }
        
        return true;
    }
    
    int findPages(int A[], int N, int M) 
    {
        //code here
        int start = 1;
        int sum = 0;
        
        for (int i = 0 ; i < N ; i++){
            sum += A[i];
        }
        
        int end = sum;
        
        int ans = -1;
        
        if (N < M) return -1;
        
        while (start <= end){
            int mid = (start + end)/2;
            
            if (isPossible(A , N , M , mid)){
                ans = mid;
                end = mid - 1;
            }else {
                start = mid + 1;
            }
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}

// } Driver Code Ends