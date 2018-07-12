#include "Graph.h"
#include "disjointset.h"
#include "TemplateDoublyLinkedList.h"
#include <iostream>


using namespace std;


void Graph::buildGraph() {
  if((n<0) || (e<0)){
    throw GraphException("either row or column is negative!");
  }
  //implement your code here
   /* for (int i = 0; i < n; ++i)
    {
        Vertex *emptyVertex = new Vertex(i); // create vertex
        DListNode<Vertex>* nodeList = new DListNode<Vertex>(i,*emptyVertex); // make a new node for each vertex created
        AdjacencyList.push_back(nodeList); // push this node into the adj list
    }
    */
    //create empty adjacency list with each node being pushed into the vector
    for (int i=0; i<n; i++)
    {
        DListNode<Vertex>* emptyVer = new DListNode<Vertex>(i, Vertex(i));
        AdjacencyList.push_back(emptyVer);
    }
}


void Graph::insertEdge(int i, int j, double w) {
    
  if(curEdges >= e){
    throw GraphException("edge number is not correct!");
  }
  //implement your code here insertEdge(0,1,9) insertEdge(0,2,3)
    
    Edge *newEdge = new Edge(i,j,w); // create the edge and push into the vector
    EdgeList.push_back(newEdge);
    
    DListNode<Vertex>* V1 = AdjacencyList[i]->insert_after(j, Vertex(j));
    DListNode<Vertex>* V2 = AdjacencyList[j]->insert_after(i, Vertex(i));
    
    V1->getElem().edge = newEdge;
    V2->getElem().edge = newEdge;
    
    curEdges++;
    return;

}

double Graph::getWeight(int i, int j) {
  //implement your code here
    DListNode<Vertex> *temp = AdjacencyList[i];
    while(temp != NULL)
    {
        if (temp->getElem().index == j)
        {
            if(temp->getElem().edge == NULL)
                return 0;
            else
                return temp->getElem().edge->weight;
        }
        
        temp = temp->getNext();
    }
    
    return 0;
}







bool comparasionFunct(Edge* i, Edge* j)
{
    return (i->weight < j->weight);
}

void Graph::sortEdge() {
    //implement your code here
    sort(EdgeList.begin(), EdgeList.end(), comparasionFunct);
    
}





double Graph::MSTAlgo() {
    
    //implement your code here
    
    DisjointSet<Vertex> nodeSet(2); // create disjoint set
    for (int i =0; i<AdjacencyList.size(); i++)
        nodeSet.MakeSet(i, Vertex(i));
    
    sortEdge();
    
    for (int j = 0; j <EdgeList.size(); j++)
    {
        int u = EdgeList[j]->vertex_i;
        int v = EdgeList[j]->vertex_j;
        if (nodeSet.FindSet(u) != nodeSet.FindSet(v))
        {
            MST.push_back(EdgeList[j]); // push into mst if not equal
            nodeSet.Union(*(nodeSet.FindSet(u)),*(nodeSet.FindSet(v)));
        }
        
    }
    
    
    //get total value
    double MST_Value = 0;
    for (int k = 0; k <MST.size()-1; k++)
    {
        MST_Value = MST_Value + MST[k]->weight;
    }
    return MST_Value;
}

  