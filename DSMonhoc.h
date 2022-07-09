#ifndef DSMH
#define DSMH

#include <math.h>
#include <stdio.h>

struct Monhoc{
	int MaMH;
	char TenMH[50];
	char DScauhoithi[200];
};
struct Node{
	Monhoc data;
	Node * left;
	Node * right;
};
void printtree(Node *);
Node * creatNode(Monhoc);
Node * insertMonhoc(Node * &, Monhoc);
Node * deleteMonhoc(Node *, int);
Node * getNode(Node * , int key);
int countMonhoc=0;

Node * creatNode (Monhoc x)
{
	Node *p= new Node;
	p->data=x;
	p->left=NULL;
	p->right=NULL;
	return p;
}
Node * insertMonhoc(Node * & root, Monhoc x)
{
	if (root = NULL)
	{
		root = creatNode(x);
		return root;
	}
	if (root->data.MaMH > x.MaMH)
	{
		root->left=insertMonhoc(root->left,x);
	}
	else 
	if (root->data.MaMH < x.MaMH)
	{
		root->right=insertMonhoc(root->right,x);
	}
	return root;
}
Node * getMinNode(Node * root)
{
	Node * c=root;
	while (c!=NULL && c->left!=NULL)
		c=c->left;
	return c;
}
Node * deleteMonhoc(Node * root, int MaMH)
{
	if (root==NULL) return NULL;
	if (root->data.MaMH > MaMH)
		root->left=deleteMonhoc(root->left, MaMH);
	else 
	if (MaMH > root -> data.MaMH)
		root->right = deleteMonhoc(root->right,MaMH);
	else
	{
		if (root->left==NULL)
		{
			Node * r=root->right;
			delete root;
			return r;
		}
		else if (root->right=NULL)
		{
			Node * r=root->right;
			delete root;
			return r;
		}
		
		Node * t=getMinNode(root->right);
		root->data=t->data;
		root->right=deleteMonhoc(root->right, t->data.MaMH);
	}
	return root;
}
Node * getNode(Node * root, int key)
{
	Node * p=root;
	while (p!=NULL)
	{
		if (p->data.MaMH==key)
			return p;
		if (p->data.MaMH>key)
			p=p->left;
		else p=p->right;
	}
	return p;
}
void printtree(Node * root)
{
	if (root==NULL)
		return;
	printf("%d %s %d %s %d\n",root->data.MaMH, root->data.TenMH, root->data.DScauhoithi);
	printtree(root->left);
	printtree(root->right);
}
Node * getNode (Node * root, char * MaMH, char * TenMH, char * DScauhoithi)
{
	if (root==NULL)
	return NULL;
	if (root->data.MaMH==MaMH && root TenMH==TenMH && root DScauhoithi==DScauhoithi)
	{
		return root;
		
	}
	Node * p1=getNode(root->left,MaMH,TenMH,DScauhoithi);
	if (p1!=NULL)
	{
		return p1;
	}
	return getNode(root->right,MaMH,TenMH,DScauhoithi);
}
#endif