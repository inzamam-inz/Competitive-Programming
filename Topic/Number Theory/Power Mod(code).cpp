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
