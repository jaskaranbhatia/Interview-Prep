#include<bits/stdc++.h>
using namespace std;

/* Given a “2 x n” board and tiles of size “2 x 1”, 
count the number of ways to tile the given board using the 2 x 1 tiles. 
A tile can either be placed horizontally i.e., 
as a 1 x 2 tile or vertically i.e., as 2 x 1 tile.
*/

int totalWays(int n){
    if(n<1) return 0;
    if(n<4) return 1;
    if(n==4) return 2;
    return totalWays(n-1) + totalWays(n-4);
}

int main(){
    int n = 5;
    cout<<totalWays(5);
    return 0;
}
