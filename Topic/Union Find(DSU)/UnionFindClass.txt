class UnionFind {
      private: vector < int > par, SIZ;
      public:
            UnionFind( int sz ) {
                  for ( int i = 0; i < sz; ++i ) {
                        par.push_back( i );
                        SIZ.push_back( 1 );
                  }
            }

            int find_root( int u ) {
                  if ( par[ u ] != u )
                        par[ u ] = find_root( par[ u ] );

                  return par[ u ];
            }

            void marge( int u, int v ) {
                  if ( find_root( u ) != find_root( v ) ) {
                        if ( SIZ[ par[ u ] ] <= SIZ[ par[ v ] ] )   swap( u, v );

                        SIZ[ par[ u ] ] += SIZ[ par[ v ] ];
                        par[ par[ v ] ] = par[ u ];
                  }
            }
};
