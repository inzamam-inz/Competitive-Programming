struct Node {
      Node *left, *right;
      int val;
      int cnt;
      Node ( int val ) {
            this->val = val;
            this->cnt = 1;
            this->left = NULL;
            this->right = NULL;
      }
};

class BST {
      public:
            Node *info = NULL;
          
            Node* insert( Node *root, int val ) {
                  if ( root == NULL )            return new Node( val );
                  else if ( root->val == val )   root->cnt++;
                  else if ( root->val > val )    root->left = insert( root->left, val );
                  else                           root->cnt++, root->right = insert( root->right, val );
              
                  return root;
            }
          
            int search( Node *root, long tar ) {
                  if ( root == NULL )            return 0;
                  else if ( tar == root->val )   return root->cnt;
                  else if ( root->val > tar )    return root->cnt + search( root->left, tar );
                  else                           return search( root->right, tar );
            }
          
            void print( Node *root ) {
                  if ( root == NULL )  return;
                  cout << root->val;
                  print( root->left );
                  print( root->right );
            }
};
