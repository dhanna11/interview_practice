#include <stddef.h>

struct Uba;

struct Uba* newUba(size_t size);
int UbaEmplace(struct Uba* uba, void* elm);
int UbaRemove(struct Uba* uba, size_t idx);
void* UbaBack(struct Uba* uba);
