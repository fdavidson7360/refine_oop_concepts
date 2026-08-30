#include <iostream>
using namespace std;

class Engine {
    public:
        Engine(int p): power(p) {};
        void start() {
            cout <<"Engine ON ("<<power<<" horsepower)";
        }
    private:
        int power;
};
class Car {
    public:
        Car(Engine x, string c, int y): e(x), color(c), year(y) {};
        void start() {
            cout <<"Starting"<<endl;
            //your code goes here
            e.start();
            
        }
    private:
        Engine e;
        string color;
        int year;
};

int main() {
    int power;
    string color;
    int year;
    cin >> power >> color >> year;
    
    Engine e(power);
    //your code goes here
    Car carObj(e, color, year);
    carObj.start();

}


//=== Friend function example
#include <iostream>
using namespace std;

class Point {
    public:
        Point(int a, int b): x(a), y(b) {};
        void print() {
            cout << x << ", " << y;
        }

        friend void shift(Point &p, int step);
        
    private:
        int x;
        int y;
    
    
};
void shift(Point &p, int step) {
    p.x += step;
    p.y += step;
}

int main() {
    int x, y;
    cin>>x>>y;
    Point p(x, y);

    int step;
    cin>>step;
    shift(p, step);
    
    p.print();
}


//=== Overloading an operator example
#include <iostream>
using namespace std;

class MyClass {
    public:
        int var;
        MyClass() { }
        MyClass(int a)
        : var(a) { }

        MyClass operator+(MyClass &obj) {
            MyClass res;
            cout << "this->var: " << this->var << endl;
            cout << "obj.var: " << obj.var << endl;
            res.var= this->var+obj.var;
            return res; 
        }
};

int main() {
    MyClass obj1(12); // obj 1 --> sets the member var because it is created first??
    MyClass obj2(55);  // obj 2 will be the reference value passed into the overloaded op
    MyClass res = obj1+obj2;

    cout << res.var;
}

// Overloading the + operator example 2
#include <iostream>
using namespace std;

class Account {
    private:
        int balance=0;
        int interest=0;
    public:
        Account() {}
        Account(int a): balance(a) 
        {
            interest += balance/10;
        }
        int getTotal() {
            return balance+interest;
        }
        //your code goes here
        Account operator+(Account &acctObj)
        {
            Account result;
            result = this->balance + acctObj.balance;
            return result;
        }
        

};

int main() {
    int n1, n2;
    cin >> n1 >> n2;
    Account a(n1);
    Account b(n2);
    Account res = a+b;

    cout << res.getTotal();
}


// Complete example of Overloading the + operator

//Your Queue class is up and working in a customer service company. 
// The company opens up a new branch and asks you to make another version of the Queue for them. 
// The only difference is the way the Queue is displayed: each number on a new line.
// You decide to create a new class called Queue2, which is derived from the Queue class and overrides the print() method, 
// outputting each element of the queue on a new line.
#include <iostream>
using namespace std; 

class Queue { 
	int size; 
	int* queue; 
	
	public:
	Queue() { 
		size = 0;
		queue = new int[100];
	}
	void add(int data) { 
		queue[size] = data; 
		size++;
	}
	void remove() { 
		if (size == 0) { 
			cout << "Queue is empty"<<endl; 
			return; 
		} 
		else { 
			for (int i = 0; i < size - 1; i++) { 
				queue[i] = queue[i + 1]; 
			} 
			size--; 
		} 
	} 
	void print() { 
		if (size == 0) { 
			cout << "Queue is empty"<<endl; 
			return; 
		} 
		for (int i = 0; i < size; i++) { 
			cout<<queue[i]<<" <- ";
		} 
		cout << endl;
	}
	//your code goes here
	Queue operator+(Queue &qObj)
	{
		Queue result;
		
		for(int i =0; i< size; i++)
		{
		    result.add(queue[i]);
		}
		for(int i =0; i< size; i++)
		{
		    result.add(qObj.queue[i]);
		}

		return result;
	}
	
}; 

int main() { 
	Queue q1; 
	q1.add(42); q1.add(2); q1.add(8);  q1.add(1);
	//q1.print();


	Queue q2;
	q2.add(3); q2.add(66); q2.add(128);  q2.add(5);
	Queue q3 = q1+q2;
	q3.print();

	return 0; 
} 

