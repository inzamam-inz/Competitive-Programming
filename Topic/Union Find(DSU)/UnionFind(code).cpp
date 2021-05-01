int par[ N ], SIZ[ N ];


void init()
{
      for ( int i = 1; i <= N; ++i ) {
            par[ i ] = i;
            SIZ[ i ] = 1;
      }
}

int find_root( int u )
{
      if ( par[ u ] != u )
            par[ u ] = find_root( par[ u ] );

      return par[ u ];
}

void marge( int u, int v )
{
      if ( find_root( u ) != find_root( v ) ) {
            if ( SIZ[ par[ u ] ] <= SIZ[ par[ v ] ] )   swap( u, v );

            SIZ[ par[ u ] ] += SIZ[ par[ v ] ];
            par[ par[ v ] ] = par[ u ];
      }
}
