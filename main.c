#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "coordinate.h"

int main(int argc, char *argv[])
{
  if (argc != 2)
  {
    printf("usage: ./main <number of coordinates>\n");
    return 1;
  }

  int n = atoi(argv[1]);
  if (n < 1)
  {
    printf("enter a number of 1 or more\n");
    return 1;
  }

  srand(time(NULL));

  // make the first node by hand
  Coordinate *list_beginning = malloc(sizeof(Coordinate));
  list_beginning->x = (float)(rand() % 10000) / 100;
  list_beginning->y = (float)(rand() % 10000) / 100;
  list_beginning->coord_id = 0;
  list_beginning->next = NULL;
  list_beginning->previous = NULL;
  Coordinate *list_end = list_beginning;

  int i;
  for (i = 1; i < n; i++)
  {
    add_coordinate(list_end, (float)(rand() % 10000) / 100, (float)(rand() % 10000) / 100);
    list_end = list_end->next;
  }

  printf("Length: %d\n", list_length(list_beginning));

  printf("\nForward:\n");
  forward_display(list_beginning);

  printf("\nBackward:\n");
  backward_display(list_end);

  printf("\nDeleting id 2\n");
  delete_coordinate(list_beginning, 2);
  forward_display(list_beginning);
  printf("Length: %d\n", list_length(list_beginning));

  printf("\n");
  closest_to(list_beginning, 50.0, 50.0);

  // free everything
  Coordinate *temp = list_beginning;
  while (temp != NULL)
  {
    Coordinate *next = temp->next;
    free(temp);
    temp = next;
  }

  return 0;
}
