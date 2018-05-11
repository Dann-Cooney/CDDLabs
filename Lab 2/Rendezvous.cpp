/*! 
    \author Daniel Cooney
    \date 20/10/2017
    \file Rendezvous.cpp
    \brief Rendezvous using semaphores
    \licence GNU General Public Licence
!
*/

#include "Semaphore.h"
#include <iostream>
#include <thread>


/*! \fn void taskOne()
    \brief This function will be called by threadA
    taskOne prints out a statement, signals sem1 and waits sem2. 
    It will print out one more statement when it finishes.
 */


void taskOne(std::shared_ptr<Semaphore> sem1, std::shared_ptr<Semaphore> sem2)
{
  std::cout << "Thread A arrived" << std::endl;
  sem1->Signal();
  std::cout << "Thread A is in wait" << std::endl;
  sem2->Wait();
  std::cout << "Thread A Completed" << std::endl;

}

/*! \fn void taskTwo()
    \brief This function will be called by threadB
    taskOne prints out a statement, waits sem1 and signals sem2. 
    It will print out one more statement when it finishes.
 */
void taskTwo(std::shared_ptr<Semaphore> sem1, std::shared_ptr<Semaphore> sem2)
{
  std::cout << "Thread B arrived " << std::endl;
  sem2->Signal();
  std::cout << "Thread B is in wait" << std::endl;
  sem1->Wait();
  std::cout << "Thread B Completed"<< std::endl;
}

 /*!
    Creating two threads and assigns them to  functions, 
    and a semaphore instance.
*/
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
