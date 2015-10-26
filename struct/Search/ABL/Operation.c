#include <stdio.h>
#include <stdlib.h>
#include "BaseData.h"

void R_Rotate(BiTree *P)
{
  BiTree L;
  L = (*P)->lchild;
  (*P)->lchild = L->rchild;
  L->rchild = (*P);
  *P = L;
}

void L_Rotate(BiTree *P)
{
  BiTree R;
  R = (*P)->rchild;
  (*P)->rchild = R->lchild;
  R->lchild = (*P);
  *P = R;
}

void LeftBalance(BiTree *T)
{
  BiTree L, Lr;
  L = (*T)->lchild;
  switch(L->bf) {
    case LH:
      (*T)->bf = L->bf = EH;
      R_Rotate(T);
      break;
    case RH:
      Lr = L->rchild;
      switch(Lr->bf) {
        case LH:
          (*T)->bf = RH;
          L->bf = EH;
          break;
        case EH: 
          (*T)->bf = L->bf = EH;
          break;
        case RH:
          (*T)->bf = EH;
          L->bf = LH;
          break;
      }
      Lr->bf = EH;
      L_Rotate(&L);
      R_Rotate(T);
  }
}

void RightBalance(BiTree *T)
{
  BiTree R, Rl;
  R = (*T)->rchild;
  switch (R->bf) {
    case RH:
      (*T)->bf = R->bf = EH;
      L_Rotate(T);
      break;
    case LH:
      Rl = R->lchild;
      switch (Rl->bf) {
        case LH:
          (*T)->bf = RH;
          R->bf = EH;
          break;
        case EH:
          (*T)->bf = R->bf = EH;
          break;
        case RH:
          (*T)->bf = LH;
          R->bf = EH;
          break;
      }
      Rl->bf = EH;
      R_Rotate(&R);
      L_Rotate(T);
  }
}

Status InsertAVL(BiTree *T, int e, Status *taller)
{
  if (*T) {
    if (e == (*T)->data) {
      *taller = FALSE;
      return FALSE;
    }
    if (e < (*T)->data) {
      if (!InsertAVL(&(*T)->lchild, e, taller))
        return FALSE;
      if (*taller) {
        switch((*T)->bf) {
          case LH:
            LeftBalance(T);
            *taller = FALSE;
            break;
          case EH:
            (*T)->bf = LH;
            *taller = TRUE;
            break;
          case RH:
            (*T)->bf = EH;
            *taller = FALSE;
            break;
        }
      }
    } else {
      if (!InsertAVL(&(*T)->rchild, e, taller))
        return FALSE;
      if (*taller) {
        switch ((*T)->bf) {
          case LH:
            (*T)->bf = EH;
            *taller = FALSE;
            break;
          case EH:
            (*T)->bf = RH;
            *taller = TRUE;
            break;
          case RH:
            RightBalance(T);
            *taller = FALSE;
            break;
        }
      }
    }
  } else {
    *T = (BiTree) malloc(sizeof(BiTNode));
    (*T)->data = e;
    (*T)->lchild = (*T)->rchild = NULL;
    (*T)->bf = EH;
    *taller = TRUE;
  }
  return TRUE;
}

void Print_Tree(BiTree* T)
{
  if (!(*T))
    return;
  Print_Tree(&(*T)->lchild);
  printf("%d, ", (*T)->data);
  Print_Tree(&(*T)->rchild);
}