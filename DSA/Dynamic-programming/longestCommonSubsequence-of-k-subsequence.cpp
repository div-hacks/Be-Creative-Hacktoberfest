//https://www.techiedelight.com/longest-common-subsequence-of-k-sequences/


//Longest common subsequence of k-sequences

// naive method : complexity-  O(3^(m+n+z))

// #include <iostream>
// #include <algorithm>
// #include <string>
// using namespace std;

// int max(int a, int b, int c) {
//     return max (max(a,b), c);
// }

// int lcslength(string x, string y, string z , int m , int n, int o) {

//     if (m == 0 || n == 0 || o ==0)
//         return 0;
    
//     if (x[m-1] == y[n-1] && y[n-1] == z[o-1])
//         return lcslength(x, y, z, m-1, n-1, o-1) +1 ;
    

//     return max(lcslength(x,y,z, m-1, n, o),
//                 lcslength(x,y,z, m, n-1 ,o),
//                 lcslength(x,y,z, m, n, o-1));
// }

// int main(void) {
//     string x = "abcbdab", y = "bdcaba", z = "badacb";

//     cout << "The length of the LCS is "<<
//     lcslength(x,y,z, x.length(), y.length(), z.length())
//     << endl;

//     return 0;
// }









//***************************************************************

// Since the LCS problem exhibits overlapping subproblems. Thus using dp


// TOP DOWN APPROACH.  
//  Complexity : O (m.n.o)  where m, n, o are length of the strings
// #include <iostream>
// #include <algorithm>
// #include <string>
// #include <unordered_map>
// using namespace std;

// int max(int a, int b, int c) {
//     return max(max(a,b), c);
// }


// int lcslength(string x, string y, string z, int m, int n, int o, auto &lookup) {

//     if (m == 0 || n == 0 || o == 0)
//         return 0;
    
//     string key = to_string(m) + "|" + to_string(n) + "|" + to_string(o);

//     if( lookup.find(key) == lookup.end()) {
//         if( x[m-1] == y[n-1] && y[n-1] == z[o-1])
//             lookup[key] = lcslength(x,y,z, m-1, n-1, o-1, lookup) + 1;
        
//         else 
//             lookup[key] = max(lcslength(x,y,z, m-1 ,n, o, lookup), lcslength(x,y,z, m, n-1, o, lookup), lcslength(x,y,z, m, n, o-1, lookup));
//     }

//     return lookup[key];
// }

// int main(void) {

//     string x = "abcbdab", y = "bdcaba", z = "badacb";

//     unordered_map<string, int> lookup;

//     cout << "The length of the LCS is " <<
//         lcslength(x,y,z, x.length(), y.length(), z. length(), lookup) << endl;

//     return 0;
// }












//***************************************************************
// BOTTOM UP APPROACH


#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <string>
#include <cstring>
using namespace std;

int max(int a, int b, int c) {
    return max(max(a,b), c);
}

int lcslength(string x, string y, string z) {
    int m = x.length(), n = y.length(), o = z.length();

    int lookup[m+1][n+1][o+1];

    memset(lookup, 0, sizeof lookup);

    for (int i = 1; i<=m; i++){
        for(int j = 1; j<=n; j++) {
            for(int k =1; k<= o; k++){
                if (x[i-1] == y[j-1] && y[j-1] == z[k-1]) {
                    lookup[i][j][k] = lookup[i-1][j-1][k-1] + 1;
                }
                else
                {
                    lookup[i][j][k] = max(lookup[i-1][j][k], lookup[i][j-1][k], lookup[i][j][k-1]);

                }
                
            }
        }
    }
    return lookup[m][n][o];
}


int main (void) {

    string x = "abcbdab", y = "bdcaba", z = "badacb";

    cout << "The length of the LCS is " << lcslength(x,y,z) << endl;

    return 0;
}