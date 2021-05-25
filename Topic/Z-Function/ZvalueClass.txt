class ZFunction {
      public:
            string S;
            vector < int > Z;
            ZFunction( string S ) {
                  this->S = S;
                  Z.resize( S.size() );
                  Z[ 0 ] = 0;
            }
    
            void calZvalue() {
                  int L = 0, R = 0, len = S.size();
                  for ( int i = 1; i < len; ++i ) {
                        Z[ i ] = 0;
                        if ( i <= R )  
                              Z[ i ] = min( Z[ i - L ], R - i + 1 );

                        while ( i + Z[ i ] < len && S[ i + Z[ i ] ] == S[ Z[ i ] ] ) 
                              Z[ i ]++;

                        if ( i + Z[ i ] - 1 > R )  
                              L = i, R = i + Z[ i ] - 1;
                  }
            }
};
