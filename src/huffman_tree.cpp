#include <iostream>
#include <vector>
#include <cstring>
#include <cassert>
using namespace std;

struct Node
{
	bool tag;
	double weight;
	char c;
	string code;
	Node *lchild,*rchild;
	Node()
	{
		tag=true;
        lchild=NULL;
		rchild=NULL;
		weight=1.0;
		c='#';
		code="";
	}		
};
vector<Node> initialize(vector<char> &l,vector<double> &w)
{
	assert(l.size()==w.size());
	vector<Node> list(l.size()*2-1);
    for(int k=0;k<l.size();k++)
	{
		list[k].c=l[k];
		list[k].weight=w[k];
	}
	return list;
}
int find_min(int left,int right,vector<Node> &list)
{
	int min=list.size()-1;
	for(int k=left;k<=right;k++)
	{
		if(list[k].weight<list[min].weight&&list[k].tag)  min=k;
	}
	list[min].tag=false;
	return min;
}		
void huffman_tree(vector<Node> &list)
{
	const int n=(list.size()+1)/2;
	for(int k=n;k<list.size();k++)
	{
		int first=find_min(0,k-1,list);
		int second=find_min(0,k-1,list);
		list[k].lchild=&(list[first]);
		list[k].rchild=&(list[second]);
		list[k].weight=list[first].weight+list[second].weight;
	}
	list[list.size()-1].weight=1.0;
}
void encode(Node *p)
{
	if(p->lchild&&p->rchild)
	{
		p->lchild->code=p->code+"0";
		p->rchild->code=p->code+"1";
		encode(p->lchild);
		encode(p->rchild);
	}
}
void huffman_tree_encode(vector<Node> &list)
{
	Node *root=&(list[list.size()-1]);
    encode(root);
}
void visit(Node *p)
{
	cout<<p->c<<':'<<p->code<<endl;
}
void preordertraverse(Node *p)
{
	if(p)
	{
		if(p->c!='#')  visit(p);
		preordertraverse(p->lchild);
		preordertraverse(p->rchild);
	}		
}
void inordertraverse(Node *p)
{
	if(p)
	{
		inordertraverse(p->lchild);
		if(p->c!='#')  visit(p);
        inordertraverse(p->rchild);
	}		
}
void postordertraverse(Node *p)
{
	if(p)
	{
		postordertraverse(p->lchild);
		postordertraverse(p->rchild);
        if(p->c!='#')  visit(p);
	}		
}
void huffman_tree_traverse(vector<Node> &list)
{
	Node *root=&(list[list.size()-1]);
	int mode;
	cout<<"Input the mode:";
	cin>>mode;
	if(mode==0)  preordertraverse(root);
	else if(mode==1)  inordertraverse(root);
	else  postordertraverse(root);
}
double wpl(vector<Node> &list)
{
	double sum=0.0;
	for(int k=0;k<list.size();k++)
	{
		if(list[k].c!='#')  sum+=list[k].weight*list[k].code.size();
	}
	return sum;
}

int main()
{
	const double h=0.01;
	vector<double> w={8.167*h,1.492*h,2.782*h,4.253*h,12.702*h,2.228*h,2.015*h,6.094*h,6.966*h,0.153*h,0.772*h,4.025*h,2.406*h,6.749*h,7.507*h,1.929*h,0.095*h,5.987*h,6.327*h,9.056*h,2.758*h,0.978*h,2.360*h,0.150*h,1.974*h,0.074*h};
    vector<char> l={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    vector<Node> list=initialize(l,w);
	huffman_tree(list);
    huffman_tree_encode(list);
	huffman_tree_traverse(list);
	cout<<"---------------------------------"<<endl;
	cout<<wpl(list)<<endl;
    return 0;
}	
