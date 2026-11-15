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

// Next example of multiple threading
// Allow two threads to run concurrently, each thread will print a message to the console.
// Then the main thread will wait for both threads to finish before exiting.

#include <iostream>
#include <thread>
#include <string>

class HeroRunner {
public:
    HeroRunner(const std::string& heroName) : heroName(heroName) {}

    void operator()() const {
        std::this_thread::sleep_for(std::chrono::milliseconds(800));
        std::cout << "Hero " << heroName << " activated" << std::endl;
    }

private:
    std::string heroName;
};

int main() {
    std::thread t1(HeroRunner("Hero-A"));
    std::thread t2(HeroRunner("Hero-B"));

    t1.join();
    t2.join();

    std::cout << "Operation Complete" << std::endl;

    return 0;
}