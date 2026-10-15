#include <iostream>
#include <iomanip>
#include <cmath>
#include "coordinate.h"

using namespace std;

void add_coordinate(Coordinate *list_end, float x, float y)
{
  Coordinate *new_coord = new Coordinate;
  Coordinate *temp = list_end;
  int count = 1;

  // count the nodes by walking back to the start
  while (temp->previous != NULL)
  {
    count++;
    temp = temp->previous;
  }

  new_coord->x = x;
  new_coord->y = y;
  new_coord->coord_id = count;
  new_coord->next = NULL;
  new_coord->previous = list_end;
  list_end->next = new_coord;
}

void forward_display(Coordinate *list_beginning)
{
  cout << fixed << setprecision(2);
  Coordinate *temp = list_beginning;
  while (temp != NULL)
  {
    cout << "id " << temp->coord_id << ": (" << temp->x << ", " << temp->y << ")" << endl;
    temp = temp->next;
  }
}

void backward_display(Coordinate *list_end)
{
  cout << fixed << setprecision(2);
  Coordinate *temp = list_end;
  while (temp != NULL)
  {
    cout << "id " << temp->coord_id << ": (" << temp->x << ", " << temp->y << ")" << endl;
    temp = temp->previous;
  }
}

void delete_coordinate(Coordinate *list_beginning, int coord_id_to_delete)
{
  Coordinate *temp = list_beginning;

  while (temp != NULL && temp->coord_id != coord_id_to_delete)
  {
    temp = temp->next;
  }

  if (temp == NULL)
  {
    cout << "id " << coord_id_to_delete << " not found" << endl;
    return;
  }

  if (temp == list_beginning)
  {
    // the head pointer can't change, so copy the second node in and delete it
    Coordinate *second = temp->next;
    if (second == NULL)
    {
      cout << "can't delete the only coordinate" << endl;
      return;
    }
    temp->x = second->x;
    temp->y = second->y;
    temp->coord_id = second->coord_id;
    temp->next = second->next;
    if (second->next != NULL)
    {
      second->next->previous = temp;
    }
    delete second;
  }
  else
  {
    temp->previous->next = temp->next;
    if (temp->next != NULL)
    {
      temp->next->previous = temp->previous;
    }
    delete temp;
  }
}

int list_length(Coordinate *list_beginning)
{
  int count = 0;
  Coordinate *temp = list_beginning;
  while (temp != NULL)
  {
    count++;
    temp = temp->next;
  }
  return count;
}

void closest_to(Coordinate *list_beginning, float x, float y)
{
  Coordinate *temp = list_beginning;
  Coordinate *closest = list_beginning;
  float best = -1;

  while (temp != NULL)
  {
    float dx = temp->x - x;
    float dy = temp->y - y;
    float dist = sqrt(dx * dx + dy * dy);
    if (best < 0 || dist < best)
    {
      best = dist;
      closest = temp;
    }
    temp = temp->next;
  }

  cout << fixed << setprecision(2);
  cout << "closest to (" << x << ", " << y << ") is id " << closest->coord_id
       << " (" << closest->x << ", " << closest->y << "), distance " << best << endl;
}
