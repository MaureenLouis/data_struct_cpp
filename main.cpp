#include <iostream>
#include <vector>

#include "union_find.h"

using std::cout;
using std::endl;

int main() {

    QuickUnion union_find(10);

    union_find.union_elems(0,1);
    union_find.union_elems(1,2);
    union_find.union_elems(2,3);
    union_find.union_elems(4,5);

    cout << union_find.is_connected(0,3) <<endl;



    return 0;
}
