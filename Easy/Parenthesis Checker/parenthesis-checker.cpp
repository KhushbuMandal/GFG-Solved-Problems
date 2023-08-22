//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    bool ispar(string x)
    {
       int n = x.length();
       
       if (n % 2 != 0){
          return false; 
       }
       else {
           stack <char> st;
           st.push('h');
           
           for (int i = 0; i < n ; i++){
               char ch = x[i];
               if (ch == '{' || ch == '[' || ch == '('){
                   st.push(ch);
               }
               else if ( (ch == '}' && st.top() == '{') 
                       ||(ch == ']' && st.top() == '[') 
                       ||(ch == ')' && st.top() == '(')){
                           st.pop();
               }
               else {
                   return false;
               }
           }
           
            if (st.top() == 'h') return true;
            else return false;
       }
       
    }

};

//{ Driver Code Starts.

int main()
{
   int t;
   string a;
   cin>>t;
   while(t--)
   {
       cin>>a;
       Solution obj;
       if(obj.ispar(a))
        cout<<"balanced"<<endl;
       else
        cout<<"not balanced"<<endl;
   }
}
// } Driver Code Ends