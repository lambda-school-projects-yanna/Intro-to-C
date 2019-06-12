#include <stdio.h>
#include <stdlib.h>
#include "lib.h"

/* 
    Define the Person struct by specifying the fields that make up the
    Person type. Don't forget to specify the type of each field. A 
    Person should have the fields `name`, `age`, `height`, and `weight`.
*/
/* 
    Define the Person struct by specifying the fields that make up the
    Person type. Don't forget to specify the type of each field. A 
    Person should have the fields `name`, `age`, `height`, and `weight`.
*/
typedef struct Person {

	char *name;
	int age;
	int height;
	int weight;
} Person;


Person *createPerson(char *name, int age, int height, int weight)
{
	struct Person *who = malloc(sizeof(struct Person));

    who->name = string_dup(name);
	who->age = age;
	who->height = height;
	who->weight = weight;

	return who;

}

void destroyPerson(Person *who)
{

  free(who->name);
	free(who);
}

#ifndef TESTING
int main(void)
{
    Person *tony = createPerson("Tony Stark", 32, 64, 140);

    printf("  Name: %s\n", tony->name);
    printf("   Age: %d\n", tony->age);
    printf("Height: %d\n", tony->height);
    printf("Weight: %d\n", tony->weight);

    destroyPerson(tony);

    return 0;
}
#endif