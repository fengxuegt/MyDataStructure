#include<iostream>
#include"List.h"
using namespace std;
int main()
{
    List *ll = new List;
    ll->insertHead(1);
    ll->insertHead(2);
    ll->insertHead(3);

    ll->insertTail(4);
    ll->insertTail(5);
    ll->insertTail(6);

    ll->travse();
    cout << endl;
    ll->insert(2, 8); 

    ll->travse();
    cout << endl;
    return 0;
}
