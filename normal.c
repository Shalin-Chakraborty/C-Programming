/*Let the normalized representation of any non-zero real number be (m, e), where the range of the absolute
value of the mantissa m is 1 <= |m| < 10 and the exponent e is an integer power of 10. Thus, the
nor~alized representation of 432.27 is (4.3227, 2) and that of -0.011537 is ( -1.1537, -2).
The following recursive C function is meant to take as parameters pointers to the mantissa u and
exponent e of a floating point number u x 10^e and transforms the number to the normalized form.
It is invoked first time with e = 0 and a non-zero mantissa u.*/
#include<stdio.h>
void normalize(float *u,int *e){
	int m=*u;
	if(m>=1 && m<10){
		return;
	}
	if(m==0){
		*u=*u*10;
		*e=*e-1;
		
	}else{
		*u=*u/10;
		*e=*e+1;;
	}
	normalize(u,e);
}
int main(){
	float u;
	int e=0;
	puts("Enter a non-zero real number: ");
	scanf("%f",&u);
	normalize(&u,&e);
	printf("The normalized representation of the given non-zero real number is (%f,%d)",u,e);
}
