#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Descriptor
{
    int id;
    int name_length;
    char *name;
} Descriptor;

Descriptor* allocate_and_initialize_descriptor(int id, const char* name)
{
    struct Descriptor* descriptor = (Descriptor*)malloc(sizeof * descriptor);

    descriptor->id = id;
    descriptor->name_length = strlen(name);
    descriptor->name = (char*)malloc(strlen(name) + 1);
    if (descriptor->name) {
        strcpy(descriptor->name, name);
    };
    return descriptor;
}

void deallocate_descriptor(Descriptor* descriptor)
{
    free(descriptor->name);
    free(descriptor);
}

#ifndef RunTests
int main()
{
    Descriptor *descriptor = allocate_and_initialize_descriptor(2, "File");
    printf("Id: %d, name length: %d, name: %s", descriptor->id, descriptor->name_length, descriptor->name);
    deallocate_descriptor(descriptor);
}
#endif