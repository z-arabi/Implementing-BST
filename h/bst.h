#ifndef BST_H
#define BST_H

#include <iostream>
#include <memory>
#include <vector>

#include <typeinfo>

class BST{
private:
    class Node{
        public:
            std::shared_ptr<Node> parent{nullptr};
            std::shared_ptr<Node> right{nullptr};
            std::shared_ptr<Node> left{nullptr};
            int val{0};
            Node(std::shared_ptr<Node> p, std::shared_ptr<Node> r, std::shared_ptr<Node> l);
            Node(int i);
            void show();  //  Prints the value of a node in a single line
    };   
    std::shared_ptr<Node> proot{nullptr};

    // variables I add in addition to the question
    std::shared_ptr<Node> rot{nullptr};  
    int s{0};
    std::vector<int> vec{};
    
public:

    BST();
    BST(const BST& b);
    ~BST();
    std::shared_ptr<Node> copy(std::shared_ptr<Node> rot);

    BST* add(int i);
    void add(int i,std::shared_ptr<Node> rot);
    BST operator+(int i); //  Adds i to the BST

    //  Returns true if the value i is in BST, otherwise false
    bool search(int i){ return search(i,proot); }
    bool search(int i,std::shared_ptr<Node> rot);

    BST* remove(int i);
    void remove(int i,std::shared_ptr<Node> rot);

    std::shared_ptr<Node> Swap(std::shared_ptr<Node> rot , std::shared_ptr<Node> temp);
    std::shared_ptr<Node> FindMin(std::shared_ptr<Node> rot);

    //  Inorder traverse of tree
    std::vector<int> inorder();
    void inorder(std::shared_ptr<Node> rot);

    //  Preorder traverse of tree
    std::vector<int> preorder(); 
    void preorder(std::shared_ptr<Node> rot);

    //  Postorder traverse of tree
    std::vector<int> postorder(); 
    void postorder(std::shared_ptr<Node> rot);

    //  Returns the root value
    int root(){ return proot->val; }

    //  Returns no of elements in BST 
    size_t size(){ return s; }

    int operator[](int index); // Returns the value of the index in the inorder sort 

    void show(); //  Prints the inorder traverse of BST in a single line.
};

#endif