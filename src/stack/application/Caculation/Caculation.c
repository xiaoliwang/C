#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "DataBase.h"

int infixToPostfix(char *infix[], char *postfix[], int argc);

int main(int argc, char *argv[])
{
  int i;
  int len;
  char *postfix[argc];
  len = infixToPostfix(argv, postfix, argc);
  
  for (i = 0;  i< len; i++) {
    printf("%s\n", postfix[i]);
  }
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
        Push(S, argv[i]);
      } else {
        while (Pop(S,e)){
          postfix[j] = (char *) malloc((strlen(*e) + 1) * sizeof(char));
          strcpy(postfix[j++], *e);
        }
        Push(S, argv[i]);
      }
    } else if (strcmp(argv[i], "*") == 0 || strcmp(argv[i], "/") == 0) {
      if (!S->top || strcmp(S->top->data, "-") == 0 || strcmp(S->top->data, "+") == 0
        || strcmp(S->top->data, "(") == 0) {
        Push(S, argv[i]);
      } else {
        while (Pop(S,e)){
          postfix[j] = (char *) malloc((strlen(*e) + 1) * sizeof(char));
          strcpy(postfix[j++], *e);
        }
        Push(S, argv[i]);
      }
    } else if (strcmp(argv[i], ")") == 0) {
      while (Pop(S,e) && strcmp(*e, "(") != 0) {
         postfix[j] = (char *) malloc((strlen(*e) + 1) * sizeof(char));
         strcpy(postfix[j++], *e);
      }
    } else if (strcmp(argv[i], "(") == 0) {
      Push(S, argv[i]);
    } else {
       postfix[j] = (char *) malloc((strlen(argv[i]) + 1) * sizeof(char));               
       strcpy(postfix[j++], argv[i]);
    }
  }
  while (Pop(S,e)) {
    postfix[j] = (char *) malloc((strlen(*e) + 1) * sizeof(char));
    strcpy(postfix[j++], *e);
  }
  return j;
}
