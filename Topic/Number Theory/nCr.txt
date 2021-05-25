ll F[ N ], FI[ N ];

ll powerMod( ll par1, ll par2, ll par3 )
{     
      /* ( par1 ^ par2 ) % par3 */
      /* O( log(par2) ) */
      
      ll res = 1;
      par1 %= par3;
      assert( par2 >= 0 );

      for( ; par2; par2 >>= 1 ) {
            if ( par2 & 1 ) 
                  res = res * par1 % par3;
            par1 = par1 * par1 % par3;
      }

      return res;
}

void fact( )
{
      /* O( N ) */
      F[ 0 ] = 1;
      FI[ 0 ] = powerMod( F[ 0 ], MOD - 2, MOD );

      for ( int i = 1; i < N; ++i ) {
            F[ i ] = ( F[ i - 1 ] * i ) % MOD;
            FI[ i ] = powerMod( F[ i ], MOD - 2, MOD );
      }
}

ll nCr( ll x, ll y )
{
      /* O( 1 ) */
      if ( x < y )   return 0;
      return  ( ( F[ x ] * ( ( FI[ y ] * FI[ x - y ] ) % MOD ) ) % MOD );
}
