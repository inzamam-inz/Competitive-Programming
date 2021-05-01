void zFunction( string &str )
{
      // z[ i...len ] -> z Value of string str
      int len = str.size(); // string size
      z[ 0 ] = 0;

      for ( int i = 1, l = 0, r = 0; i < len; ++i ) {
            z[ i ] = 0;
            if ( r >= i )
                  z[ i ] = min( z[ i - l ], r - i + 1 );

            while ( i + z[ i ] < len && str[ i + z[ i ] ] == str[ z[ i ] ] )
                  z[ i ]++;

            if ( i + z[ i ] - 1 > r ) {
                  l = i;
                  r = i + z[ i ] - 1;
            }
      }
}
