//Author:Daniel Cooney

#include "Semaphore.h"
#include <iostream>
#include <thread>

void taskOne(std::shared_ptr<Semaphore> sem1, std::shared_ptr<Semaphore> sem2)
{
  std::cout << "Thread A arrived" << std::endl;
  sem1->Signal();
  std::cout << "Thread A is in wait" << std::endl;
  sem2->Wait();
  std::cout << "Thread A Completed" << std::endl;

}
void taskTwo(std::shared_ptr<Semaphore> sem1, std::shared_ptr<Semaphore> sem2)
{
  std::cout << "Thread B arrived " << std::endl;
  sem2->Signal();
  std::cout << "Thread B is in wait" << std::endl;
  sem1->Wait();
  std::cout << "Thread B Completed"<< std::endl;
}

int main(void)
{
  std::thread threadOne, threadTwo;
  
  std::shared_ptr<Semaphore> sem1( new Semaphore);
  
  std::shared_ptr<Semaphore> sem2( new Semaphore);
  
  /**< Launch the threads  */
  threadOne=std::thread(taskTwo,sem1,sem2);
  threadTwo=std::thread(taskOne,sem1,sem2);
  
  std::cout << "Launched from the main\n";
  threadOne.join();
  threadTwo.join();
  return 0;
}
