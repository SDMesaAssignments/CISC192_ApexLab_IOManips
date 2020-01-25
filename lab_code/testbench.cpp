//
// Don't modify code in this file, with the exception
// of adding test cases.
//
#include <iostream>
#include <fstream>
#include "apex_code.h"

using namespace std;

#define TEST_FUNC_PTR void (*test_func)(stringstream&, stringstream&)
void test(TEST_FUNC_PTR, const string& input, const string& expected)
{
    stringstream in_stream(input);
    stringstream out_stream;
    test_func(in_stream, out_stream);

    if(expected == out_stream.str())
    {
        cout << "PASS" << endl;
    }
    else
    {
        cout << "With input \"" << input << "\" expected output \"" << expected
             << "\", received \"" << out_stream.str() << "\"" << endl;
    }
}

int main()
{
    // To add a test case, duplicate one of the test lines below
    // modify input with the first string, and the expected output
    // in the second string.

    test(street_address, "The Number Family\n789 Donaknowy St.\nBig City, CA 92929", "789 Donaknowy St.");
    test(street_address, "The Banks\n13 Cherry Tree Lane\nLondon, CA 92003", "13 Cherry Tree Lane");
    test(coffee_sale_item, "Latte 30 3.4", "Latte total sales = $102.00");
    test(first_name_and_country, "Jane 345 One Fab Pl., USA", "Jane is from USA");
    test(first_name_and_country, "Jane 345555 One Fab Pl.           USA", "Jane is from USA");

    return 0;
}