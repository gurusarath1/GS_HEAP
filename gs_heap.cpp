#include "gs_heap.h"
#include <vector>
#include <utility>
#include <iostream>

using namespace std;

gs_heap::gs_heap()
{
    gs_heap_vector.push_back(0);
}

gs_heap::gs_heap(int heap_size)
{
    gs_heap_vector.resize(heap_size + 1);
}

gs_heap::gs_heap(vector<int> &ary)
{
    gs_heap_vector.push_back(0);
    for (int i = 0; i < ary.size(); i++)
    {
        gs_heap_vector.push_back(ary[i]);
    }

    // Convert the array to heap
    heapify();
}

int gs_heap::get_heap_size()
{
    return gs_heap_vector.size() - 1;
}

bool gs_heap::is_empty()
{
    if (get_heap_size() == 0)
    {
        return true;
    }
    return false;
}

bool gs_heap::is_leaf(int index)
{
    int num_nodes = get_heap_size();
    int index_of_first_leaf_node = (num_nodes / 2) + 1;
    if (index >= index_of_first_leaf_node)
    {
        return true;
    }

    return false;
}

int gs_heap::get_parent_index(int index)
{
    int parent_index = index / 2;

    if (parent_index == 0) // 1 index heap
    {
        return GS_INVALID_HEAP_VEC_INDEX;
    }

    return parent_index;
}

pair<int, int> gs_heap::get_children_index(int index)
{
    pair<int, int> children_index;

    if (is_leaf(index))
    {
        children_index.first = GS_INVALID_HEAP_VEC_INDEX;
        children_index.second = GS_INVALID_HEAP_VEC_INDEX;
    }

    int num_nodes = get_heap_size();

    // Child 1
    int child_1_index = 2 * index;
    children_index.first = child_1_index;

    // Child 2
    int child_2_index = 2 * index + 1;
    if (child_2_index > num_nodes)
    {
        child_2_index = GS_INVALID_HEAP_VEC_INDEX;
    }
    children_index.second = child_2_index;

    return children_index;
}

void gs_heap::heapify()
{
    for (int i = gs_heap_vector.size() - 1; i > 0; i--)
    {
        if (is_leaf(i))
        {
            // Leaf nodes are heap by itself // No need to process lead nodes
            continue;
        }

        heap_down(i);
    }
}

void gs_heap::heap_down(int current_index)
{
    int current_node_val = gs_heap_vector[current_index];
    pair<int, int> children_index = get_children_index(current_index);
    int first_child_val = gs_heap_vector[children_index.first];
    int second_child_val = gs_heap_vector[children_index.second];

    while (1)
    {
        // Leaf nodes are heap by itself // No need to process lead nodes
        if (is_leaf(current_index))
            break;

        if (children_index.second != GS_INVALID_HEAP_VEC_INDEX)
        {
            // Both children exist

            if (first_child_val >= second_child_val)
            {
                if (first_child_val > current_node_val)
                {
                    // Swap with first child
                    gs_heap_vector[children_index.first] = current_node_val;
                    gs_heap_vector[current_index] = first_child_val;

                    current_index = children_index.first;
                }
                else
                {
                    // No swap
                    break;
                }
            }
            else
            {
                if (second_child_val > current_node_val)
                {
                    // Swap with second child
                    gs_heap_vector[children_index.second] = current_node_val;
                    gs_heap_vector[current_index] = second_child_val;

                    current_index = children_index.second;
                }
                else
                {
                    // No swap
                    break;
                }
            }
        }
        else
        {
            // Only left child exist
            if (first_child_val > current_node_val)
            {
                // Swap with first child
                gs_heap_vector[children_index.first] = current_node_val;
                gs_heap_vector[current_index] = first_child_val;

                current_index = children_index.first;
            }
            else
            {
                // No Swap
                break;
            }
        }

        // Next iter variables
        current_node_val = gs_heap_vector[current_index];
        children_index = get_children_index(current_index);
        first_child_val = gs_heap_vector[children_index.first];
        second_child_val = gs_heap_vector[children_index.second];
    }
}

void gs_heap::heap_up(int current_index)
{
    int current_node_val = gs_heap_vector[current_index];
    int parent_index = get_parent_index(current_index);
    int parent_val = gs_heap_vector[parent_index];

    while (parent_val < current_node_val) // Max heap condition
    {
        // swap with parent
        gs_heap_vector[parent_index] = current_node_val;
        gs_heap_vector[current_index] = parent_val;

        // Next iter variables
        current_index = parent_index;
        current_node_val = gs_heap_vector[current_index];
        parent_index = get_parent_index(current_index);
        if (parent_index == GS_INVALID_HEAP_VEC_INDEX)
            break;
        parent_val = gs_heap_vector[parent_index];
    }
}

int gs_heap::peek()
{
    if (get_heap_size() >= 1)
    {
        return gs_heap_vector[1];
    }
    else
    {
        return GS_HEAP_EMPTY;
    }
}

int gs_heap::add_value(int value)
{
    // Add the value to the end of the array
    gs_heap_vector.push_back(value);
    // and heap up
    heap_up(gs_heap_vector.size() - 1);

    return GS_HEAP_SUCCESS;
}

int gs_heap::pop_value()
{
    int last_node_value = gs_heap_vector[gs_heap_vector.size() - 1];
    gs_heap_vector[1] = last_node_value;
    gs_heap_vector.resize(gs_heap_vector.size() - 1);
    heap_down(1);

    return GS_HEAP_SUCCESS;
}

void gs_heap::print_heap()
{
    for (int i = 0; i < gs_heap_vector.size(); i++)
    {
        cout << i << " :: " << gs_heap_vector[i] << endl;
    }
}