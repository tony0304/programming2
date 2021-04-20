#include <stdio.h>
#include <string.h>
#include <math.h>
int ans[99][2];
int count=0;
void swap(char *x, char *y) {
    char tmp = *x;
    *x = *y;
    *y = tmp;
}

void reverse(char *first, char *last) {
    --last;
    while (first < last) {
        swap(first, last);
        ++first;
        --last;
    }
}

void bubble_sort(int arr[][2], int n) {
	int i,j;
	int temp[2];
	for (i = 0; i < n; ++i) {
		for (j = 0; j < i; ++j) {
		  if (ans[j][0] > ans[i][0]) {
		    temp[0] = ans[j][0];
		    temp[1] = ans[j][1];
		    ans[j][0] = ans[i][0];
		    ans[j][1] = ans[i][1];
		    ans[i][0] = temp[0];
		    ans[i][1] = temp[1];
		  }
		  else if(ans[j][0] == ans[i][0] && ans[j][1] >ans[i][1])
		  {
		  	temp[0] = ans[j][0];
		    temp[1] = ans[j][1];
		    ans[j][0] = ans[i][0];
		    ans[j][1] = ans[i][1];
		    ans[i][0] = temp[0];
		    ans[i][1] = temp[1];
		  }
		}
	}
}

char* P(int size, char arr[], char arr2[])
{
	if(arr[0]=='0' || (int)strlen(arr)==0){
		return arr;
	}
	else if (arr[0] == '1'){
		if(size==1) {
			int x=0, y=0, i;
			reverse(&arr2[0],&arr2[strlen(arr2)]);
			for(i =0; i<(int)strlen(arr2)-1;i++){
				if(arr2[i]=='1'){
					x+=0*pow(2,i);
					y+=0*pow(2,i);
				}
				if(arr2[i]=='2'){
					x+=1*pow(2,i);
					y+=0*pow(2,i);
				}
				if(arr2[i]=='3'){
					x+=0*pow(2,i);
					y+=1*pow(2,i);
				}
				if(arr2[i]=='4'){
					x+=1*pow(2,i);
					y+=1*pow(2,i);
				}
			}
			ans[count][0]=y;
			ans[count++][1]=x;
			return arr;
		}
		else if(size>1){
			reverse(&arr[0],&arr[strlen(arr)]);
			strcat(arr,"1111");
			reverse(&arr[0],&arr[strlen(arr)]);
			char temp[99];
			strcpy(temp,arr2);
			strcat(temp,"1");
			arr = P(size/2,arr+1,temp);
			strcpy(temp,arr2);
			strcat(temp,"2");
			arr = P(size/2,arr+1,temp);
			strcpy(temp,arr2);
			strcat(temp,"3");
			arr = P(size/2,arr+1,temp);
			strcpy(temp,arr2);
			strcat(temp,"4");
			arr = P(size/2,arr+1,temp);
			return arr;
		}
	}
	else {
		char temp[99];
		strcpy(temp,arr2);
		strcat(temp,"1");
		arr = P(size/2,arr+1,temp);
		strcpy(temp,arr2);
		strcat(temp,"2");
		arr = P(size/2,arr+1,temp);
		strcpy(temp,arr2);
		strcat(temp,"3");
		arr = P(size/2,arr+1,temp);
		strcpy(temp,arr2);
		strcat(temp,"4");
		arr = P(size/2,arr+1,temp);
		return arr;
	}
} 
void main(){
	char list[99],arr[99]={'1'};
	char test[2]={'a','b'};
	int size;
	scanf("%s\n",list);	
	scanf("%d",&size);
    P(size,list,arr);
    int i;
    bubble_sort(ans, count);
    for (i=0;i<count;i++)
    {
    	printf("%d,%d\n",ans[i][0],ans[i][1]);
	}
	if(count==0){
		printf("all white\n");
	}
//    for (i=0;i<count;i++)
//    {
//    	printf("%d,%d\n",ans[i][0],ans[i][1]);
//	}
    
}
