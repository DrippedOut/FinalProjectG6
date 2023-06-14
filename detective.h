#include <iostream>
#include <string>
using namespace std;

class Detective {
private:
    string name;
    string specie;
    int age;
    Detective* partner;
    int numCase;

public:
    Detective(string name = "Bot", string specie = "Android", int age = 0);
    ~Detective() {
        cout << "Goodbye detective " << name << endl;
    }

    // Getter & Setter
    string getName() { return name; }
    string getSpecie() { return specie; }
    int getAge() { return age; }
    void setPartner(Detective* partner) { this->partner = partner; }
    Detective* getPartner() { return partner; }
    int getNumCase() { return numCase; }
    void setNumCase(int numCases) { this->numCase = numCases; }

    void bubbleSort(Detective* detectives[], int size); // sort by Experience = age * numCase
    Detective* moreExp(Detective* other);

    void changePartner(Detective* newPartner) { partner = newPartner; }
    void addNumCase() { numCase++; }
    void print();

    bool operator==(const Detective& other) {
        return (name == other.name && specie == other.specie && age == other.age);
    }
    void operator++() { age++; }
    void operator--() { age--; }
};

Detective::Detective(string name, string specie, int age) {
    this->name = name;
    this->specie = specie;
    this->age = age;
    partner = nullptr;
    numCase = 0;
  
    cout << "Welcome, detective " << name << endl;
}

void Detective::bubbleSort(Detective* detectives[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            Detective* current = detectives[j];
            Detective* next = detectives[j + 1];

            if (*(current->moreExp(next)) == *next) {
                detectives[j] = next;
                detectives[j + 1] = current;
            }
        }
    }
}


Detective* Detective::moreExp(Detective* other) {
    int exp1 = age * numCase;
    int exp2 = other->getAge() * other->getNumCase();

    if (exp1 > exp2)
        return this;
    else
        return other;
}

void Detective::print() {
    cout << "Name: " << name << endl
         << "Species: " << specie << endl
         << "Age: " << age << endl
         << "Num Cases: " << numCase << endl << endl;
}
