#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
#include<cmath>
using namespace std;

// Convert string from given base to decimal
long long toDecimal(const string &s, int base) {
    long long num = 0;
    for (char v : s) {
        int digit;
        if (isdigit(v)) digit = v - '0';
        else digit = 10 + (tolower(v) - 'a'); // handle a,b,c... in bases > 10
        num = num * base + digit;
    }
    return num;
}

// Lagrange interpolation to find f(0)
long long solve(const vector<pair<long long,long long>> &pairs, int k) {
    long double res = 0.0;
    for (int i = 0; i < k; i++) {
        long double xi = pairs[i].first;
        long double yi = pairs[i].second;
        long double t = yi;
        for (int j = 0; j < k; j++) {
            if (i != j) {
                long double xj = pairs[j].first;
                t *= (0 - xj) / (xi - xj);  // evaluating at x=0
            }
        }
        res += t;
    }
    return llround(res); // round to nearest integer
}
int main(){
    {   // number of pairs 4
        int k = 3;
        vector<pair<long long,long long>> points;
        points.push_back({1, toDecimal("4", 10)});
        points.push_back({2, toDecimal("111", 2)});
        points.push_back({3, toDecimal("12", 10)});
        points.push_back({6, toDecimal("213", 4)});

        // first k points
        vector<pair<long long,long long>> chosen(points.begin(), points.begin()+k);
        long long secret = solve(chosen, k);

        cout << "Test Case 1: Secret (P(0)) = " << secret << endl;
    }

    // second Test case
    {   // no. of pairs = 10
        int k = 7;
        vector<pair<long long,long long>> points;
        points.push_back({1, toDecimal("13444211440455345511", 6)});
        points.push_back({2, toDecimal("aed7015a346d635", 15)});
        points.push_back({3, toDecimal("6aeeb69631c227c", 15)});
        points.push_back({4, toDecimal("e1b5e05623d881f", 16)});
        points.push_back({5, toDecimal("316034514573652620673", 8)});
        points.push_back({6, toDecimal("2122212201122002221120200210011020220200", 3)});
        points.push_back({7, toDecimal("20120221122211000100210021102001201112121", 3)});
        points.push_back({8, toDecimal("20220554335330240002224253", 6)});
        points.push_back({9, toDecimal("45153788322a1255483", 12)});
        points.push_back({10, toDecimal("1101613130313526312514143", 7)});

        
        sort(points.begin(), points.end());

        // first k points
        vector<pair<long long,long long>> chosen(points.begin(), points.begin()+k);
        long long secret = solve(chosen, k);

        cout << "Test Case 2: Secret (P(0)) = " << secret << endl;
    }

}
