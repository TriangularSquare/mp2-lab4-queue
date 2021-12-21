#include <iostream>
#include "TQueueL.h"

void main() {
    /*
    TQueueL<int> tql;
    int size, elem;
    cout << "Enter size: ";
    cin >> size;
    cout << "Enter elements to push: ";
    for (int i = 0; i < size; i++) {
        cin >> elem;
        tql.Push(elem);
    }
    cout << tql;
    */
    setlocale(LC_ALL, "russian");
    setlocale(LC_NUMERIC, "eng");

    TQueueL<int> tql;
    cout << "tql: " << tql << "\nEmpty = " << tql.IsEmpty() << "\n\n";

    for (int i = 1; i <= 3; i++) {
        cout << i << " pushed:\n";
        tql.Push(i);
        cout << tql << "\nEmpty = " << tql.IsEmpty() << "\n\n";
    }
    cout << "\n";

    cout << "Assign qu to qu2 and clear qu:\n";
    TQueueL<int> tql2 = tql;
    tql.Clear();
    cout << "tql: " << tql << "\nEmpty = " << tql.IsEmpty() << "\n\n";
    cout << "tql2: " << tql2 << "\nEmpty = " << tql2.IsEmpty() << "\n\n";


    cout << "We can't pop from tql again:\n";
    try {
        tql.Pop();
    }
    catch (...) {
        cout << "Exception\n\n";
    }

    cout << "Then we continue with tql2.\n\n";

    for (int i = 1; i <= 3; i++) {
        cout << tql2.Pop() << " popped:\n";
        cout << tql2 << "\nEmpty = " << tql.IsEmpty() << "\n\n";
    }
    cout << "\n";


    for (int i = 4; i <= 6; i++) {
        cout << i << " pushed:\n";
        tql2.Push(i);
        cout << tql2 << "\nEmpty = " << tql2.IsEmpty() << "\n\n";
    }

    cout << "Other tests:\n\n";
    TQueueL<int> tql3(tql2);

    cout << "tql2: " << tql2 << "\nEmpty = " << tql2.IsEmpty() << "\n\n";
    cout << "tql3(tql22): " << tql3 << "\nEmpty = " << tql3.IsEmpty() << "\n\n";

    cout << "(tql3 == tql2) = " << (tql3 == tql2) << "\n\n";

    cout << tql2.Pop() << " popped from tql2:\n";
    cout << "tql2: " << tql2 << "\nEmpty = " << tql2.IsEmpty() << "\n\n";

    cout << "(tql3 == tql2) = " << (tql3 == tql2) << "\n";
}
