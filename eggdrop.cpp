#include <bits/stdc++.h>
using namespace std;

int recursive(int eggs, int floors)
{
    if(floors == 0){
        return 0;
    }
    // if one floor then that is the critical one
    // so no trals needed
    if (floors == 1)
        return floors-1;
    
    // if floors number of floors are there
    // n-1 trials are needed as one egg
    // is dropped from each floor in the worst case
    // and the last one is the critical one for sure
    if (eggs == 1)
        return floors-1;
 
    int min_tries = INT_MAX, x, res;
 
    // Consider all droppings from
    // 1st floor to xth floor and
    // return the minimum of these
    // values plus 1.
    for (x = 1; x <= floors; x++) {
        min_tries = 
        min(min_tries, max(recursive(eggs - 1, x - 1), recursive(eggs, floors - x)));
    }
 
    return min_tries + 1;
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

    cout << recursive(eggs, floors);
}
