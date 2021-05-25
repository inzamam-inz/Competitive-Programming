ll knapsack( ll need )
{
      // DP[ need ] -> memo
      // P -> profit
      // W -> weight
      for ( ll i = 1; i <= W.size(); ++i ) {
            for ( ll j = need; j >= 0; --j ) {
                  if ( j - W[ i ] >= 0  ) {
                        DP[ j ] = max( DP[ j ], DP[ j - W[ i ] ] + P[ i ] );
                  }
            }
      }
      cout << DP[ need ] << "\n";
}
