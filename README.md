# C（数据结构）
---

## 数据结构和算法的基础概念
数据的逻辑结构：

- 集合
- 线性
- 树形
- 图形

数据元素的存储结构：

- 顺序存储
- 链式存储

算法三要素：

- 有穷性
- 确定性
- 可行性

渐进增长：
> 函数的渐进增长：给定两个函数f(n)和g(n)，如果存在一个整数N，使得对于所有n>N，f(n)总是比g(n)大，我们说f(n)的增长渐进快于g(n)。

时间复杂度：
> T(n) = O(f(n))
> O(1) < O(logn) < O(n) < O(nlogn) < O(n^2) < O(n^3) < O(2^n) < O(n!) < O(n^n)
> 基本不考虑O(n^3)以上的算法
> **时间复杂度一般都是值最坏复杂度** 

算法的空间复杂图：
> S(n) = O(f(n))

## 基础数据结构

### 线性表(list)

- 零个或多个数据元素的优先序列。  
- 若将线性表记为(a1, ..., ai-1, ai, ai+1, ..., an),则表中ai-1领先于ai,ai领先于ai+1,称ai-1是ai的直接前驱元素，ai+1是ai的直接后继元素。
- 线性表元素的个数为n(n为自然数)定义为线性表的长度，当n=0时，称为空表。

Operation:

- InitList(*L)
- ListEmpty(L)
- ClearList(*L)
- GetElem(L, i, *e)
- LocateElem(L, e)
- ListInsert(*L, i, e)
- ListDelete(*L, i, *e)
- ListLength(L)

**我们通常把具有存取时间性能为O(1)的存储结构称为随机存储结构**

线性表顺序存储结构  
优点：

- 无需为存储逻辑有新的存储开销
- 可以快速地存取表中任意位置

缺点：

- 插入和删除时，开销较大
- 容量变大时，不易确定存储容量
- 造成存储空间碎片

**若线性表需要频繁查找，很少插入和删除，宜采用顺序存储结构。反之采用单链表结构**
**用数组描述的链表叫做静态链表**

### 栈（stack）

- 是限定仅在表尾进行插入和删除操作的线性表
- 我们把允许插入和删除的一端称为栈顶(top)，另一端称为栈底(bottom),不含任何数据元素的栈称为空栈。栈又称为后进先出(Last In First Out)的线性表，简称LIFO结构
- 栈的插入操作，叫做进栈，也称压栈、入栈
- 栈的删除操作，叫做出栈，也有的叫做弹栈

> 如果栈的使用过程中元素变化不可预料，有时很小，有时非常大，那么最好是用链栈，反之，如果它的变化在可控范围内，建议使用顺序栈会更好一些。

- 一种不需要括号的后缀表达法，我们也把它称为逆波兰(Reverse Polish Notation, RPN)
- 标准四则运算表达式叫做中缀表达式

### 队列（queue）
- 是只允许在一端进行插入操作，而在另一端进行删除操作的线性表
- 队列是一种先进先出(First In First Out)的线性表，简称FIFO。允许插入的一端称为队尾，允许删除的一端称为队头。
- 我们把队列的这种头尾相接的顺序存储结构称为循环队列
- 队列的链式存储结构，即线性表的单链表并只能尾进头出。简称为链队列