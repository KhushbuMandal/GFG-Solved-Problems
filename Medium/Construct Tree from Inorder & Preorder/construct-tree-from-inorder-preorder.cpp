//{ Driver Code Starts
//

#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};


void printPostOrder(Node *root)
{
	if(root==NULL)
		return;
	printPostOrder(root->left);
	printPostOrder(root->right);
	cout<<root->data<<" ";
}

// } Driver Code Ends

/*Complete the code here.
Node is as follows:
struct Node
{
  int data;
  Node* left;
  Node* right;
};
*/
class Solution{
    public:
    
    int findPosition (int in[] , int ele , int inorderStart , int inorderEnd){
        for (int i = inorderStart; i <= inorderEnd ; i++){
            if (in[i] == ele){
                return i;
            }
        } 
        
        return -1;
    }
    
    Node* getPostOrder (int in[] , int pre[] , int &index , int inorderStart , int inorderEnd , int n){
        //base case
        if (index >= n || inorderStart > inorderEnd){
            return NULL;
        }
        
        int element = pre[index++];
        Node* root = new Node (element);
        int position = findPosition (in , element , inorderStart , inorderEnd);
        
        root->left = getPostOrder (in , pre , index , inorderStart , position - 1 , n);
        root->right = getPostOrder (in , pre , index , position + 1 , inorderEnd , n);
        
        return root;
        
    }
    
    Node* buildTree(int in[],int pre[], int n)
    {
       int preOrderIndex = 0;
       
       Node* ans = getPostOrder (in , pre , preOrderIndex , 0 , n-1 , n);
       
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
		int n;
		cin>>n;
		
		int inorder[n], preorder[n];
		for(int i=0; i<n; i++)
			cin>> inorder[i];
		for(int i=0; i<n; i++)
			cin>> preorder[i];
		Solution obj;
		Node *root = obj.buildTree(inorder, preorder, n);
		printPostOrder(root);
		cout<< endl;
	}
}

// } Driver Code Ends