#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

static int cnt;

class Element {
public:

  Element() {
    id = cnt++;
  }

  Element(char *str) {
      // ____qcodep____
      value = new char[strlen(str) + 1];
      strcpy(value, str);
      id = cnt;

      Element();
  }

  Element(Element &obj) {
      // ____qcodep____
      value = new char[strlen(obj.value) + 1];
      strcpy(value, obj.value);
      id = cnt;

      Element();
  }

  char* get_value() {
    return value;
  }

  void set_value(char *str) {
    value = str;
  }

private:
  int id;
  char *value;
};

Element *elements[10];

class Operator {
public:  
  virtual void operator()() {}

  void read_arguments() {
    int i = 0;
    while (cin >> operands[i++]) {
      if (getchar() == '\n') break;
    }
  }

protected:
  char operands[4][10]; 
};

// ____qcodep____
class New : public Operator {
public:
  void operator()() {
    Element *elem = new Element(operands[0]);
    elements[cnt - 1] = elem;
  }
};

class Copy : public Operator {
public:
  void operator()() {
    int id = atoi(operands[0]);
    Element *elem = new Element(*elements[id]);
    elements[cnt - 1] = elem;
  }
};

class Swap : public Operator {
public:
  void operator()() {
    int id1 = atoi(operands[0]);
    int id2 = atoi(operands[1]);
    char *temp = elements[id1]->get_value();
    elements[id1]->set_value(elements[id2]->get_value());
    elements[id2]->set_value(temp);
  }
};

class Replace : public Operator {
public:
  void operator()() {
    int id = atoi(operands[0]);
    elements[id]->set_value(operands[1]);
  }
};

class Query : public Operator {
public:
  void operator()() {
    int id = atoi(operands[0]);
    cout << elements[id]->get_value() << endl;
  }
};

int main() {
  int m, i;
  char ch;
  cin >> m;
  Operator *op;

  for (i = 0; i < m; i++) {
    cin >> ch;
    switch (ch) {
      case 'N':  //new
        op = new New();
        break;
      case 'C':  //copy
        op = new Copy();
        break;
      case 'S':  //swap
        op = new Swap();
        break;
      case 'R':  //replace
        op = new Replace();
        break;
      case 'Q':  //querry
        op = new Query();
        break;
    }
    op->read_arguments();
    (*op)();
  }

}