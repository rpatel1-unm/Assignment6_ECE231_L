# Assignment 6 - Doubly-Linked List of Coordinates

## What it does
This program builds a doubly-linked list that stores x-y coordinate pairs. The user gives the number of coordinates on the command line, and the program fills the list with random x and y values (0.00 to 99.99). Each node points to both the next and the previous node, so the list can be walked forward or backward.
main.c then tests every list function: it displays the list in both directions, deletes a coordinate, prints the new length, and finds the coordinate closest to a given point.

## Files
- coordinate.h - the Coordinate struct and function prototypes
- coordinate.c - the linked list functions
- main.c - reads the command line, builds the list, and tests each function

## Functions
- add_coordinate: adds a node to the end of the list (coord_id is based on the list length)
- forward_display: prints all coordinates from beginning to end
- backward_display: prints all coordinates from end to beginning
- delete_coordinate: removes a node by coord_id and frees its memory
- list_length: returns the number of nodes
- closest_to: finds the coordinate nearest to a given x, y and prints the distance

## Build and run
    gcc -o main main.c coordinate.c -lm
    ./main 10

## Notes
- Distance is the straight-line distance: sqrt((x2 - x1)^2 + (y2 - y1)^2)
- Deleting the first node copies the second node's data into it, sinece the head pointers can not be changed by the function
- All alloceted memory is freed at the end of main

