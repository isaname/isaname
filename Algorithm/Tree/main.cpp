#include"BinTree.h"
using namespace std;
template<typename E>
bool fuckyou(BinNode<E>* Root1, BinNode<E>* Root2)
{
    
    if (Root1==NULL || Root2==NULL) return false;
    if (Root1->getValue() == Root2->getValue())
        return fuckfuck(Root1, Root2);
    else
        return fuckyou(Root1->left(), Root2) || fuckyou(Root1->right(), Root2);
}
template<typename E>
bool fuckfuck(BinNode<E>* root1, BinNode<E>* root2)
{
    if (root1==NULL && root2==NULL) return true;
    if (root1==NULL || root2==NULL) return false;
    if (root1->getValue() != root2->getValue())
        return false;
    else
        return fuckfuck(root1->left(),root2->left()) && fuckfuck(root1->right(),root2->right());
}
template<typename  E>
BinNode<E>*  creatBinaryTree(string  s[],  int  &x,int  n)//构建二叉树的主函数，根据先序遍历，采用递归思想构建
{
        if  (s[x]  =="#")
                return  NULL;
        else
        {
                BinNode<E>*node  =  new  BinNode<E>(s[x]);
                x  =  x  +  1;
                if  (x  <  n);
                node->setLeft(creatBinaryTree<E>(s,  x,n));
                x  =  x  +  1;
                if  (x  <  n);
                node->setRight(creatBinaryTree<E>(s,  x,n));
                return  node;
        }
}
template<typename E>
BinNode<E>* fuck(string s,int *x,int n){
    if  (s[*x]  =='#')
                return  NULL;
        else
        {
                BinNode<E>*node  =  new  BinNode<E>(s[*x]);
                *x  =  *x  +  1;
                //cout<<x<<endl;
                if  (*x  <  n);
                node->setLeft(fuck<E>(s, x,n));
                *x  =  *x  +  1;
                if  (*x  <  n);
                node->setRight(fuck<E>(s,  x,n));
                return  node;
        }
}

int main(){
    // BinTree<string>*BT1  =  new  BinTree<string>;
    // creatBinaryTree(BT1);
    // string  strfind1;
    // cin>>strfind1;
    // BinTree<string>*BT2  =  new  BinTree<string>;
    // creatBinaryTree(BT2);
    // string  strfind2;
    // cin>>strfind2;
    // if(HasSubTree(BT1->getRoot(),BT2->getRoot())){
    //     cout<<"yes"<<endl;
    // }else cout<<"no"<<endl;
    string a;
    cin>>a;
    string b;
    cin>>b;
    //CGH#### ABD##E##CGH###F##
    int i=0;
    int s=0;
    BinNode<char> *aa=fuck<char>(a,&i,a.size());
    BinNode<char> *bb=fuck<char>(b,&s,b.size());
    if(fuckyou(aa,bb)){
        cout<<"yes"<<endl;
    }else cout<<"no"<<endl;
}