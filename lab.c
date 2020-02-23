// 2/22/2020
// Jake Stulgis, Jenny Guo, Ashwin Randhir

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Item{
    char *name;
    char *description;
    struct Item *next;
}

struct Item *item(char* name, char* description, struct Item *next){
    struct Item *newItem = NULL;
    newItem = (struct Item *)malloc(sizeof(struct Item));
    
    if(newItem == NULL){
        return NULL;
    }
    
    newItem->name = name;
    newItem->description = description;
    newItem->next = next;
    
    return newItem;
}
  
char* item_name(struct Item *item){
    return item->name;
}

char* item_description(struct Item *item){
    return item->description;
}

char* item_next(struct Item *item){
    return item->next;
}



struct Item* items = item("bronze key", "a dull bronze key", 
                          item("rope", "a leather-bound rope", NULL));

struct Room * room(char* description, struct Item* items,
                   struct Room *north, struct Room *south,
                   struct Room *east, struct Room *west,
                   struct Room *up, struct Room *down);

void room_exit_north(struct Room* current, struct Room* other);
