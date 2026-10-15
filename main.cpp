#include <iostream>
#include <cstdlib>
#include <ctime>
#include "coordinate.h"

using namespace std;

int main(int argc, char *argv[])
{
  if (argc != 2)
  {
    cout << "usage: ./main <number of coordinates>" << endl;
    return 1;
  }

  int n = atoi(argv[1]);
  if (n < 1)
  {
    cout << "enter a number of 1 or more" << endl;
    return 1;
  }

  srand(time(NULL));

  // make the first node by hand
  Coordinate *list_beginning = new Coordinate;
  list_beginning->x = (float)(rand() % 10000) / 100;
  list_beginning->y = (float)(rand() % 10000) / 100;
  list_beginning->coord_id = 0;
  list_beginning->next = NULL;
  list_beginning->previous = NULL;
  Coordinate *list_end = list_beginning;

  for (int i = 1; i < n; i++)
  {
    add_coordinate(list_end, (float)(rand() % 10000) / 100, (float)(rand() % 10000) / 100);
    list_end = list_end->next;
  }

  cout << "Length: " << list_length(list_beginning) << endl;

  cout << "\nForward:" << endl;
  forward_display(list_beginning);

  cout << "\nBackward:" << endl;
  backward_display(list_end);

  cout << "\nDeleting id 2" << endl;
  delete_coordinate(list_beginning, 2);
  forward_display(list_beginning);
  cout << "Length: " << list_length(list_beginning) << endl;

  cout << endl;
  closest_to(list_beginning, 50.0, 50.0);

  // free everything
  Coordinate *temp = list_beginning;
  while (temp != NULL)
  {
    Coordinate *next = temp->next;
    delete temp;
    temp = next;
  }

  return 0;
}
