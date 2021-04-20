#include <stdio.h>

#define ROW 4
#define COL 3
void search(int arr[][COL], int p[]){
int i, j;
p[0] = p[1]=arr[0][0];
for(i=0; i<ROW; i++){
for(j=0; j<COL; j++){
if(p[0]<arr[i][j]) p[0] = arr[i][j];
if(p[1]>arr[i][j]) p[1] = arr[i][j];
}
}
}
void show(int arr[][COL]) {
int i, j;
for(i=0; i<ROW; i++){
for(j=0; j<COL; j++)
printf("%02d", arr[i][j]);
printf("\n");
}
}

int main() {
int a[ROW][COL]= {{1, 2, 3}, {4, 5, 6},
{7, 8, 9}, {5, 4, 3}};
int i, j, b[2];
show(a);
search(a, b);
printf("max = %d, min = %d\n", b[0], b[1]);
}