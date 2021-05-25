#include<bits/stdc++.h>
using namespace std;

const int N = 10;
vector < pair < int, int > > edge[ N ];
int DP[ N ];


// For DAG
int F( int u )
{
      if ( DP[ u ] != -1 )   return DP[ u ];
      
      int cost = 10000;
      for ( int i = 0; i < edge[ u ].size(); ++i ) {
            cost = min( cost, edge[ u ][ i ].second + F( edge[ u ][ i ].first ) );
      }
      
      return cost;
}

int main()
{
      // Plz don't use this when there is a cycle
      int n, m;
      cin >> n >> m;
      
      for ( int i= 0; i < m; ++i ) {
            int u, v, c;
            cin >> u >> v >> c;
            edge[ u ].push_back( { v, c } );
      }
      
      for ( int i = 0; i < n; ++i )
            DP[ i ] = -1;
            
      DP[ n - 1 ] = 0;   // Node ( n - 1 ) is our Goal Node
      // Complexity -> O( n * n );
      int ans = F( 0 );  // Node ( 0 ) is our Start Node
      
      cout << ans << "\n";
      
      return 0;
}
