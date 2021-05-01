ll segT[ 4 * N ], Lazy[ 4 * N ];


void Relax( ll L, ll R, ll idx )
{
      //Do something
      
      Lazy[ idx ] = ??; //after Relaxing
}

void built( ll L, ll R, ll idx )
{
      Lazy[ idx ] = -1;
      if ( L == R ) {
            segT[ idx ] = ??;
            return;
      }

      ll M = ( L + R ) / 2;

      BsegT( L, M, idx * 2 );
      BsegT( M + 1, R, idx * 2 + 1 );
      segT[ idx ] = segT[ idx * 2 ] ?? segT[ idx * 2 + 1 ];
}

ll QsegR( ll L, ll R, ll idx, ll l, ll r )
{
      Relax( L, R, idx );

      if ( L > r || R < l )    return 0;
      if ( L >= l && R <= r )  return segT[ idx ];

      ll M = ( L + R ) / 2;

      ll LP = QsegR( L, M, idx * 2, l, r );
      ll RP = QsegR( M + 1, R, idx * 2 + 1, l, r );
      segT[ idx ] = segT[ idx * 2 ] ?? segT[ idx * 2 + 1 ]; //is it useful?

      return LP ?? RP;
}

void UsegR( ll L, ll R, ll idx, ll l, ll r )
{
      Relax( L, R, idx );

      if ( L > r || R < l )    return;
      if ( L >= l && R <= r ) {
            // Do something
            Lazy[ idx ] = ??;
            Relax( L, R, idx );
            return;
      }

      ll M = ( L + R ) / 2;

      UsegR( L, M, idx * 2, l, r );
      UsegR( M + 1, R, idx * 2 + 1, l, r );
      segT[ idx ] = segT[ idx * 2 ] ?? segT[ idx * 2 + 1 ];
}
