class segmentTree {
      public:
            vector < ll > segT;
            vector < ll > Lazy;

            segmentTree( int n ) {
                  // need to clear!
                  segT.resize( 4 * n + 10, ?? );
                  Lazy.resize( 4 * n + 10, ?? );
            }

            ll marge( int L, int R, int idx ) {
                  return segT[ L ] ?? segT[ R ];
            }

            void Relax( int L, int R, int idx ) {
                  //Do something

                  Lazy[ idx ] = ??; //after Relaxing
            }

            void makeSegmentTree( int L, int R, int idx ) {
                  Lazy[ idx ] = ??;
                  if ( L == R ) {
                        segT[ idx ] = ??;
                        return;
                  }

                  int M = ( L + R ) / 2;

                  BsegT( L, M, idx * 2 );
                  BsegT( M + 1, R, idx * 2 + 1 );
                  segT[ idx ] = marge( idx * 2, idx * 2 + 1, idx );
            }

            ll rangeQuery( int L, int R, int idx, int l, int r ) {
                  Relax( L, R, idx );

                  if ( L > r || R < l )    return 0;
                  if ( L >= l && R <= r )  return segT[ idx ];

                  int M = ( L + R ) / 2;

                  ll LP = rangeQuery( L, M, idx * 2, l, r );
                  ll RP = rangeQuery( M + 1, R, idx * 2 + 1, l, r );
                  segT[ idx ] = marge( idx * 2, idx * 2 + 1, idx ); //is it useful?

                  return LP ?? RP;
            }

            void rangeUpdate( int L, int R, int idx, int l, int r ) {
                  Relax( L, R, idx );

                  if ( L > r || R < l )    return;
                  if ( L >= l && R <= r ) {
                        // Do something
                        Lazy[ idx ] = ??;
                        Relax( L, R, idx );
                        return;
                  }

                  int M = ( L + R ) / 2;

                  rangeUpdate( L, M, idx * 2, l, r );
                  rangeUpdate( M + 1, R, idx * 2 + 1, l, r );

                  segT[ idx ] = marge( idx * 2, idx * 2 + 1, idx );
            }
};
