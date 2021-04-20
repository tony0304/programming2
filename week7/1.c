#include <stdio.h>

#define ROW 2
#define COL 4
int main() {
int i, j;
int arr[ROW][COL];
for(i=0; i<ROW; i++){
for(j=0; j<COL; j++){
arr[i][j] = i*j;
}
}
for(i=0; i<ROW; i++){
for(j=0; j<COL; j++) {
printf("%d*%d=%d\t", i, j, arr[i][j]);
}
printf("\n");
}
return 0;
}