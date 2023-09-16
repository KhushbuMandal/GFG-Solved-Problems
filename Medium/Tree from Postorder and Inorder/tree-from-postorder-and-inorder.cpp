//{ Driver Code Starts
/* program to construct tree using inorder and postorder traversals */
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node {
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

/* This funtcion is here just to test buildTreeUtil() */
void preOrder(Node* node) {
    if (node == NULL) return;

    /* then print the data of node */
    printf("%d ", node->data);

    /* first recur on left child */
    preOrder(node->left);

    /* now recur on right child */
    preOrder(node->right);
}

Node* buildTree(int in[], int post[], int n);

int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        int in[n], post[n];
        for (int i = 0; i < n; i++) cin >> in[i];
        for (int i = 0; i < n; i++) cin >> post[i];
        Node* root = buildTree(in, post, n);
        preOrder(root);
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends


/* Tree node structure

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};*/

//Function to return a tree created from postorder and inoreder traversals.
int findPosition (int in[] , int ele , int n){
    for (int i = 0 ; i < n ; i++){
        if (in[i] == ele) return i;
    }
    return -1;
}

Node *getTree (int in[], int post[], int &postIndex , int instart , int inEnd , int n){
    //base case 
    if(postIndex < 0 || instart > inEnd){
        return NULL;
    }
    
    int ele = post[postIndex--];
    Node* root = new Node (ele);
    int position = findPosition(in , ele , n);
    
    root->right = getTree (in , post , postIndex ,position+1 ,inEnd , n );
    root->left = getTree (in , post , postIndex , instart , position -1 , n);
    
    return root;
}

Node *buildTree(int in[], int post[], int n) {
    int postIndex = n - 1;
    
    Node* ans = getTree (in , post , postIndex , 0 , n-1 , n);
    
    return ans;
}
