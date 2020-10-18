
#ifndef NTYPE_H
#define NTYPE_H
#include "ItemType.h"

struct NodeType
{
    ItemType data;
    NodeType *next;
    // NodeType *back;
};

#endif