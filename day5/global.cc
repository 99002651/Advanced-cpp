#include <iostream>
#include <thread>
//int result;
void sumarr(int *arr, int len) {
  int sum=0,i;
  for(i=0;i<len;i++)
    sum+=arr[i];
  result=sum;

}

 /*
int main(){
int arr[10];
//fill with random values
std::thread t1(sumarr, arr, 10);
t1.join();
  std::cout <<result;
//print the result
return 0;
}*/



int main(){
int arr[10];
//fill with random values
std::future<int> result;
result = std::async(sumarr,arr,10);
std::cout <<reslt.get();
//get will do lke thread join but also it 

 // std::cout <<result;
//print the result
return 0;
}

