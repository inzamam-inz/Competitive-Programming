int block_size;
class MOsALGO {  /* 0-base index */
      public:
            struct query {
                  int L, R, idx;
                  bool operator < ( query other ) const {
                        return ( make_pair( L / block_size, R ) < make_pair( other.L / block_size, other.R ) );
                  }
            };

            vector < int > Cnt;
            vector < query > Qry;
            vector < int > Arr;

            MOsALGO( int sz, int nq ) {
                  block_size = (int) sqrt( sz + 0.0 ) + 1;
                  Qry.resize( nq );
                  Cnt.resize( 1000009 );
                  Arr.resize( sz );
            }

            ll add( int idx ) {
                  ll res = (ll) Cnt[ Arr[ idx ] ] * Cnt[ Arr[ idx ] ];
                  Cnt[ Arr[ idx ] ]++;
                  res = (ll) Cnt[ Arr[ idx ] ] * Cnt[ Arr[ idx ] ] - res;

                  return res * Arr[ idx ];
            }

            ll del( int idx ) {
                  ll res = (ll) Cnt[ Arr[ idx ] ] * Cnt[ Arr[ idx ] ];
                  Cnt[ Arr[ idx ] ]--;
                  res = (ll) Cnt[ Arr[ idx ] ] * Cnt[ Arr[ idx ] ] - res;

                  return res * Arr[ idx ];
            }

            void getANS( vector < ll > &ANS ) {
                  ll POWER = 0;
                  int CL = -1, CR = -1;
                  sort( Qry.begin(), Qry.end() );
                  for ( int i = 0; i < ANS.size(); ++i ) {
                        while ( CR < Qry[ i ].R )        POWER += add( ++CR );
                        while ( CR > Qry[ i ].R )        POWER += del( CR-- );

                        while ( CL + 1 < Qry[ i ].L )    POWER += del( ++CL );
                        while ( CL >= Qry[ i ].L )       POWER += add( CL-- );

                        ANS[ Qry[ i ].idx ] = POWER;
                  }
            }
};
