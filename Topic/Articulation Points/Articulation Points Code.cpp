int n; //Number of Nodes (0.....n-1)
vector < int > ADJ[ N ];  // N = MAX of n
vector < bool > VIS;
set < int > articulationPoints; // use a flag array if needed
int timer;
int inTime[ N ], lowTime[ N ];



void DFSAP( int node, int parent )
{
      VIS[ node ] = true;
      inTime[ node ] = lowTime[ node ] = timer++;
      int subTree = 0;

      for ( int i = 0; i < ADJ[ node ].size(); ++i ) {
            int child = ADJ[ node ][ i ];
            if ( child == parent )   continue;

            if ( VIS[ child ] )      lowTime[ node ] = min( lowTime[ node ], inTime[ child ] );
            else {
                  DFSAP( child, node );
                  lowTime[ node ] = min( lowTime[ child ], lowTime[ node ] );
                  if ( parent != -1 && lowTime[ child ] >= inTime[ node ] )
                        articulationPoints.insert( node );
                  ++subTree;
            }
      }

      if ( parent == -1 && subTree > 1 )
            articulationPoints.insert( node );
}

void findArticulationPoint()
{
      /* timer -> 0  and vis -> false */
      for ( int i = 0; i < n; ++i ) {
            if ( !VIS[ i ] )
                  DFSAP( i, -1 );
      }
}
