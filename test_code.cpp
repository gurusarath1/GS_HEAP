#include <iostream>
#include "gs_heap.h"

int main()
{
    vector<int> ary = {3, 4, 1, 5, 6, 7, 8, 2, 1, 2, 10, 9};
    gs_heap h1(ary);

    h1.add_value(15);
    h1.add_value(0);
    h1.add_value(15);
    h1.add_value(13);
    h1.add_value(14);
    h1.add_value(12);
    h1.add_value(12);
    h1.print_heap();

    while (!h1.is_empty())
    {
        cout << h1.peek() << endl;
        h1.pop_value();
    }

    vector<int> ary2 = {1};
    gs_heap h2(ary2);

    h2.print_heap();

    while (!h2.is_empty())
    {
        cout << h2.peek() << endl;
        h2.pop_value();
    }

    h2.add_value(1);
    h2.print_heap();

    h2.add_value(2);
    h2.print_heap();

    h2.add_value(3);
    h2.print_heap();

    h2.add_value(4);
    h2.print_heap();

    h2.add_value(5);
    h2.print_heap();

    while (!h2.is_empty())
    {
        cout << h2.peek() << endl;
        h2.pop_value();
    }
    return 0;
}