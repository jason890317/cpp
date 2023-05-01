#ifndef BTREE_H
#define BTREE_H
#include<iostream>
#include<string>
#include"queue.h"
using namespace std;
template <class T ,class M>
class node
{
    
    public:
        T item;
        M tar;
        node<T,M> *right;
        node<T,M> *left;
        node<T,M>():item(0),tar(0),right(NULL),left(NULL){};
        node<T,M>(T it,M ta, node<T,M> *r, node<T,M> *l):item(it),tar(ta),right(r),left(l){};
        T val()  
        {
            return item;
        }
        void val(T it)
        {
            item=it;
        }
};

template <class T ,class M>
class tree : public node<T,M>
{
    public:
        node<T,M> *root;
        tree():root(NULL){};
        tree(node<T,M> *it):root(it){};
        void add_right(node<T,M> *it)
        {
            root->right=it;
        }
        void add_left(node<T,M> *it)
        {
            root->left=it;
        }
        string inorder(node<T,M> *cur)
        {
            static string result="";
            if(cur!=NULL)
            {
                
                
                preorder(cur->left);
                if(cur->val()!=0)
                {
                    result+=to_string((int)cur->val());
                    result+=" ";
                }
                preorder(cur->right);
            }
            return result;
        }
        void add(T a,M b)
        {
            node<T,M> *p=root;
            node<T,M> *pp=NULL;
            node<T,M> *q=NULL;
            while(p!=NULL)
            {
                pp=p;
                
                if(a<p->item)
                {
                    p=p->left;
                }
                else if(a>=p->item) 
                {
                    p=p->right;
                }
                
            }
            
            q=new node<T,M>(a,b,0,0);
            if(root!=NULL)
            {
                if(a<pp->item)
                {
                    pp->left=q;
                }
                else
                {
                    pp->right=q;
                }
            }
            else
            {
                root=q;
            }
            
        }

        node<T,M> *search(T a)
        {
            return search(root, a);
        }
        
        node<T,M> *search(node<T,M>*p, T a)
        {
            if(!p)
            {
                return 0;
            }
            if(a< p->item)
            {
                return search(p->left, a);
            }
            if(a> p->item)
            {
                return search(p->right, a);
            }
            return p;
        }
};


#endif