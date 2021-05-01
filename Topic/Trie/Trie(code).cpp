class TrieNode { // from http://www.shafaetsplanet.com/?p=1679
      public:
            struct node {  // only lower-case letter
                  bool endmark;
                  node* next[ 26 + 1 ];
                  node() {
                        endmark = false;
                        for ( int i = 0; i < 26; ++i )
                        next[ i ] = NULL;
                  }
            } * root;

            void insert( string str ) {
                  int len = str.size();
                  node* curr = root;
                  for ( int i = 0; i < len; ++i ) {
                        int id = str[ i ] - 'a';
                        if ( curr->next[ id ] == NULL )
                        curr->next[ id ] = new node();
                        curr = curr->next[ id ];
                  }
                  curr->endmark = true;
            }

            bool search( string str ) {
                  int len = str.size();
                  node* curr = root;
                  for ( int i = 0; i < len; ++i ) {
                        int id = str[ i ] - 'a';
                        if ( curr->next[ id ] == NULL )
                        return false;
                        curr = curr->next[ id ];
                  }
                  return curr->endmark;
            }

            void del( node* cur ) {
                  for ( int i = 0; i < 26; i++ )
                        if ( cur->next[ i ])
                        del( cur->next[ i ] );

                  delete ( cur );
            }

            TrieNode() {
                  root = new node();
            }
};
