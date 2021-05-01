int n; //Number of Nodes (0.....n-1)
vector < int > ADJ[ N ];  // N = MAX of n
vector < bool > VIS;
vector < pair < int, int > > articulationBridges;
int timer;
int inTime[ N ], lowTime[ N ];


void DFSAB( int node, int parent )
{
      VIS[ node ] = true;
      inTime[ node ] = lowTime[ node ] = timer++;

      for ( int i = 0; i < ADJ[ node ].size(); ++i ) {
            int child = ADJ[ node ][ i ];
            if ( child == parent )   continue;

            if ( VIS[ child ] )      lowTime[ node ] = min( lowTime[ node ], inTime[ child ] );
            else {
                  DFSAB( child, node );
                  lowTime[ node ] = min( lowTime[ child ], lowTime[ node ] );
                  if ( lowTime[ child ] > inTime[ node ] )
                        articulationBridges.push_back( { min( node, child ) + 1, max( node, child ) + 1 } );
            }
      }
}

void findArticulationBridge()
{
      /* timer -> 0  and vis -> false */
      for ( int i = 0; i < n; ++i ) {
            if ( !VIS[ i ] )
                  DFSAB( i, -1 );
      }
}
