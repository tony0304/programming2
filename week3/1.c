#include <stdio.h>

int Sum(int n){
    printf("%d", n);
    if (n%2 == 0) n = n-1;
    if (n == 1 ){
        return 1;
    }
    else return n + Sum(n-2);
}

 int main(){
    int ans;
    ans = Sum(8);
    printf("%d", ans);
    return 0;
 }