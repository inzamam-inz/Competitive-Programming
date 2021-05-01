void DFSMVC( ll u )
{
      // vis[ number of vertex ] -> is it visited?
      // DP[ number of vertex ][ 2 ]  -> memo 
      vis[ u ] = true;

      ll cost0 = 0; // if v is not taken
      ll cost1 = 1; // if v is taken

      rep( i, 0, adj[ u ].size() ) {
            ll v = adj[ u ][ i ];
            if ( !vis[ v ] ) {
                  DFSMVC( v );
                  cost0 += DP[ v ][ 1 ];
                  cost1 += min( DP[ v ][ 0 ], DP[ v ][ 1 ] );
            }
      }

      DP[ u ][ 0 ] = cost0;
      DP[ u ][ 1 ] = cost1;
}

ll MVC()
{
      // suppose root is 1;
      // DP[ v ][ 1 ] mane if v is taken
      // DP[ v ][ 0 ] mane if v is not taken

      DFSMVC( 1 ); // vertex are[ 1....n ]

      return min( DP[ 1 ][ 0 ], DP[ 1 ][ 1 ] );
}
