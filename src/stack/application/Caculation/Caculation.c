#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "DataBase.h"

int infixToPostfix(char *infix[], char *postfix[], int argc);
int caculatePostfix(char *postfix[], int postfixc);

int main(int argc, char *argv[])
{
  int i;
  int len;
  char *postfix[argc];
  len = infixToPostfix(argv, postfix, argc);
  int result = caculatePostfix(postfix, len); 
  
  printf("%d\n", result);
  /**for (i = 0;  i< len; i++) {
    printf("%s\n", postfix[i]);
  }*/
  return OK;
}

int infixToPostfix(char *argv[], char *postfix[], int argc){
  int i, j=0;
  SElemType *e = (SElemType *) malloc(sizeof(SElemType));
  LinkStack *S = (LinkStack *) malloc(sizeof(LinkStack));
  Init(S);
  for (i = 1; i < argc; i++) {
    if(strcmp(argv[i], "+") == 0 || strcmp(argv[i], "-") == 0) {
      if (!S->top || strcmp(S->top->data, "(") == 0) {
        Push(S, argv[i], 1);
      } else {
        while (Pop(S, e, 1)){
          postfix[j] = (char *) malloc((strlen(*e) + 1) * sizeof(char));
          strcpy(postfix[j++], *e);
        }
        Push(S, argv[i], 1);
      }
    } else if (strcmp(argv[i], "*") == 0 || strcmp(argv[i], "/") == 0) {
      if (!S->top || strcmp(S->top->data, "-") == 0 || strcmp(S->top->data, "+") == 0
        || strcmp(S->top->data, "(") == 0) {
        Push(S, argv[i], 1);
      } else {
        while (Pop(S, e, 1)){
          postfix[j] = (char *) malloc((strlen(*e) + 1) * sizeof(char));
          strcpy(postfix[j++], *e);
        }
        Push(S, argv[i], 1);
      }
    } else if (strcmp(argv[i], ")") == 0) {
      while (Pop(S, e, 1) && strcmp(*e, "(") != 0) {
         postfix[j] = (char *) malloc((strlen(*e) + 1) * sizeof(char));
         strcpy(postfix[j++], *e);
      }
    } else if (strcmp(argv[i], "(") == 0) {
      Push(S, argv[i], 1);
    } else {
       postfix[j] = (char *) malloc((strlen(argv[i]) + 1) * sizeof(char));               
       strcpy(postfix[j++], argv[i]);
    }
  }
  while (Pop(S, e, 1)) {
    postfix[j] = (char *) malloc((strlen(*e) + 1) * sizeof(char));
    strcpy(postfix[j++], *e);
  }
  free(e);
  free(S);
  return j;
}

int caculatePostfix(char *postfix[], int postfixc){
  int i, j=0;
  int *e = (int *) malloc(sizeof(int));
  SElemType *e1 = (SElemType *) malloc(sizeof(SElemType));
  SElemType *e2 = (SElemType *) malloc(sizeof(SElemType));
  LinkStack *S = (LinkStack *) malloc(sizeof(LinkStack));
  Init(S);
  for (i = 0; i < postfixc; i++) {
    if (strcmp(postfix[i], "+") == 0) {
		Pop(S, e1, 2);
		Pop(S, e2, 2);
		*e = *(int*) *e2 + *(int*) *e1;
		Push(S, e , 2);
	} else if (strcmp(postfix[i], "-") == 0) {
		Pop(S, e1, 2);
		Pop(S, e2, 2);
		*e = *(int*) *e2 - *(int*) *e1;
		Push(S, e , 2);
	} else if (strcmp(postfix[i], "*") == 0) {
		Pop(S, e1, 2);
		Pop(S, e2, 2);
		*e = *(int*) *e2 * *(int*) *e1;
		Push(S, e , 2);
	} else if (strcmp(postfix[i], "/") == 0) {
		Pop(S, e1, 2);
		Pop(S, e2, 2);
		*e = *(int*) *e2 / *(int*) *e1;
		Push(S, e , 2);
	} else {
		int temp = atoi(postfix[i]);
		e = &temp;
		Push(S, e, 2);
	}
  }
  Pop(S, e1, 2);
  return *(int*) *e1;
}
