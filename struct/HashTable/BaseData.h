#ifndef _BASE_DATA_
#define _BASE_DATA_

#define SUCCESS 1
#define UNSUCCESS 0
#define HASHSIZE 12
#define NULLKEY -32768
#define OK 1

typedef int Status;

typedef struct
{
  int *elem;
  int count;
}HashTable;

Status InitHashTable(HashTable *H);
void InsertHash(HashTable *H, int key);
Status SearchHash(HashTable H, int key, int *addr);
#endif