#include "detective.h" // Include the detective class header
#include "ll.h"        // Include the LL class header
#include "queue.h"     // Include the queue class header

#include <iostream>
using namespace std;

// Display menu
void menu(void) {
  cout << " [ 1 ] Register as a detective" << endl;       // Create instance
  cout << " [ 2 ] Make reservation (for client)" << endl; // enqueue
  cout << " [ 3 ] Finish investigation (for detective)" << endl; // dequeue
  cout << " [ 4 ] Display queue" << endl;                        // Print queue
  cout << " [ 5 ] Display detective rank" << endl;               // Print LL
  cout << " [ 6 ] Resign (for detective)" << endl;
  cout << " [ 7 ] Exit" << endl;

  printf("\n");
}

int main() {
  Queue q;
  LL l;
  unsigned int choice;

  // Case 1
  string nm, sp;
  int ex;
  // Case 2
  string nm2, target_name;
  // Case 6
  string nm6;

  cout << "Hello! We are the IDA, \n"
          "Intergalactic Detectives Agency. \n"
          "What service can we offer you? \n"
          ""
       << endl;

  menu(); // display menu

  cout << ">> ";
  cin >> choice;

  while (choice != 7) {

    switch (choice) {
    case 1: // Register as a detective
      cout << "Input in this format: " << endl;
      cout << "*name* *specie* *experience*" << endl;
      printf("\n");
      cout << ">> ";
      cin >> nm >> sp >> ex; // name specie experience
      l.insert(nm, sp, ex);
      printf("\n");
      l.printList();
      break;

    case 2: // Make reservation (for client)
      cout << "Input in this format: " << endl;
      cout << "*Target name* *Detective name*" << endl;
      printf("\n");
      cout << ">> ";
      cin >> target_name >> nm2;
      q.enqueue(target_name, l.search(nm2));
      break;

    case 3: // Finish investigation (for detective)
      
      q.dequeue();
      break;

    case 4: // Display queue
      q.printQueue();
      break;

    case 5: // Display detective rank
      l.printList();
      break;

    case 6: // Resign (for detective)
      cout << "Please say your name" << endl;
      printf("\n");
      cout << ">> ";
      cin >> nm6;
      l.deletes(nm6);
      break;

    default:
      cout << "Invalid choice." << endl;
      menu();
      break;
    }

    printf("\n");
    menu();
    cout << ">> ";
    cin >> choice;
  }

  return 0;
}
