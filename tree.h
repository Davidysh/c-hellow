#include<iostream>
#include<queue>
#include<stack>
#define datatype int

typedef struct TreeNode
{
    datatype data;
    TreeNode *left,*right;
}TreeNode,Tree*;


void PreOrder(Tree bt) {//  DLR 先序遍历
    if(bt == nullptr)
        return;
    else{
        std::cout<<bt->data;
        PreOrder(bt->left);
        PreOrder(bt->right);
    }
}

void InOrder(Tree bt) {// LDR 中序遍历
    if(bt == nullptr)
        return;
    else{
        InOrder(bt->left);
        std::cout<<bt->data;
        InOrder(bt->right);
    }
}

void PostOrder(Tree bt) {// LRD 中序遍历
    if(bt == nullptr)
        return;
    else{
        PostOrder(bt->left);
        PostOrder(bt->right);
        std::cout<<bt->data;
    }
} 

void LevelOrder(Tree bt){ // 层序遍历
    if(bt == nullptr)
        return;
    std::queue<datatype> Q;
    TreeNode *p = bt;
    Q.push(p);
    while(!Q.empty()){
        p = Q.top();
        Q.pop();
        std::cout<<p->data;
        if(p->left) Q.push(p->left);
        if(p->right) Q.push(p->right);
    }
}

void CreatBiTree(Tree bt){
    datatype a;
    std::cin>>a;
    if(a == '#') bt = nullptr;
    else {
        bt == new TreeNode;
        bt->data = a;
        CreatBiTree(bt->left);
        CreatBiTree(bt->right);
    }
}

void NRPreorder(Tree bt){ //非递归算法的Preorder
    if(bt == nullptr)
    return;
    else{
        std::stack<datatype> a;
        Tree *p = bt;
        while(p != nullptr || !a.empty()){
            while(p != nullptr){
                cout<<p->data;
                a.emplace(p);
                p = p->left;
            }
            if(!a.empty()){
                p = a.top();
                a.pop();
                p = p->right;
            }
        }
    }
}

