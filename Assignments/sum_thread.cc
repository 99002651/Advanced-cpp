#include<iostream>
#include<thread>

 

int size=5;
int arr[1000];
int thread = 0;
int sum_arr[5];

 

void sum()
{
int i,total=0;
std:: cout << "Thread entered - " << std::this_thread:: get_id()<< std::endl;
int part = thread++;
int start = part*size/5;
int end = (part+1)*size/5;
   for(i=start; i<end; i++)
   {
     total = total + arr[i];
   }
   sum_arr[part] = total;
   
}

 

int main()
{ 
 for(int i=0; i<1000 ; i++)
 {
     arr[i] = rand()%10; // generates number 0-99
 }

 

std::thread t1(sum);
std::thread t2(sum);
std::thread t3(sum);
std::thread t4(sum);
std::thread t5(sum);

 

t1.join();
t2.join();
t3.join();
t4.join();
t5.join();

 

int final_sum;
for(int j=0; j<5; j++)
{
  final_sum = final_sum + sum_arr[j];
}

 

 std::cout << "Sum is " << final_sum << std::endl;
}
