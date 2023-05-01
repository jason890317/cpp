#ifndef LIST_H
#define LIST_H
#include<iostream>
#include<string>
using namespace std;
template <class T>
class node
{
    public:
        node<T>(T it):item(it),next(0){};
        node<T>():item(0),next(0){};
        T item;
        node<T> *next;
   
};

template <class T>
class list : public node<T>
{
    public:
        node<T> *root;
        list<T>(node<T> *it):root(it){};
        list<T>():root(0){};
        void add_node(T it)
        {
            node<T> *n=new node<T>(it);
            node<T> *cur=root;
            if(cur==NULL)
            {
                root=n;
            }
            else
            {
                while(cur->next!=NULL)
                {
                    cur=cur->next;
                }
                cur->next=n;
            }
            
        }

        void del(int tar)
        {
            node<T> *cur=root;
            if(cur!=NULL)
            {
                for(int i=0;i<tar-1;i++)
                {
                    cur=cur->next;
                }
                cur->next=cur->next->next;
            }
        }

        void show()
        {
            node<T> *cur=root;
            while(cur!=NULL)
            {
                cout<<cur->item<<" ";
                cur=cur->next;
            }
        }

        int size()
        {
            int num=0;
            for(node<T> *cur=root;cur!=NULL;cur=cur->next)
            {
                num++;
            }
            return num;
        }

        node<T>* cut(int tar,int num)//from tar to tar+num
        {
            node<T> *cur=root;
            node<T> *q=root;
            node<T> *p=root;
            int si =this->size();
            if(root == NULL)
            {
                return cur;
            }

            if(tar == 0 && num != si)
            {
                
                for(int i=0;i<num-1;i++)
                {
                    p=p->next;
                }
                root=p->next;
                p->next=NULL;

                return cur;
            }
            if(tar == 0 && num == si)
            {
                
                root=NULL;
                return cur;
            }
            
            if(tar + num ==si)
            {
                for(int i=0;i<tar-1;i++)
                {
                    q=q->next;
                }
                p=q->next;
                q->next=NULL;
                
                return p;
            }

            if(tar!=0 && tar + num < si)
            {
                
                for(int i=0;i<tar-1;i++)
                {
                    q=q->next;
                }

                for(int i=0;i<tar+num-1;i++)
                {
                    p=p->next;
                }

                cur=q->next;

                q->next=p->next;
                p->next=NULL;

                return cur;
            }
            return cur;
        }

        void paste(int tar, node<T> *it)//after tar
        {
            node<T> *cur=root;
            node<T> *p=root;
            int si =this->size();
            if(cur == NULL )
            {
                root =it;
            };
            if(tar == -1 && cur != NULL)
            {
                cur=it;
                while(cur->next!=NULL)
                {
                    cur=cur->next;
                }
                cur->next=root;
                root=it;
            }
            if(tar == si-1 && cur != NULL)
            {
                while(cur->next!=NULL)
                {
                    cur=cur->next;
                }
                cur->next=it;
            }
            if(tar != -1 && tar < si-1 && cur != NULL)
            {
                cur=it;
                while(cur->next!=NULL)
                {
                    cur=cur->next;
                }
                for(int i=0;i<tar;i++)
                {
                    p=p->next;
                }

                cur->next=p->next;
                p->next=it;
            
            }
        }

        void inverse()
        {
            node<T> *p=root, *q=NULL, *r=NULL;
            while(p!=NULL)
            {
                r=q;
                q=p;
                p=p->next;
                q->next=r;
            }
            root=q;
        }

        void swap(int a,int b)
        {
            node<T> *a_1=root,*a_2=root;
            int temp_num;
            T temp_item;
            for(int i=0;i<a;i++)
            {   
                a_1=a_1->next;
            }
            for(int i=0;i<b;i++)
            {   
                a_2=a_2->next;
            }
            temp_item=a_1->item;
        
            a_1->item=a_2->item;
        
            a_2->item=temp_item;
        
        }
        void sort()
        {
            node<T> *h=root;
            node<T> *p=h;
            int max;
            int size =this->size();
            max=root->item;
            for(int i=0;i<size-1;i++)
            {
                p=h;
                max=h->item;
                
                for(int j=i;j<size;j++)
                {
                    if(p->item>max)
                    {
                        max=p->item;
                        swap(i,j);
                    }
                    p=p->next;
                }
                                
                h=h->next;
            }
            
            
        }

        int find_max() //return 0~n-1
        {
            node<T> *p=root;
            int max=root->item;
            int count=0;
            int tar=0;
            while(p!=NULL)
            {
                if(p->item>max)
                {
                    max=p->item;
                    tar=count;
                }
                count++;
                p=p->next;
            }
            
            return tar;
        }

        node<T>* node_no(int a)
        {
            node<T> *cur=root;
            if(a<this->size())
            {
                for(int i=0;i<a;i++)
                {
                    cur=cur->next;
                }
            }
            
            return cur;
        }
};


#endif