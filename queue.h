#ifndef QUEUE_H
#define QUEUE_H

#include "detective.h"

class Queue {
  DPtr headPtr;
  DPtr tailPtr;
  int size;

public:
  void enqueue(string, DPtr);
  void dequeue();
  void printQueue();
  Queue();
  ~Queue(); // dequeue all
};

Queue::Queue() {
  size = 0;
  headPtr = NULL;
  tailPtr = NULL;
}

Queue::~Queue() {
  int i;
  int n = size;
  for (i = 0; i < n; i++)
    dequeue();
}

void Queue::enqueue(string n, DPtr x) {
  if (x && x->getTarg() == "None") {
    if (size == 0) {
      headPtr = x;
    } else {
      tailPtr->set_next(x);
    }
    ++size;
    tailPtr = x;

    x->set_Targ(n);
    cout << "Your reservation has been made" << endl;
  } else
    cout << "Your reservation was declined";
}

void Queue::dequeue() {
  string targ;
  DPtr t;
  if (headPtr && size > 0) {
    t = headPtr;
    targ = t->getTarg();
    t->set_Targ("None");
    headPtr = headPtr->get_next();
    if (size == 1)
      tailPtr = NULL;
    size--;
    //delete t;
    cout << targ << " has been found" << endl;
    return;
  }
  cout << "Queue is empty" << endl;
}

void Queue::printQueue() {
  if (size == 0) {
    cout << "Queue is empty." << endl;
    return;
  }

  cout << "The queue is:" << endl;
  printf("\n");

  DPtr currentPtr = headPtr;
  int position = 1;

  while (currentPtr != NULL) {
    cout << "Position " << position << ":" << endl;
    currentPtr->print();
    cout << endl;
    if (currentPtr == tailPtr)
      break;
    currentPtr = currentPtr->get_next();
    position++;
  }
}

#endif // QUEUE_H