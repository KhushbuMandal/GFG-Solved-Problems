//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
		string FirstNonRepeating(string A){
		    
		    //To store the count of Element
		    unordered_map <char , int> count;
		    
		    //To keep the track of element
		    queue<int> q;
		    
		    //to store the ans
		    string ans = "";
		    
		    //WE will iterate through each elem and increase its count count[ch]++; and then push in queue
		    //tab tak q empty nhi ho jata if count[q.front()] > 1 q.pop() else ans.push_back(q.front()) break
		    // while se bhar if (q.empty) ans me store "#"
		    //return ans
		    
		    for (int i = 0 ; i < A.length() ; i++){
		        char ch = A[i];
		        count [ch]++;
		        q.push (ch);
		        
		        while (!q.empty()){
		            if (count[q.front()] > 1) q.pop();
		            
		            else {
		                 ans.push_back(q.front());
		                 break;
		            }       
		        }
		        
		        if (q.empty()) ans.push_back('#');
		        
		    }
		    
		    return ans;
	}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends