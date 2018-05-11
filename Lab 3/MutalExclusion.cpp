/*! 
    \author Daniel Cooney
    \date 28/1/2018
    \file Semaphore.h
    \brief The Semaphore class
    \licence GNU General Public Licence
!
*/

#include "Semaphore.h"
#include <iostream>
#include <thread>
#include <mutex>

int count = 0;
/*! 
brief: Allows 2 in, preventing access to taskTwo until finished
parameters: theSemaphore, count
*/
void taskOne(std::shared_ptr<Semaphore> mutex)
{
 /*! Wait only allowing one task in at a time */
 mutex ->Wait();
 count = count + 1;
 std::cout << count << std::endl;
 mutex ->Signal();
}


int main(void)
{
  std::thread threadOne, threadTwo;
  std::shared_ptr<Semaphore> mutex( new Semaphore);
  
  /**< Launch the threads  */
  mutex ->Signal();

  threadOne=std::thread(taskOne, mutex);
  threadTwo=std::thread(taskOne, mutex);
  
  std::cout << "Launched from the main\n";
  threadOne.join();
  threadTwo.join();
  return 0;
}
