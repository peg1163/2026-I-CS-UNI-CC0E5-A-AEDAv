#include <iostream>
#include <initializer_list>
#include <sstream>
#include <utility>
#include "container_demo_utils.h"
#include "hashtable.h"
#include "../types.h"
using namespace std;

using DemoHashNode = HashNode<T1, T1>;
using DemoHashTable = HashTable<HashTableTrait<DemoHashNode>>;

void HashTableDemo() {
    cout << "\nDemo HashTable (AVL)" << endl;
    DemoHashTable table(7);

    InsertContainerItems(table, {{42, 7081}, {119, -36}, {203, 945}, {56, 12012}, {77, 301}});
    table[5] = 3;
    table[14] = 8088;
    table[119] = -41;

    cout << table << endl;
    PrintContainerLookup("table", table, 5);
    PrintContainerLookup("table", table, 14);
    cout << "contains(203): " << table.contains(203) << endl;
    PrintContainerItems(table);

    DemoHashTable copy(table);
    DemoHashTable moved(std::move(copy));
    cout << "moved copy: " << moved << endl;

    stringstream input("[(301,234),(58,653453),(-17,11),(912,2334),(44,-606)]");
    DemoHashTable fromStream(7);
    input >> fromStream;
    cout << "from stream: " << fromStream << endl;
}
