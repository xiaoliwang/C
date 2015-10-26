#ifndef _DATA_BASE_
#define _DATA_BASE_

#define OK 1
typedef char * String;
void get_next(String T, int len, int *next);
void get_nextval(String T, int len, int *next);
int Index_KMP(String S, int len1, String T, int len2, int pos);
#endif