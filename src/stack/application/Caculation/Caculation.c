#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "DataBase.h"

void main(int argc, char *argv[])
{
  int i, j = 0;
  char *postfix[100];
  char **e;
  LinkStack *S = (LinkStack *)malloc(sizeof(LinkStack));
  Init(S);
  
  for (i = 1; i < argc; i++){
    if (strcmp(argv[i], "+") == 0) {
      if (!S->top) {
        Push(S, argv[i]);
	  } else {
		Pop(S, e); 
		postfix[j] = (char *) malloc((strlen(*e) + 1) * sizeof(char));
		strcpy(postfix[j++], *e);
	  }
	} else if (strcmp(argv[i], "-") == 0){
	  Push(S, argv[i]);
	} else if (strcmp(argv[i], "*") == 0){
		
	} else if (strcmp(argv[i], "/") == 0){
		
    } else if(strcmp(argv[i], "(") == 0){
	  Push(S, argv[i]);
    } else if(strcmp(argv[i], ")") == 0){
	  do{
		  Pop(S, e);
		  postfix[j] = (char *) malloc((strlen(*e) + 1) * sizeof(char));
		strcpy(postfix[j++], *e);
	  }while(strcmp(*e, "(") != 0);
    } else {
		postfix[j] = (char *) malloc((strlen(argv[i]) + 1) * sizeof(char));
		strcpy(postfix[j++], argv[i]);
	}
  }
  
  for (i = 0;  i< j; i++) {
	  printf("%s\n", postfix[i]);
  }
}