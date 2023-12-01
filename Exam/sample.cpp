#include <iostream>
#include <string>
using namespace std;

class Animal {
protected:
    string name;
    int age;

public:
    void SetName(const string& animalName) {
        name = animalName;
    }

    void SetAge(int animalAge) {
        age = animalAge;
    }

    virtual void WhoAmI() = 0;  // Pure virtual function
};

class Zebra : public Animal {
public:
    void WhoAmI() {
        cout << "I am a zebra called " << name << " and I am " << age << " years old." << endl;
    }
};

class Dolphin : public Animal {
public:
    void WhoAmI() {
        cout << "I am a dolphin called " << name << " and I am " << age << " years old." << endl;
    }
};

int main() {
    Animal* animalArray[2];  // Array of animal pointers

    Dolphin dolphin;
    Zebra zebra;

    dolphin.SetName("Dolphie");
    dolphin.SetAge(7);

    zebra.SetName("Zebbie");
    zebra.SetAge(5);

    animalArray[0] = &dolphin;  // Assign Dolphin instance to the first field
    animalArray[1] = &zebra;    // Assign Zebra instance to the second field

    animalArray[0]->WhoAmI();  // Call WhoAmI() method of the Dolphin instance
    animalArray[1]->WhoAmI();  // Call WhoAmI() method of the Zebra instance

    return 0;
}
