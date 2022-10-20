#include <bits/stdc++.h>
using namespace std;

int max(int a, int b)
{
    return (a > b) ? a : b;
}
 

int recursive(int eggs, int floors)
{
    // If there are no floors,
    // then no trials needed.
    // OR if there is one floor,
    // one trial needed.
    if (floors == 1)
        return floors-1;
 
    // We need k trials for one
    // egg and k floors
    if (eggs == 1)
        return floors-1;
 
    int min = INT_MAX, x, res;
 
    // Consider all droppings from
    // 1st floor to kth floor and
    // return the minimum of these
    // values plus 1.
    for (x = 1; x <= floors; x++) {
        res = max(
            recursive(eggs - 1, x - 1),
            recursive(eggs, floors - x));
        if (res < min)
            min = res;
    }
 
    return min + 1;
}
int main(){
#ifndef GRADESCOPE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int eggs, floors;
    string input;
    cin >> input;

    floors = stoi(input.substr(0, input.find(",")));
    input.erase(0, input.find(",") + 1);
    eggs = stoi(input);

    cout << recursive(eggs, floors) << endl;
}
