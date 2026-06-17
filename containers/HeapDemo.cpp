#include <iostream>
#include <initializer_list>
#include <tuple>
#include <utility>
#include "container_demo_utils.h"
#include "heap.h"
#include "../types.h"
using namespace std;

template <typename Trait>
void RunHeapDemo(const string &title) {
    cout << "\n" << title << endl;
    Heap<Trait> heap;
    InsertContainerItems(heap, {{47, 9031}, {-12, 418}, {86, 1207}, {7, 7764}, {31, 59}, {-4, 6402}});
    cout << heap << endl;
    PrintContainerItem("peek: ", heap.peek());
    PrintContainerItem("extract: ", heap.extract());
    cout << heap << endl;
}

void DemoMinHeap() {
    RunHeapDemo<MinHeapTrait<T1>>("Demo MinHeap");
}

void DemoMaxHeap() {
    RunHeapDemo<MaxHeapTrait<T1>>("Demo MaxHeap");
}

void HeapDemo() {
    DemoMinHeap();
    DemoMaxHeap();
}
