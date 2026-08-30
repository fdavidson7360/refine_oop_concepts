//==== Example 1
#include <iostream>
using namespace std;

class Game
{
    public:
    Game() {
        cout <<"Game Started"<<endl;
    }
    //destructor goes here
    ~Game() {
        cout << "Game Over" << endl;
    }
    
};

class Quiz: public Game
{
    public:
    Quiz() {
        cout <<"Quiz Started"<<endl;
    }
    //destructor goes here
    ~Quiz(){
        cout << "Quiz Over" <<endl;
    }
    
};

int main() {
    Quiz q;
}


//==== Example 2 Polymorphism 
#include <iostream>
using namespace std;

class Enemy {
    protected: 
        int attackPower;
    public:
        void setAttackPower(int a){
            attackPower = a;
        }
};

class Ninja: public Enemy {
    public:
        void attack() {
            cout << "Ninja! - "<<attackPower<<endl;
        }
};

class Monster: public Enemy {
    public:
        void attack() {
            cout << "Monster! - "<<attackPower<<endl;
        }
};

int main() {
    Ninja n;
    Monster m;
    Enemy *e1 = &n;
    Enemy *e2 = &m;

    e1->setAttackPower(20); // same as n.setAttackPower(20);
    e2->setAttackPower(80); // same as m.setAttackPower(80); but the pointer is faster than the object itself, so we use the pointer to set the attack power.

    n.attack();
    m.attack();
}


//==== Example 3 Polymorphism extended example
#include <iostream>
using namespace std;

class Drink {
    protected: 
        int price;
    public:
        void setPrice(int a){
            price = a;
        }
        void make() 
        {
            cout << "Drink: " << price << endl;
        }
};

class Coffee : public Drink {
    public:
        void make() {
            cout << "Coffee: "<<price<<endl;
        }
};

class Tea : public Drink{
    public:
        void make() {
            cout << "Tea: "<<price<<endl;
        }
};

int main() {
    Coffee c;
    Tea t;
    Drink *e1 = &c;
    Drink *e2 = &t;

    e1->setPrice(5);
    e2->setPrice(6);

    c.make();
    t.make();
}

//==== Example 4 Virtual functions

#include <iostream>
using namespace std;

class Animal
{
    public:
        string name;
    //your code goes here
    virtual void speak() {}
    
};
class Dog: public Animal
{
    public:
        void speak() {
            cout <<"Woof!"<<endl;
        }
};
class Cat: public Animal
{
    public:
        void speak() {
            cout <<"Meaw!"<<endl;
        }
};

int main() {
    Cat c1;
    c1.name = "Fluffy";
    Dog d1;
    d1.name = "Bingo";
    
    Animal *a1 = &c1;
    Animal *a2 = &d1;
    
    Animal* arr[] = {a1, a2}; 
    for(int i=0;i<2;i++){
        arr[i]->speak();
    }
}

//==== Example 5 Astract Classes
#include <iostream>
using namespace std;

class Enemy {
    public:
        virtual void attack() {
            cout << "Enemy!"<<endl;
        }
};

class Ninja: public Enemy {
    public:
        void attack() {
            cout << "Ninja!"<<endl;
        }
};

class Monster: public Enemy {
    public:
        void attack() {
            cout << "Monster!"<<endl;
        }
};

int main() {
    Ninja n;
    Monster m;
    Enemy e;

    Enemy *e1 = &n;
    Enemy *e2 = &m;
    Enemy *e3 = &e;

    e1->attack();
    // Outputs "Ninja!"

    e2->attack();
    // Outputs "Monster!"

    e3->attack();
    // Outputs "Enemy!"
}

//==== Example 6 Pure Virtual Functions virtual void attack() = 0; 
// Just means that the function is a pure virtual function, and it must be implemented in the derived class. 
//It also means that the base class cannot be instantiated, and it can only be used as a base class for other classes. 
//The derived class must implement the pure virtual function, otherwise it will also be an abstract class and cannot be instantiated.

// Abstract Classes
// You cannot create objects of the base class with a pure virtual function.
#include <iostream>
using namespace std;

class Enemy {
    public:
        virtual void attack() = 0;
};

class Ninja: public Enemy {
    public:
        void attack() {
            cout << "Ninja!"<<endl;
        }
};

class Monster: public Enemy {
    public:
        void attack() {
            cout << "Monster!"<<endl;
        }
};


int main()
{
    Enemy e;
    return 0;
}

#include <iostream>
using namespace std;

class Enemy {
    public:
        virtual void attack() = 0;
};

class Ninja: public Enemy {
    public:
        void attack() {
            cout << "Ninja!"<<endl;
        }
};

class Monster: public Enemy {
    public:
        void attack() {
            cout << "Monster!"<<endl;
        }
};


int main()
{
    Ninja n;
    Monster m;
    Enemy *e1 = &n;
    Enemy *e2 = &m;

    e1->attack();
    e2->attack();

    return 0;
}

//==== Example 7 Queue class with inheritance and polymorphism
#include <iostream>
using namespace std; 

class Queue { 
    protected:
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
    	Queue operator+(Queue &obj) {
            Queue res;
            for(int i=0;i<this->size;i++) {
                res.add(this->queue[i]);
            }
            for(int i=0;i<obj.size;i++) {
                res.add(obj.queue[i]);
            }
            return res; 
        }
}; 

class Queue2 : public Queue {
    public:
        void print()
        {
            if (size == 0) 
            { 
			cout << "Queue is empty"<<endl; 
			return; 
    		} 
    		for (int i = 0; i < size; i++) 
    		{ 
    			cout << queue[i] << endl;
    		} 
        }
};

//your code goes here


int main() { 
	Queue q1; 
	q1.add(42); q1.add(2); q1.add(8);  q1.add(1);
    q1.print();
    
	Queue2 q2;
	q2.add(3); q2.add(66); q2.add(128);  q2.add(5);q2.add(111);q2.add(77890);
	q2.print();

	return 0; 
} 
