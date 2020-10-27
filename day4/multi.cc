#include <thread>
#include <iostream>
#include <chrono>
#include <functional>
#include <mutex>
std::chrono::milliseconds delay(1000);
int val = 10;
std::mutex m1;
std::mutex m2;
constexpr int max = 10;
void print_range(int start,int end) {
  std::cout << "printing range from:" << start << "to:" << end << "\n";
  /*for(int i=start;i<=end;i++) {
   std::cout << i << "\n";
     val++;
    std::this_thread::sleep_for(delay);
  }*/
  for(int i= 0;i < max;i++){
  	std::this_thread::sleep_for(delay);
  	val++;
  }
  m1.unlock();//non critical
}
void fasak(){
	m2.lock();
	for(int i  = 0;i <max;i++){
		val--;
	}
	m2.unlock();
}
int main() {
  std::cout << "Main -- Welcome\n";
  int start,end,i;
  int n=10;
  std::thread tarr[n];//default ctor                 
  
  for(int i=0;i<n;i++) {
    start = i*2+1;
    end = start+5;
    tarr[i] = std::thread(print_range,start,end);
  }
  for(i=0;i<n;i++){
    tarr[i].join();
  }
  std::thread(fasak);
  std::cout <<val <<"\n";
  return 0;

}

/* std::thread t1 default ,no actibe thraes /exectution
t1 = std::thread(compute)   //now active when anonymous objects rae cretaed
*/
//to do :create  a thraed with using pthraed ApI's
