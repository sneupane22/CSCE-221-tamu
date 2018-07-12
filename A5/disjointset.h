#pragma once

#include "TemplateDoublyLinkedList.h"
#include <cstddef>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Disjoint Set
template <typename T>
class DisjointSet {
private:
	vector<DListNode<T>*> nodeLocator;
public:
    ~DisjointSet(){nodeLocator.clear();};
    
    DisjointSet(int n){nodeLocator.resize(n); nodeLocatorCopy.resize(n);}//constructor
    
    vector<DListNode<T>*> getNodeLocator() const{return nodeLocator;}
    vector<DListNode<T>*> nodeLocatorCopy; // to hold initial nodes from make set we have to create new vector because the nodeLocator vector will be tampered with for unioning purposes
	DListNode<T>* MakeSet(int key, T node);
	DListNode<T>* Union(DListNode<T> nodeI, DListNode<T> nodeJ);
	DListNode<T>* FindSet(DListNode<T> node);
	DListNode<T>* FindSet(int nodeKey);
};

//make set
template <typename T>
DListNode<T>* DisjointSet<T>::MakeSet(int key, T node){
    
    DListNode<T>* newNode = new DListNode<T>(key,node); // create new node with key value and node element
    newNode->setRepresentative(newNode); // set representative to itself
    newNode->setTrailer(newNode); // set trailer to itself
    if(nodeLocator.size() > key && nodeLocatorCopy.size() > key) // executes for keys 1 2 3 4
    {
        nodeLocator[key] = newNode;
        nodeLocatorCopy[key] = newNode;
    }
    else{
        nodeLocator.resize(2*key); //executes for key 5
        nodeLocatorCopy.resize(2*key);
        nodeLocator[key] = newNode;
        nodeLocatorCopy[key] = newNode;
    }
    
    return newNode;
}


//union
template <typename T>
DListNode<T>* DisjointSet<T>::Union(DListNode<T> nodeI, DListNode<T> nodeJ){
 

    if (nodeI.getListSize() > nodeJ.getListSize())
    {
        
        nodeJ.getTrailer()->setNext(nodeI.getRepresentative()); // node J gets itself and makes next link to node I
        nodeI.setPrevious(nodeJ.getTrailer()); //Node I sets its previous link to node J
        nodeI.setRepresentative(nodeJ.getRepresentative()); // Update representaive
        nodeI.getRepresentative()->setListSize(nodeI.getListSize()+nodeJ.getListSize());
        //delete element that is to be unioned
        swap(nodeLocator[nodeI.getKey()], nodeLocator.back());
        nodeLocator.pop_back();
        return nodeJ.getRepresentative();
    }
    else
    {
    nodeI.getTrailer()->setNext(nodeJ.getRepresentative()); // NodeI gets its self and makes a next link to nodeJ (basically make nodeI next partition point to nodeJ)
    nodeJ.setPrevious(nodeI.getTrailer()); //NodeJ makes a previous link to nodeI
    nodeJ.setRepresentative(nodeI.getRepresentative());// update node J representative
    nodeI.getRepresentative()->setListSize(nodeI.getListSize()+nodeJ.getListSize());
    nodeJ.getRepresentative()->setListSize(nodeI.getListSize()+nodeJ.getListSize());
    
    //delete element that is to be unioned
    swap(nodeLocator[nodeJ.getKey()], nodeLocator.back());
    nodeLocator.pop_back();
    return nodeI.getRepresentative();
    }
    
    return NULL;
    
}


//findset
template <typename T>
DListNode<T>* DisjointSet<T>::FindSet(DListNode<T> node){
    
    return node.getRepresentative(); // return representative cause only finds set on one element so just returning what ever is in the set
}

//findset
template <typename T>
DListNode<T>* DisjointSet<T>::FindSet(int nodeKey){
    
    if(nodeKey == 0)
        cerr << "Cannot find set.\n";
    if(nodeLocatorCopy[nodeKey] != NULL)
        return nodeLocatorCopy[nodeKey]->getRepresentative(); // return whatever is in the vector[key] representative.
    
    return nodeLocatorCopy[nodeKey]->getRepresentative(); // return again
}


template <typename T>
ostream& operator<<(ostream& out, const DisjointSet<T>& ds) {
	
    vector<DListNode<T>*> tempNodeIter = ds.getNodeLocator();
    for (int i = 0; i< tempNodeIter.size(); ++i){
        
        
        if(tempNodeIter[i] != NULL && tempNodeIter[i] == (tempNodeIter[i])->getRepresentative())// as long as something in set, and that something is itself
        {
            out << "{";
            DListNode<T>* tempNode = (tempNodeIter[i])->getRepresentative();  // set a temporary node to whatever node iterating through
            while (tempNode != NULL)
            {
                out << tempNode->getElem(); //get elem as long as temp node's next is not equal to null
                tempNode = tempNode->getNext();
            }
            out << "}\n";
        }
    }
   
    return out;
}