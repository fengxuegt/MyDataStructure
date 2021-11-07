#include<iostream>
#include"Node.h"
using namespace std;
Node::Node(int data)
{
    this->data = data;
}
Node::Node()
{
    
}
void Node::printNode() {
    cout << data << " ";
}