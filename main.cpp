#include "detective.h"
#include <iostream>
using namespace std;

int main() {
    const int numDetectives = 5;

    Detective* detectives[numDetectives];
    detectives[0] = new Detective("Sherlock Holmes", "Human", 45);
    detectives[1] = new Detective(); // Using default constructor
    detectives[2] = new Detective("Cristiano Ronaldo", "Goat", 38);
    detectives[3] = new Detective("Batman", "Human", 35);
    detectives[4] = new Detective("Scooby-Doo", "Dog", 7);

    Detective* detectivePtr = new Detective("Freaky Franco", "Frog", 9);

    cout << endl;
    detectives[0]->print();
    detectives[1]->print();
    detectives[2]->print();
    detectives[3]->print();
    detectives[4]->print();
    detectivePtr->print();

    cout << endl;
    detectives[0]->changePartner(detectives[1]);
    detectives[0]->addNumCase();
    detectives[1]->addNumCase();

    detectives[0]->print();
    detectives[1]->print();

    cout << endl;
    ++(*detectives[0]);
    --(*detectives[1]);

    detectives[0]->print();
    detectives[1]->print();

    cout << endl;
    Detective* moreExperienced = detectives[0]->moreExp(detectives[1]);
    cout << "Detective with more experience: " << moreExperienced->getName() << endl;

    cout << endl;
    detectives[0]->bubbleSort(detectives, numDetectives);

    cout << "Sorted Detectives by Experience:" << endl;
    for (int i = 0; i < numDetectives; i++) {
        detectives[i]->print();
    }

    // Cleanup
    for (int i = 0; i < numDetectives; i++) {
        delete detectives[i];
    }
    delete detectivePtr;

    return 0;
}
