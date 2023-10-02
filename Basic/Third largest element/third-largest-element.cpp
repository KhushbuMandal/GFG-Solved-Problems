//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
  public:
    int thirdLargest(int arr[], int n)
    {
        if (n < 3) return -1;
        int first = INT_MIN;
        int second = INT_MIN;
        int third = INT_MIN;
        
        for (int i = 0 ; i < n ; i++){
            if (arr[i] > first){
                third = second;
                second = first;
                first = arr[i];
            }
            
            else if (arr[i] > second){
                third = second;
                second = arr[i];
            }
            
            else if (arr[i] > third){
                third = arr[i];
            }
        }
        
        return third;
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
	    int a[n];
	    for(int i=0;i<n;i++)
	        cin>>a[i];
	   Solution obj;
	    cout<<obj.thirdLargest(a,n)<<endl;
    }
}   
// } Driver Code Ends