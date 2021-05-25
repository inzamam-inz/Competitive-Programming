
/* O( log(max( a, b )) */

/* GCD */
/* Cpp STL */
ll gcd( ll a, ll b ) 
{ 
      return __gcd( a, b );
}

/* normal version */
ll gcd( ll par1, ll par2 )
{
      return par2 ? gcd( par2, par1 % par2 ) : par1;
}

/* faster version( Maybe ) */
ll gcd( ll a, ll b ) {
      if ( !a || !b )    return a | b;
        
      unsigned shift = __builtin_ctz( a | b );
      a >>= __builtin_ctz( a );
    
      do {
            b >>= __builtin_ctz( b );
            if ( a > b )
                  swap( a, b );
            b -= a;
      } while ( b );
    
      return a << shift;
}

/* LCM */
ll lcm( ll a, ll b )
{
    return a / gcd( a, b ) * b;
}


/* GCD-LCM */
ll gcd( ll par1, ll par2 )
{
      return par2 ? gcd( par2, par1 % par2 ) : par1;
}

ll lcm( ll par1, ll par2 )
{
      return par1 * par2 / gcd( par1, par2 );
}
