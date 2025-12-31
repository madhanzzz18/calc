#include<stdio.h>
int addd(int a,int b);

int main(){
	int a,b,c;
	printf("add two numbers ");
	scanf("%d %d",&a,&b);
	c=addd(a,b);
	printf("sum = %d",c);	
	return 0;
}
int addd(int a,int b){
	return a+b;
}

