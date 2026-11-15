// In the following program, threads are used to run tasks. 
// Some parts of the code are left incomplete. 
// Your goal is to fill in these blanks to ensure that the threads execute as expected.

// Pay attention to how you need to initialize the threads and ensure they complete 
// properly using join and detach as instructed in the TODO comments.
#include <iostream>
#include <thread>
#include <string>

class Operation {
public:
    Operation(const std::string& name) : threadName(name) {}

    void operator()() const {
        std::cout << "Running " << threadName << std::endl;
    }

private:
    std::string threadName;
};

int main() {
    // TODO: Complete t1 and t2 thread initialization to run Operation objects with names "Find" and "Replace"
    std::thread t1(________);
    std::thread t2(________);
    std::thread t3([]() {
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        std::cout << "Lambda thread executing" << std::endl;
    });
    // TODO: Ensure t1 and t2 threads complete execution before the main thread
    t1.________();
    t2.________();
    // TODO: Ensure t3 thread runs independently of the main thread
    t3.________();

    std::cout << "End of main thread" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));

    return 0;
}


// Completed example attached below:
#include <iostream>
#include <thread>
#include <string>

class Operation {
public:
    Operation(const std::string& name) : threadName(name) {}

    void operator()() const {
        std::cout << "Running " << threadName << std::endl;
    }

private:
    std::string threadName;
};

int main() {
    // TODO: Complete t1 and t2 thread initialization to run Operation objects with names "Find" and "Replace"
    std::thread t1(Operation("Find"));
    std::thread t2(Operation("Replace"));
    std::thread t3([]() {
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        std::cout << "Lambda thread executing" << std::endl;
    });
    // TODO: Ensure t1 and t2 threads complete execution before the main thread
    t1.join();
    t2.join();
    // TODO: Ensure t3 thread runs independently of the main thread
    t3.detach();

    std::cout << "End of main thread" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));

    return 0;
}



