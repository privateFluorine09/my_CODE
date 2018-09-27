#ifndef TREE_H_INCLUDED
#define TREE_H_INCLUDED

typedef struct trnode{
    int data;
    struct trnode *left;
    struct trnode *right;
}Trnode;

typedef struct tree{
    unsigned Tree_size;
    Trnode *root;
}Tree;

Tree Tree_insert(Tree tree, int key)
{
    Trnode *new_Node;
    new_Node=(Trnode*)malloc(sizeof(Trnode));
    new_Node->data=key;
    new_Node->left=NULL;
    new_Node->right=NULL;

    Trnode *prev, *current;
    current=tree.root;
    prev=NULL;

    while(current!=NULL)
    {
        prev=current;
        if(key<current->data)
            current=current->left;
        else
            current=current->right;
    }

    if(prev==NULL)
        tree.root=new_Node;
    else if (key<prev->data)
        prev->left=new_Node;

         else
            prev->right=new_Node;

    return tree;
}

#endif // TREE_H_INCLUDED
