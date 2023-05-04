/*
Write the following functions in C that does the following:
	a)A non-recursive function lar2dig(n), where n is a positive integer, that finds the largest two-digit subsequence in n.
		For example, if n = 256723 then the largest two-digit subsequence is72.
	b)A recursive equivalent of the above called rec_lar2dig(...) which performs the same computation. 
		Define your own function arguments suitably.  
	c)A non-recursive function eval_f(x, n) where x is a floating point number between 0 and 1 and n is a positive integer. 
		The function computes and returns the value of the series: f(x) = 1 - 2x/1! + 3x2/2! - 4x3/3! + 5x4/4!-.... upton terms. 
		Print the interim sumand termvalues in each iteration of the loop. 
	d)A recursive equivalent for the above function called rec_eval_f(...). Define your own function arguments  suitably.
	e)Write a main program / function to do the following:
		i.Read a positive integer M and print it.
		ii.Read M positive integers. For each such integer p, print it. 
			Then call the functions of (a) and (b) to find and print the largest two-digit subsequence of each p.  
			Check if the non-recursive and recursive functions produce the same result. 
			Finally find and print the smallest among the largest two-digit sequences of all the numbers read. 
		iii.Read a number X between 0 and 1, and a positive integer N. Print them. Check if X lies between 0 and 1 and N is
			positive.
			Otherwise flag an input error and take bothinputs again. After correct inputs are received perform the next step.
		iv.Compute the function as given in parts (c) and (d) using X and N to find and print the result. 
		Check if the result from both non-recursive and recursive versions are the same.
*/
#include<stdio.h>
int lar2dig(int n){ // finds the largest two-digit subsequence in n, non-recursively
    int max=-1;
    while(n>0){
        if(n%100>=max){
            max=n%100;
        }
        n/=10;
    }
    return max;
}
int rec_lar2dig(int n,int max){ // finds the largest two-digit subsequence in n, recursively
    if(n<=10){
        return max;
    }
    if(n%100>=max){
        max=n%100;
    }
    rec_lar2dig(n/10,max);
}
double eval_f(double x,int n){ // The function computes and returns the value of the series, non-recursively
    int i;
    double sum=1,term=1;
    for(i=2;i<=n;i++){
        term = term * (-1)*((i*x)/((i-1)*(i-1)));
        sum=sum + term;
        printf("The interim sum value is %lf and the term value is %lf\n",sum,term);
    }
    return sum;
}
double rec_eval_f(double x,int n,double sum,double term,int i){
    if(i>n){
        return sum;
    }
    else{
    term = term * (-1)*((i*x)/((i-1)*(i-1)));
    sum = sum + term;
    printf("The interim sum value is %lf and the term value is %lf\n",sum,term);
    return rec_eval_f(x,n,sum,term,i+1);
    }
}
main(){
    int m,i,p,max,maxrec,n,small=100;
    double x,sum,sumrec;
    puts("Enter a positive integer which is the limit: \n"); //Reading a positive integer M and printing it
    scanf("%d",&m);
    printf("The positive integer given is %d\n",m);
    for(i=1;i<=m;i++){ // Reading M positive integers
        puts("Enter a positive integer : \n");
        scanf("%d",&p);
        printf("The positive integer given is %d\n",p);  //For each such integer p, printing it
        max=lar2dig(p); //calling the functions of (a) and (b) to find and print the largest two-digit subsequence of each p
        maxrec=rec_lar2dig(p,-1);
        printf("The largest two-digit sequence from (a) for %d is %d\n",p,max);
        printf("The largest two-digit sequence from (b) for %d is %d\n ",p,maxrec);
        if(max==maxrec){
            puts("The non-recursive and recursive functions produce the same result.");
        }
        if(max<small){
            small=max;
        }
    }
    printf("The smallest among the largest two-digit sequences of all the numbers read is %d\n",small);
    while(1){
        puts("Enter the value of x, which is between 0 and 1: \n");
        scanf("%lf",&x);
        printf("The value of x given is %lf\n",x);
        puts("Enter the value of N, which is a positive integer: \n");
        scanf("%d",&n);
        printf("The value of n given is %d\n",n);
        if(!(x<=1 && x>=0 && n>0)){
            printf("Input invalid ! Enter input again !!!\n");
            continue;
        }
        else
            break;
    }
    sum=eval_f(x,n);
    printf("The sum of the series by (c) for %lf is %lf\n",x,sum);
    sumrec=rec_eval_f(x,n,1.0,1.0,2);
    printf("The sum of the series by (d) for %lf is %lf\n",x,sumrec);
}
