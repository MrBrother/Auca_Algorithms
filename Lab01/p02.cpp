#include <iostream>
#include <list>

using namespace std;

void printInDirectOrder(const list<int>& lst)
{
    for (auto e: lst) {
        cout << e << " ";
    }
    cout << endl;
}

void printInReversedOrder(const list<int>& lst)
{
    for (auto it = lst.rbegin(); it != lst.rend(); ++it)
    {
        cout << *it << " ";
    }
    cout << endl;
}

int main()
{


    list<int> lst;
    cout << sizeof(lst) << endl;

    int x;
    while (cin >> x)
    {
        lst.push_back(x);
    }

    printInDirectOrder(lst);
    printInReversedOrder(lst);

    for (auto it = lst.begin(); it != lst.end();)
    {
        if (*it % 2 == 0)
        {
            it = lst.insert(it, 0);
            ++it;
        }
        ++it;
    }

    printInDirectOrder(lst);
    printInReversedOrder(lst);

    for (list<int>::iterator it = lst.begin(); it != lst.end();)
    {
        if (*it % 2 == 0)
        {
            it = lst.erase(it);
        }
        else
        {
            ++it;
        }
    }

    printInDirectOrder(lst);
    printInReversedOrder(lst);

    return 0;
}
