/*


Author:Daniel Cooney
Date: 16/10/17
Last Edit:19/10/17

About: An example showing barriers


*/

#include "Semaphore.h"
#include <iostream>
#include <thread>
#include <mutex>


int count = 0;
int numberOfTimes = 2;

void taskOne(std::shared_ptr<Semaphore> mutex,std::shared_ptr<Semaphore> BarrierA, std::shared_ptr<Semaphore> BarrierB)
{
 
  mutex->Wait();
  std::cout <<"Mutex Wait" << std::endl;

  count++;
  std::cout <<"Thread:"<< count << std::endl;
 
 
  if(count == numberOfTimes)
   {
      std::cout <<"Both Threads are at the barrier" << std::endl;
      BarrierB ->Wait();
      BarrierA ->Signal();
   }
 
  mutex->Signal();
  std::cout <<"Mutex Signal " << std::endl;

  BarrierA -> Wait();
  BarrierA -> Signal();
 
  mutex ->Wait();

  count--;

  if(count == 0)
    {
      std::cout <<"Threads are finished" << std::endl;      
      BarrierA -> Wait();
      BarrierB ->Signal();
    }

   mutex->Signal();
   BarrierB -> Wait();
   BarrierB -> Signal();

}
int main(void)
{
  std::thread threadOne, threadTwo;
  std::shared_ptr<Semaphore> mutex( new Semaphore(1));
  std::shared_ptr<Semaphore> BarrierA( new Semaphore);
  std::shared_ptr<Semaphore> BarrierB( new Semaphore(1));
  

  threadOne = std::thread(taskOne,mutex,BarrierA,BarrierB);
  threadTwo = std::thread(taskOne,mutex,BarrierA,BarrierB);

  std::cout << "Launched from the main\n";
  threadOne.join();
  threadTwo.join();
  return 0;
}
