#include <iostream>
#include <string>

using std::string;
using std::cout; using std::cin; using std::endl;

int main()
{
    string result;
    string resultWithSpace;
    string s;
    while (cin >> s)
    {
        result += s;
        if (resultWithSpace.empty())
            resultWithSpace += s;
        else
            resultWithSpace += " " + s;
    }

    cout << "\nThe concatenated string is: " << result << endl;
    cout << "\nTeh concatenated string with space is: " << resultWithSpace << endl;

    return 0;
}
