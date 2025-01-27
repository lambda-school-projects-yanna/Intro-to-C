#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "lib.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "lib.h"
#include <string.h>
// #include "lib.h"

int string_length(char *s)
{
  return strlen(s);
}


char *string_dup(char *src)
{
   int n = string_length(src);
   char *str = malloc(n + 1);

   for (int i = 0; i < n; i++) {
       *(str+i) = *(src+i);
   }

   *(str+n) = '\0';

   return str;
}

void mem_copy(void *dest, const void *src, int n)
{

    char *cast_dest = (char *) dest;
    char *cast_src = (char *) src;
    for (int i=0; i<n; i++) {
        *(cast_dest + i) = *(cast_src + i);
    }
}

void *resize_memory(void *ptr, int old_size, int new_size)
{
    if (new_size == 0) {
        free(ptr);
        return NULL;
    }

    else if (!ptr) {
        return malloc(new_size);
    }

    else if (old_size == new_size) {
        return ptr;
    }

    void *new_block = malloc(new_size);

    if (new_size < old_size) {
        mem_copy(new_block, ptr, new_size);
    }

    else {
        mem_copy(new_block, ptr, old_size);
    }

    free(ptr);
    return new_block;
}

#ifndef TESTING
int main(void)
{
    char *s = "Some string to duplicate.";
    char *dup = string_dup(s);

    printf("Duplicated string: %s\n", dup);

    int numbers[] = {100, 55, 4, 98, 10, 18, 90, 95, 43, 11, 47, 67, 89, 42, 49, 79};
    int n = sizeof(numbers) / sizeof(numbers[0]);
    int *target = malloc(n * sizeof(int));
    
    mem_copy(target, numbers, n * sizeof(int));

    printf("Copied array: ");

    for (int i = 0; i < n; i++) {
        printf("%d ", target[i]);
    }

    printf("\n");

    char *url = string_dup("http://lambdaschool.com");
    char *path = string_dup("/students/");
    int url_length = string_length(url);
    int path_length = string_length(path);
    
    int new_length = url_length - 1 + path_length;
    char *new_url = resize_memory(url, url_length, new_length);
    char *p = new_url + url_length;

    while (*path != '\0') {
        *p = *path;
        p++;
        path++;
    }

    printf("Full path string: %s\n", new_url);

    return 0;
}
#endif