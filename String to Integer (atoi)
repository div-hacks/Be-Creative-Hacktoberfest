#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        int i = 0, sign = 1;
        long res = 0; // Using long to handle overflow cases

        // Trim leading spaces
        while (i < s.size() && s[i] == ' ') i++;
        if (i == s.size()) return 0;

        // Check for sign
        if (s[i] == '-') { sign = -1; i++; }
        else if (s[i] == '+') i++;

        // Process numerical characters
        while (i < s.size() && isdigit(s[i])) {
            res = res * 10 + (s[i] - '0');

            // Handle overflow
            if (sign * res > INT_MAX) return INT_MAX;
            if (sign * res < INT_MIN) return INT_MIN;

            i++;
        }

        return (int)(sign * res);
    }
};
