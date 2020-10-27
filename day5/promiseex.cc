#include <iostream>
#include <future>
#include <thread>
std::promise<int> parr[5];

void compute() {
int len = 10;
  for(int i=0;i<len;i++){
    std::cout << "Hello.." << i << "\n";
	if(i%5 == 0)	parr[i/5].set_value(i);
  }
}

 

int main() {
  int arr[10];
  std::thread t1(compute);
  
for (int i=0;i<5;i++){
	//std::cout << parr[i].get_future().get();
	std::cout << parr[i].get_future().get() << "\n";
    /*std::cout << result.get() << "\n";      link with set_value,.get will  wait for set     get capture promised value.*/
}
  t1.join();
  return 0;
}

