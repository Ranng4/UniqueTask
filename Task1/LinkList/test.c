//
// Created by Lenovo on 25-4-8.
//
#include"Link.h"


int main()
{
    unidirectionalNode* List = unidirectionalInit();
    unidirectionalTailerInsert(List,1);
    unidirectionalTailerInsert(List,2);
    unidirectionalTailerInsert(List,3);
    unidirectionalTailerInsert(List,4);
    unidirectionalTailerInsert(List,5);
    unidirectionalTailerInsert(List,6);
    unidirectionalDeleByVal(List,3);
    unidirectionalPrint(List);
    return 0;

}
