// Now, let's bring it all together in this challenge where you will write a complete C++ program to manage thread operations.

// Create a TaskExecutor class and construct three threads: two using this class and one with a lambda.

// Use join() for the first two threads and detach() for the lambda. Conclude by printing "Execution Complete" after managing all the threads.
#include <iostream>
#include <thread>
#include <string>

// TODO: Define a class named TaskExecutor
//       - This class should have a constructor that accepts a string (task name)
//       - Implement an operator() that prints "Executing <task name>"

int main() {
    // TODO: Create a thread t1 using TaskExecutor with the name "Task-1"
    // TODO: Create a thread t2 using TaskExecutor with the name "Task-2"
    // TODO: Create a thread t3 using a lambda function that pauses for 1 second and prints "Lambda executing"

    // TODO: Use join() on t1 to wait for its completion
    // TODO: Use join() on t2 to wait for its completion
    // TODO: Use detach() on t3 to let it run independently

    // TODO: Print "Execution Complete" after ensuring all threads have been managed
    // TODO: Pause the main thread for 1 second

    return 0;
}

// Completed example attached below:

#include <iostream>
#include <thread>
#include <string>

// TODO: Define a class named TaskExecutor
//       - This class should have a constructor that accepts a string (task name)
//       - Implement an operator() that prints "Executing <task name>"
class TaskExecutor
{
public: 
    TaskExecutor(std::string name): taskName(name) {}
    
    void operator()()const
    {
      std::cout << "Executing " << taskName << std::endl;
    }
    
private:
std::string taskName;
    
};

int main() {
    // TODO: Create a thread t1 using TaskExecutor with the name "Task-1"
    std::thread t1(TaskExecutor("Task-1")); 
    // TODO: Create a thread t2 using TaskExecutor with the name "Task-2"
    std::thread t2(TaskExecutor("Task-2"));
    // TODO: Create a thread t3 using a lambda function that pauses for 1 second and prints "Lambda executing"
    std::thread t3([](){
        std::this_thread::sleep_for(std::chrono::milliseconds(1000)); // 1 sec sleep
        std::cout << "Lambda thread executing" << std::endl;
    });

    // TODO: Use join() on t1 to wait for its completion
    t1.join();
    // TODO: Use join() on t2 to wait for its completion
    t2.join();
    // TODO: Use detach() on t3 to let it run independently
    t3.detach();

    // TODO: Print "Execution Complete" after ensuring all threads have been managed
    std::cout << "Execution Complete" << std::endl;
    // TODO: Pause the main thread for 1 second
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));

    return 0;
}