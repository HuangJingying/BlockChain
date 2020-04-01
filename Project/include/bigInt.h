#ifndef BIG_INT_H
#define BIG_INT_H
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

class BigInt // store in vector, easy to operate
{
public:
    void check(); //carry bit
    BigInt()
    {
        number.push_back(0);
        check();
    }
    void SetNumber(string s);        // use a string to adjust the number
    bool GetNumber(vector<int> &vec) // use another vector to contain the number
    {
        vec.assign(number.begin(), number.end());
        reverse(vec.begin(), vec.end());
        return true;
    }
    friend istream &operator>>(istream &input, BigInt &bigInt);
    friend ostream &operator<<(ostream &output, BigInt &bigInt);
    // overload operators
    bool operator!=(BigInt &bigInt);
    bool operator==(BigInt &bigInt);
    bool operator<(BigInt &bigInt);
    bool operator>(BigInt &bigInt);
    bool operator<=(BigInt &bigInt);
    bool operator>=(BigInt &bigInt);
    void operator+=(BigInt &bigInt);
    void operator-=(BigInt &bigInt);
    void operator*=(BigInt &bigInt);
    void operator/=(BigInt &bigInt);
    BigInt operator+(BigInt &bigInt);
    BigInt operator-(BigInt &bigInt);
    BigInt operator*(BigInt &bigInt);
    BigInt operator/(BigInt &bigInt);
    BigInt operator%(BigInt &bigInt);
    BigInt DivWithMod(BigInt &bigInt);

private:
    vector<int> number; // stored in inverted order
};

#endif