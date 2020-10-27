#include <iostream>
#include <stdarg.h>
int sum(int num,...){
	int sum=0;
	va_list valist;
	va_start(valist,num);
	for(int i=0;i < num;i++){
		sum += va_arg(valist,int);
	}
	va_end(valist);
	return sum;
}

int main(){
	std::cout << sum(2, 10000,2000) << "\n";
	std::cout << sum(3, 10000,2000,500) << "\n";
}
