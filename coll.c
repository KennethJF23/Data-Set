#include <stdio.h>
#include <conio.h>
int st[10];
int top=-1;
int pop();
void push();

int main(){
    int val,n,i;
    int arr[10];
    printf("ENTER THE NUMBER OF ELEMENT IN ARRAY\n");
    scanf("%d",&n);
    printf("ENTER THE ELEMENTS OF ARRAY:\n");
    for( i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    for(i=0;i<n;i++){
        push(arr[i]);
    }
    for(i=0;i<n;i++){
        val=pop();
        arr[i]=val;
    }
    printf("THE REVERSED ARRAY IS\n");
    for(i=0;i<n;i++){
        printf("%d",arr[i]);
    }
    return 0;
}

int pop(){
    return(st[top--]);
}

void push(int val){
    st[top++]=val;
}