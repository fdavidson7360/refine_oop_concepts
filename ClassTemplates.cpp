//===== Class Template Ex
#include <iostream>
using namespace std;

template <class T>
class Pair {
    private:
        T first, second;
    public:
        Pair (T a, T b):
        first(a), second(b) { }
        T bigger();
};

template <class T>
T Pair<T>::bigger() {
    return (first>second ? first : second);
}

int main()
{
    Pair <int> obj(11, 22);
    cout << obj.bigger() <<endl;
    
    Pair <double> obj2(12.5, 75.2);
    cout << obj2.bigger();

    return 0;
}
// ===== Class Template Ex w/ Queue project
#include <iostream>
using namespace std;

//change the class to a template
template <class T>
class Queue 
{
	private:
	    T *arr;
        int count;
    public:
    	Queue(int size) {
    	    arr = new T[size];
    	    count = 0;
    	}
    	void add(T elem) {
    	    arr[count] = elem;
    	    count++;
    	}
    	void get(int index) {
    	    cout << arr[index]<<endl;
    	}
};

int main()
{
	Queue<string> q(4);
	q.add("James");
	q.add("Andy");
	q.add("Amy");
	q.get(2);
	
	Queue <int> n(2);
	n.add(42);
	n.add(33);
	n.get(1);
	
	return 0;
}