#ifndef TREE_H
#define TREE_H
#include<iostream>
#include<string>
#include"queue.h"
using namespace std;
template <class T>
class node
{
    public:
        T item;
        node<T> *right;
        node<T> *left;
        node<T>():item(0),right(NULL),left(NULL){};
        node<T>(T it, node<T> *r, node<T> *l):item(it),right(r),left(l){};
        T val()  
        {
            return item;
        }
        void val(T it)
        {
            item=it;
        }
};

template <class T>
class tree : public node<T>
{
    public:
        node<T> *root;
        tree():root(NULL){};
        tree(node<T> *it):root(it){};
        void add_right(node<T> *it)
        {
            root->right=it;
        }
        void add_left(node<T> *it)
        {
            root->left=it;
        }
        string preorder(node<T> *cur)
        {
            static string result="";
            if(cur!=NULL)
            {
                if(cur->val()!=0)
                {
                    result+=to_string((int)cur->val());
                    result+=" ";
                }
                
                preorder(cur->left);
                preorder(cur->right);
            }
            return result;
        }
        void add(T a)
        {
            node<T> *n= new node<T>(a,0,0);
            
            if(root==NULL)
            {
                root=n;
            }
            else
            {
                queue<node<T>*> qu;
                node<T> *no;
                qu.push_back(root);
                while(true) 
                {  
                    no = qu.pop_front();  
                    if(no->left != NULL && no->right != NULL) 
                    {  
                        qu.push_back(no->left);  
                        qu.push_back(no->right);  
                    }  
                    else 
                    {  
                        if(no->left == NULL) 
                        {  
                            no->left = n;  
                            qu.push_back(no->left);  
                        }  
                        else 
                        {  
                            no->right = n;  
                            qu.push_back(no->right);  
                        }  
                        break;  
                    }  
                }
            }
        }

        
};


#endif