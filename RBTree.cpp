//
// Created by User on 08.06.2020.
//

#include "RBTree.h"

template <class T>
treeNode<T>* nil;

template <class T>
treeNode<T>::treeNode(T* key) {
    this->left = nullptr;
    this->right = nullptr;
    this->color = "black";
    this->key = key;
    this->size = 0;
    this->prev = nullptr;
}

template <class T>
void treeNode<T>::print() {
    std::cout<<this->key->name<<"("<<this->color<<")"<<std::endl;
}

template <class T>
RBTree<T>::RBTree()
{
    this->root=nil<T>;
}

template <class T>
void RBTree<T>::LeftRotate(treeNode<T>* x) {
    treeNode<T>* y=x->right;
    x->right=y->left;

    if (y->left!=nil<T>)
        y->left->prev=x;
    y->prev=x->prev;
    if(x->prev==nil<T>)
        this->root=y;
    else if(x==x->prev->left)
        x->prev->left=y;
    else
        x->prev->right=y;
    y->left=x;
    x->prev=y;
}

template <class T>
void RBTree<T>::RightRotate(treeNode<T> *x) {
    treeNode<T>* y=x->left;
    x->left=y->right;

    if (y->right!=nil<T>)
        y->right->prev=x;
    y->prev=x->prev;
    if(x->prev==nil<T>)
        this->root=y;
    else if(x==x->prev->right)
        x->prev->right=y;
    else
        x->prev->left=y;
    y->right=x;
    x->prev=y;
}

template <class T>
void RBTree<T>::add(treeNode<T>* z) {
    treeNode<T>* y=nil<T>;
    treeNode<T>* x=this->root;
    while(x!=nil<T>)
    {
        y=x;
        if (z->key->count<x->key->count)
            x=x->left;
        else
            x=x->right;
    }
    z->prev=y;
    if (y==nil<T>)
        this->root=z;
    else if (z->key->count<y->key->count)
        y->left=z;
    else
        y->right=z;
    z->left=nil<T>;
    z->right=nil<T>;
    z->color="red";
    y=z;
    while(y!=nil<T>)
    {
        y->size++;
        y=y->prev;
    }
    this->AddFix(z);
    SizeFix();
}

template <class T>
void RBTree<T>::AddFix(treeNode<T> *z) {
    treeNode<T>* y;
    while(z->prev->color=="red")
        if(z->prev==z->prev->prev->left)
        {
            y=z->prev->prev->right;
            if(y->color=="red")
            {
                z->prev->color="black";
                y->color="black";
                z->prev->prev->color="red";
                z=z->prev->prev;
            }
            else if(z==z->prev->right)
            {
                z=z->prev;
                LeftRotate(z);
            }
            else
            {
                z->prev->color="black";
                z->prev->prev->color="red";
                RightRotate(z->prev->prev);
            }
        }
        else
        {
            y=z->prev->prev->left;
            if(y->color=="red")
            {
                z->prev->color="black";
                y->color="black";
                z->prev->prev->color="red";
                z=z->prev->prev;
            }
            else if(z==z->prev->left)
            {
                z=z->prev;
                RightRotate(z);
            }
            else
            {
                z->prev->color="black";
                z->prev->prev->color="red";
                LeftRotate(z->prev->prev);
            }
        }
    this->root->color="black";
}

template <class T>
void RBTree<T>::print() {
    this->show_tree_graph_aux(this->root,0);
}

template <class T>
void RBTree<T>::Transplant(treeNode<T> *u, treeNode<T> *v) {
    if(u->prev==nil<T>)
        this->root=v;
    else if(u==u->prev->left)
        u->prev->left=v;
    else
        u->prev->right=v;
    v->prev=u->prev;
}

template <class T>
void RBTree<T>::Remove(treeNode<T> *z) {
    treeNode<T>* y=z;
    treeNode<T>* x;
    std::string color=y->color;
    if(z->left==nil<T>)
    {
        x=z->right;
        Transplant(z,z->right);
    }
    else if(z->right==nil<T>)
    {
        x=z->left;
        Transplant(z,z->left);
    }
    else
    {
        y=TreeMin(z->right);
        color=y->color;
        x=y->right;
        if(y->prev==z)
            x->prev=y;
        else
        {
            Transplant(y,y->right);
            y->right=z->right;
            y->right->prev=y;
        }
        Transplant(z,y);
        y->left=z->left;
        y->left->prev=y;
        y->color=z->color;
    }
    if(color=="black")
        RemoveFix(x);
    SizeFix();
}

template <class T>
void RBTree<T>::show_tree_graph_aux(treeNode<T> *start, int space){
    if (start == nil<T>)
        return;
    space = space + 10;
    show_tree_graph_aux(start->right,space);
    std::cout << std::endl;
    for (int i = 10-1; i < space; i++)
        std::cout << " ";
    std::cout << start->key->name <<'(' << start->size << ')' << "\n";
    show_tree_graph_aux(start->left, space);
}

template <class T>
void RBTree<T>::RemoveFix(treeNode<T> *x) {
    treeNode<T>* y;
    while(x!=this->root && x->color=="black")
    {
        if(x==x->prev->left)
        {
            y=x->prev->right;
            if(y->color=="red")
            {
                y->color="black";
                x->prev->color="red";
                LeftRotate(x->prev);
                y=x->prev->right;
            }
            if(y->left->color=="black" && y->right->color=="black")
            {
                y->color="red";
                x=x->prev;
            }
            else if(y->right->color=="black")
            {
                y->left->color="black";
                y->color="red";
                RightRotate(y);
                y=x->prev->right;
            }
            else
            {
                y->color=x->prev->color;
                x->prev->color="black";
                y->right->color="black";
                LeftRotate(x->prev);
                x=this->root;
            }
        }
        else
        {
            y=x->prev->left;
            if(y->color=="red")
            {
                y->color="black";
                x->prev->color="red";
                RightRotate(x->prev);
                y=x->prev->left;
            }
            if(y->right->color=="black" && y->left->color=="black")
            {
                y->color="red";
                x=x->prev;
            }
            else if(y->left->color=="black")
            {
                y->right->color="black";
                y->color="red";
                LeftRotate(y);
                y=x->prev->left;
            }
            else
            {
                y->color=x->prev->color;
                x->prev->color="black";
                y->left->color="black";
                RightRotate(x->prev);
                x=this->root;
            }
        }

    }
    x->color="black";
}

template <class T>
treeNode<T> *RBTree<T>::TreeMin(treeNode<T> *x) {
    while(x->left!=nil<T>)
        x=x->left;
    return x;
}

template <class T>
T* RBTree<T>::get_Server_by_serverID(std::string name) {
    return nullptr;
}

template <>
Server* RBTree<Server>::get_Server_by_serverID(std::string name) {
    treeNode<Server>* x=this->root;
    return SearchName(x,name);
}

template <class T>
T* RBTree<T> :: SearchName(treeNode<T> *x, std::string name) {
    if(x==nil<T>)
        return nullptr;
    if(x->key->get_serverID()==name)
        return x->key;
    if(x->left==nil<T> && x->right==nil<T>)
        return nullptr;

    T* l=SearchName(x->left,name);
    T* r=SearchName(x->right,name);
    if(l== nullptr)
        return r;
    else
        return l;
}

template <class T>
void RBTree<T>::SizeFix() {
    treeNode<T>* x=this->root;
    SizeFixFromRoot(x);
}

template <class T>
void RBTree<T>::SizeFixFromRoot(treeNode<T> *x) {
    if(x==nil<T>)
        return;
    if(x->left!=nil<T>)
        SizeFixFromRoot(x->left);
    if(x->right!=nil<T>)
        SizeFixFromRoot(x->right);
    x->size=x->left->size+x->right->size+1;
}

template <class T>
treeNode<T> *RBTree<T>::SearchElement(int rank) {
    if(rank>=1 && rank<=this->root->size)
        return SearchByRank(this->root,rank);
    else
        return nil<T>;
}

template <class T>
treeNode<T> *RBTree<T>::SearchByRank(treeNode<T> *x, int rank) {
    int r=x->left->size+1;
    if(rank==r)
        return x;
    else if(rank<r)
        return SearchByRank(x->left,rank);
    else
        return SearchByRank(x->right,rank-r);
}

template <class T>
int RBTree<T>::SearchRank(std::string name) {
    treeNode<T>* x=get_Server_by_serverID(name);
    int r=x->left->size+1;
    while(x!=this->root)
    {
        if(x==x->prev->right)
            r+=x->prev->left->size+1;
        x=x->prev;
    }
    return r;
}