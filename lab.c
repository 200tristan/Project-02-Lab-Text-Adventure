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

struct Item* item_take(char* name, struct Item *item){
    while(item->next!=NULL){
        if(strcmp(item->next->name, name) == 0){//implies two strings are equal
            struct Item* remove = item->next;
            struct Item* returnItem = item(remove->name, remove->description, NULL);
            item->next = item->next->next;
            free(remove);
            return returnItem;
        }
        item = item->next;
    }
    return NULL;
}

struct Room{
    char* description;
    struct Item* items;
    struct Room *north;
    struct Room *south;
    struct Room *east;
    struct Room *west;
    struct Room *up;
    struct Room *down;
}                          

struct Room * room(char* description, struct Item* items,
                   struct Room *north, struct Room *south,
                   struct Room *east, struct Room *west,
                   struct Room *up, struct Room *down){
    struct Room *newRoom = NULL;
    newRoom = (struct Room *)malloc(sizeof(struct Room));
    
    if(newRoom == NULL){
        return NULL;
    }
    
    newRoom->description = description;
    newRoom->items = items;
    newRoom->north = north;
    newRoom->south = south;
    newRoom->east = east;
    newRoom->west = west;
    newRoom->up = up;
    newRoom->down = down;
    
    return newRoom;
}

void room_exit_north(struct Room* current, struct Room* other){
    current->north = other;
}

int main(){
    struct Item* item1 = item("bronze key", "a dull bronze key", 
                          item("rope", "a leather-bound rope", NULL));
    struct Item* item2 = item("old box", "a box with dust", 
                          item("notebook", "a CS notebook", NULL));
    struct Room *room1 = room("Seems like no one lives in this room for a long time", item1, NULL, NULL, NULL, NULL, NULL, NULL);
    struct Room *room2 = room("Looks like scientist's room", item2, NULL, NULL, NULL, NULL, NULL, NULL);

    room_exit_north(room1, room2);
    
}


