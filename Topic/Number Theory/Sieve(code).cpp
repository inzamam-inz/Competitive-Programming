const ll MSS;       //for sieve function
vector < ll > sie;  //for sieve function
ll spf[ MSS + 7 ];  //for sieve function

void sieve() 
{    
      // [ 1 - MSS ]
      for ( ll i = 2; i < MSS; ++i ) {  
            if ( spf[ i ] == 0 ) {
                  spf[ i ] = i;   
                  sie.push_back( i );  
            }    
            for ( ll j = 0; j < sie.size() && i * sie[ j ] <= MSS && sie[ j ] <= spf[ i ]; ++j ) {
                  spf[ i * sie[ j ] ] = sie[ j ]; 
            }
      }
}
