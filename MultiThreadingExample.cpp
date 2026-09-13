// Multi threading is when multiple threads are spawned by a process to do different tasks, at the same time. 
// This is a very powerful technique that allows you to write efficient programs that 
// can do multiple things at once. In this example, we will create a simple multi-threaded
//  program that demonstrates how to use threads in C++.  


// Multi-processing is a technique that allows you to run multiple processes simultaneously.

#include <iostream>
#include <thread>

void hello() 
{
    std::cout << "Hello from thread!" << std::endl;
}

void goodbye(std::string message) 
{
    std::cout << message << std::endl;
}

int main() 
{
    std::thread t1(hello); // Create a thread that runs the hello function
    std::thread t2(goodbye, "Goodbye from thread!"); // Create a thread that runs the goodbye function

    t1.join(); // Wait for the first thread to finish
    t2.join(); // Wait for the second thread to finish

    return 0;
}