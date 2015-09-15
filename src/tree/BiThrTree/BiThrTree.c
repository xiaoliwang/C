BiThrTree pre;

void InThreading(BiThrTree p)
{
  if (p) {
    InThreading(p->lchild);
    if (!p->lchild) {
      p->LTag = Thread;
      p->lchild = pre;
    }
    if (!p->rchild) {
      pre->RTag = Thread;
      pre->rchild = p;
    }
    pre = p;
    InThreading(p->rchild);
  }
}

void InOrderTraverse_Thr(BiThrTree T)
{
  BiThrTree p;
  p = T->lchild;
  while (p != T) {
    while (p->LTage == Link)
      p = p->lchild;
    printf("%c", p->data);
    while (p->RTag == Thread && p->rchild != T) {
      p = p->rchild;
      printf("%c", p->data);
    }
    p = p->rchild;
  }
  return OK;
}