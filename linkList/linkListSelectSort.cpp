#include <stdio.h>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

typedef int Status; /*  Status */
typedef int ElemType; /*  ElemType类型根据实际情况而顶，这里假设为int */

typedef	struct Node
{
    ElemType data;
    struct Node* next;
}
