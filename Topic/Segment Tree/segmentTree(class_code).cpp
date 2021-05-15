class segmentTree {
      #define LC( idx )      idx * 2
      #define RC( idx )      idx * 2 + 1
      public:
            struct node {
                  int Value;
                  int Lazy;
                  node () {
                        this->Value = ??;
                        this->Lazy = ??;
                  }
            };
            vector < node > segT;
            vector < int > A;

            segmentTree( int sz ) {
                  // need to clear!
                  segT.resize( 4 * sz + 10 );
                  A.resize( sz + 1 );
            }

            node merge( node L, node R ) {
                  node F;
                  F = ??
                  return F;
            }

            void Relax( int L, int R, int idx ) {
                  //Do something

                  segT[ idx ].Lazy = ??; //after Relaxing
            }

            void makeSegmentTree( int L, int R, int idx ) {
                  if ( L == R ) {
                        segT[ idx ].Value = ??;
                        return;
                  }

                  int M = ( L + R ) / 2;

                  makeSegmentTree( L, M, LC( idx ) );
                  makeSegmentTree( M + 1, R, RC( idx ) );
                  segT[ idx ] = merge( segT[ LC( idx ) ], segT[ RC( idx ) ] );
            }

            node rangeQuery( int L, int R, int idx, int l, int r ) {
                  Relax( L, R, idx );
                  
                  node F;

                  if ( L > r || R < l )    return F;
                  if ( L >= l && R <= r )  return segT[ idx ];

                  int M = ( L + R ) / 2;

                  F = merge( rangeQuery( L, M, LC( idx ), l, r ), rangeQuery( M + 1, R, RC( idx ), l, r ) );
                  segT[ idx ] = merge( segT[ LC( idx ) ], segT[ RC( idx ) ] ); //is it useful?

                  return F;
            }

            void rangeUpdate( int L, int R, int idx, int l, int r, int val ) {
                  Relax( L, R, idx );

                  if ( L > r || R < l )    return;
                  if ( L >= l && R <= r ) {
                        // Do something
                        segT[ idx ].Lazy = ??;
                        Relax( L, R, idx );
                        return;
                  }

                  int M = ( L + R ) / 2;

                  rangeUpdate( L, M, LC( idx ), l, r, val );
                  rangeUpdate( M + 1, R, RC( idx ), l, r, val );

                  segT[ idx ] = merge( segT[ LC( idx ) ], segT[ RC( idx ) ] );
            }
};
