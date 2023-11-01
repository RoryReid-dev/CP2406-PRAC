#include "key_value_pair.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
    KeyValuePair<int, double> kv1{ 69, 2.33 };
    cout << kv1.getKey() << " = " << kv1.getValue() << "\n";

    KeyValuePair<string, int> kv2{ "Craig David", 974613 };
    cout << kv2.getKey() << " = " << kv2.getValue() << "\n";
}
