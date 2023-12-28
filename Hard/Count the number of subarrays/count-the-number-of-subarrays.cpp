//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution {
  public:
    long long count (int N , vector <int> &A , long long x){
        long long sum = 0;
        
        long long  cnt = 0;
        int i = 0;
        int j = 0;
        
        while (j < N){
            
            sum += A[j];
            
            while (sum > x){
                sum -= A[i];
                i++;
            }
            
            cnt +=( j - i + 1);
            j++;
            
        }
        
        return cnt;
        
    }
  
  
    long long countSubarray(int N,vector<int> A,long long L,long long R) {
        
        long long ans1 = count (N , A, L-1);
        long long ans2 = count (N , A , R);
        
        return ans2 - ans1;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        long long L,R;
        cin>>N>>L>>R;
        vector<int> A(N);
        for(int i=0;i<N;i++){
            cin>>A[i];
        }
        Solution obj;
        auto ans = obj.countSubarray(N,A,L,R);
        cout<<ans<<endl;
    }
}  
// } Driver Code Ends