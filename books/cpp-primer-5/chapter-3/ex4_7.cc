#include <iostream>

using std::cout; using std::endl;

int main() {
    short svalue = 32767;
    ++svalue;
    cout << svalue << "\n";

    unsigned uivalue = 0;
    --uivalue;
    cout << uivalue << "\n";

    unsigned short usvalue = 65535;
    ++usvalue;
    cout << usvalue << "\n";

    cout << endl;

    return 0;
}
