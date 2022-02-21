#ifndef GS_HEAP_INCLUDE
#define GS_HEAP_INCLUDE

#include <vector>
#include <utility>

using namespace std;

#define GS_INVALID_HEAP_VEC_INDEX -1
#define GS_HEAP_EMPTY INT_MIN
#define GS_HEAP_SUCCESS 1

class gs_heap
{
    // Max Heap
private:
    vector<int> gs_heap_vector;
    void heapify();
    void heap_down(int current_index);
    void heap_up(int current_index);

public:
    gs_heap();

    gs_heap(int heap_size);

    gs_heap(vector<int> &ary);

    int get_heap_size();
    bool is_empty();
    bool is_leaf(int index);
    pair<int, int> get_children_index(int index);
    int get_parent_index(int index);

    int peek();
    int add_value(int value);
    int pop_value();

    void print_heap();
};

#endif