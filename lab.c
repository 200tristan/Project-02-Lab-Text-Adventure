// 2/22/2020
// Jake Stulgis, Jenny Guo, Ashwin Randhir

#include <stdio.h>
#include <string.h>

struct Item{
    char *name;
    char *description;
    struct Item *next;
}

struct Item *item(char* name, char* description)
  
struct Item *next;

struct Item* items = item("bronze key", "a dull bronze key", 
                          item("rope", "a leather-bound rope", NULL));

struct Room * room(char* description, struct Item* items,
                   struct Room *north, struct Room *south,
                   struct Room *east, struct Room *west,
                   struct Room *up, struct Room *down);

void room_exit_north(struct Room* current, struct Room* other);
