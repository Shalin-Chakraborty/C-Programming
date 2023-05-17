/* 1. Read in a positive integer n (0 < n <= 20) and print it. Create a new line.
2. Read in n positive integers and store them in an array called A. Print them in a single line followed by 
commas. Then create a new line. 
3. In a new second array called B store only one copy of each number of A, removing duplicates. Print the 
numbers stored in B.
4. Find the number(s) of A having the highest frequency and print it along with the frequency. If there are ties, 
print all of them having the same highest frequency.
5. Read a positive integer m. Print it.
6. Now do the following:
a) Check if m is present in B. If so, print “Yes Present”. Otherwise print “Not present”
b) Find and print all numbers in B which are less than m. If there are none, print “No such less number”
c) Find and print all prime numbers in B which when added with m becomes non-prime. If there is no 
such, then print “No such prime number in B” */
#include<stdio.h>
int main(){
	int n,a[20],i,b[20],j,m=0,c[20]={0},max,maxf=0,f=0,q=0,s=0,k;
	puts("Enter a positive integer: ");
	scanf("%d",&n);
	puts("Enter array elements: ");
	for(i=0;i<n;i++){
		scanf("%d ",&a[i]);
	}
	for(i=0;i<n;i++){
		printf("%d ",a[i]);
	}
	printf("\n");
	for(i=0;i<n;i++){
		for(j=0;j<q;j++){
			if(a[i]==b[j]){
				break;
			}
		}
		if(j==q){
			b[q++]=a[i];
		}
	}
	for(i=0;i<q;i++){
		f=0;
		for(j=0;j<n;j++){
			if(b[i]==a[j]){
				c[i]++;
			}
		}
		if(c[i]>maxf){
			maxf=c[i];
		}
	}
	for(i=0;i<q;i++){
		if(c[i]==maxf){
			printf("%d - %d\n",b[i],c[i]);
		}
	}
	puts("Enter a positive integer: ");
	scanf("%d",&m);
	for(i=0;i<q;i++){
		if(b[i]==m){
    		break;
		}
	}
	if(i<q){
		printf("Yes, %d is present\n",m);
	}
	else{
		printf("%d is not present\n",m);
	}
	printf("Numbers less than %d\n",m);
	for(i=0;i<q;i++){
		if(b[i]<m){
			printf("%d ",b[i]);
			s++;
		}
	}
	if(s==0){
		printf("No number less than %d\n",m);
	}
	s=0;
	puts("\nThe prime numbers in B which when added with m becomes non-prime\n");
	for(i=0;i<q;i++){
		for(j=2;j<=b[i]/2;j++){
			if(b[i]%j==0){
				break;
			}
		}
		if(j>b[i]/2 && b[i]>=2){
			for(k=2;k<=(b[i]+m)/2;k++){
				if((b[i]+m)%k==0){
					break;
				}
			}
		if(k<=(b[i]+m)/2){
			printf("%d ",b[i]);
			s++;
			}
		}
	}
	if(s==0){
		printf("No such number");
	}
}

