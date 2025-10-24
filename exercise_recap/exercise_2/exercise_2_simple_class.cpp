// Create a class Dog with attributes name and age, and a method bark() that prints “Woof!”.

#include <iostream>
#include <string>
using std::cout;
using std::cin;
using std::endl;
using std::string;


class Dog {
    public:
        // Add a constructor to Dog that initializes name and age, and print a message when it’s called.
        string name;
        int age;
    
    void bark(){
        cout << "woof woof" << endl;
    }

    void name_age(){
        cout << "My name is " << name <<endl;
        cout << "My age is " << age << endl;
    }

    string dog_type;
    int number_of_heads;

    // can pre-set constructor later 
    Dog(string dt, int noh){
        dog_type = dt;
        number_of_heads = noh;
    }

    // can setup constructor manually
    Dog (){
        dog_type = "the_dog";
        number_of_heads = 1;
    }

};

int main() {
    Dog billybob;
    billybob.bark();
    billybob.name_age();
    billybob.name = "billy";
    billybob.age = 10;
    billybob.name_age();
    
    
}