#include <thread>
#include <iostream>
#include <chrono>
#include <functional>
std::chrono::milliseconds delay(1000);
int val = 10;
constexpr int max = 10;
void compute(std::string label) {​​​​​​​
	  std::cout << "Thread--" << label << "\n";
	  for(int i=1;i<=max;i++) {​​​​​​​
		  std::cout << label << "--" << i << "\n";
		  //std::this_thread::sleep_for(delay);
			val++;
	  }​​​​​​​
}​​​​​​​
void fasak(){
for(int i  = 0;i <5;i++){
	val--;
}
}

int main(){
	std::thread t1(std::bind(compute, "A"));
  //std::thread t2(std::bind(compute, "B"));
  std::thread t2(fasak);                 //also works
  std::thread t3([]() {
    compute("C");
  });
	
	t1.join();
	t2.join();
	t3.join();
	std::cout <<"faskkk";
}


/*[10:33] Rajesh Sola
    std::chrono::milliseconds delay(1000);
​[10:33] Rajesh Sola
    std::this_thread::sleep_for(delay);
*/
