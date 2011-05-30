#include <ogdf/basic/Graph.h>
#include <ogdf/basic/CombinatorialEmbedding.h>
#include <ogdf/energybased/FMMMLayout.h>

#include <iostream>
#include <common/macros.h>

using namespace ogdf;
using namespace std;

int main()
{
/*
    Graph G;
    node prev = G.newNode(0);
    G.newEdge( prev, G.newNode(9));
    loop(i,9){
        node curr = G.newNode(i+1);
        G.newEdge( prev, curr);
        prev = curr;
    }
    CombinatorialEmbedding ce(G);

    cout << ce.numberOfFaces() << endl;

    GraphAttributes GA(G);
*/
    Graph G;
    GraphAttributes GA(G);
    if( !G.readGML("sierpinski_04.gml") ) {
        cerr << "Could not load sierpinski_04.gml" << endl;
        return 1;
        }
    node v;
    forall_nodes(v,G)
        GA.width(v) = GA.height(v) = 10.0;
 
    FMMMLayout fmmm;
 
    fmmm.useHighLevelOptions(true);
    fmmm.unitEdgeLength(15.0); 
    fmmm.newInitialPlacement(true);
    fmmm.qualityVersusSpeed(FMMMLayout::qvsGorgeousAndEfficient);
 
    fmmm.call(GA);
    GA.writeGML("sierpinski_04-layout.gml");


    return 0;
}
