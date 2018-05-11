/*! 
    
    \author Daniel Cooney
    \date 17/10/2017
    \file Semaphore.cpp
    \brief The Semaphore class
    \licence GNU General Public License
   
!
*/

#include "Semaphore.h"
#include <iostream>
#include <thread>

/*! 
This will print first. Once ran,  it will signal the semaphore to allow others to run.
*/ 


void taskOne(std::shared_ptr<Semaphore> theSemaphore){
  std::cout <<"I ";
  std::cout << "must ";
  std::cout << "print ";
  std::cout << "first"<<std::endl;
  theSemaphore->Signal();
}

/*! 
This will  print second. It is blocked first, and it can only finish once taskOne completes.
*/ 
void taskTwo(std::shared_ptr<Semaphore> theSemaphore){
  /*! This will not run taskOne signals it */
  theSemaphore->Wait();
  std::cout <<"This ";
  std::cout << "will ";
  std::cout << "appear ";
  std::cout << "second"<<std::endl;
}
/*! 
This will print first. Once ran,  it will signal the semaphore to allow others to run.
*/ 
int main(void){
  std::thread threadOne, threadTwo;
  std::shared_ptr<Semaphore> sem( new Semaphore);
  /**< Launch the threads  */
  threadOne=std::thread(taskTwo,sem);
  threadTwo=std::thread(taskOne,sem);
  std::cout << "Launched from the main\n";
  threadOne.join();
  threadTwo.join();
  return 0;
}
