#include "bst.h"

BST::Node::Node(std::shared_ptr<Node> p, std::shared_ptr<Node> r, std::shared_ptr<Node> l)
{
    parent = p;
    right = r;
    left = l;
}

BST::Node::Node(int i)
{
    val = i;
}

void BST::Node::show()
{
    if (val)
        std::cout << "The value of Node is " << val << "\n";
    if (parent)
        std::cout << "The value of Parent of Node is " << val << "\n";
    if (left)
        std::cout << "The value of Left of Node is " << left->val << "\n";
    if(right)
        std::cout << "The value of Right of Node is " << right->val << "\n";
    std::cout << std::endl;
}

BST::BST()
{
    std::cout << "constructor\n";
    // proot->val = 0 ;
    proot = std::make_shared<Node>(nullptr,nullptr,nullptr);
    rot=nullptr;
    s=0;
    vec = {};
    std::cout << proot->val << " the constructor value\n";
}

BST::BST(const BST& b):BST()
{
    std::cout << "copy constructor\n";
    proot = copy(b.proot);
    s=b.s;
}

BST::~BST()
{
    vec = std::vector<int>(); //free-up memory: swap with empty vector with no memory allocated
}

std::shared_ptr<BST::Node> BST::copy(std::shared_ptr<BST::Node> rot)
{
    if (rot == NULL)
        return nullptr;
    std::shared_ptr<Node> copy_root = std::make_shared<Node>(nullptr,nullptr,nullptr);
    copy_root->val=rot->val;
    copy_root->parent=rot->parent;
    copy_root->left=copy(rot->left);
    copy_root->right=copy(rot->right);
    std::cout << "the value which is being coping is : " << rot->val << "\n";
    return copy_root;
}

BST* BST::add(int i)
{
    if (!proot)
    {
        proot = std::make_shared<Node>(nullptr,nullptr,nullptr);
    }
    add(i,proot);
    return this;
}

void BST::add(int i,std::shared_ptr<BST::Node> rot)
{
    std::cout << proot->val << " the value of proot in entrance of add\n";
    std::cout << i << " " << rot->val << " the value of rot in entrance of add , size: " << s << "\n";

    if (!rot->val)
    {
        proot->val=i;
        rot = proot;
        std::cout << "rot is " << rot->val << "\n";
        s += 1;
    }
      else if( i <= rot->val )
    {
        std::cout << i << "<=" << rot->val << "\n"; 
        if (rot->left)
        {
            std::cout << "has left\n";
            add(i,rot->left);
        }
        else
        {
            rot->left = std::make_shared<Node>(nullptr,nullptr,nullptr);
            rot->left->parent = rot;
            
            rot->left->val = i;
            std::cout << rot->left->parent->val << "*****" << rot->left->val << "\n"; 
            s += 1;
            // if (rot->right)
            // {
            //     std::cout << "set right\n";
            //     rot->right->parent = rot;
            // }
        }          
    }
    else if( i > rot->val )
    {
        std::cout << i << ">=" << rot->val << "\n"; 
        if (rot->right)
        {
            std::cout << "has right\n";
            add(i,rot->right);                
        }
        else
        {
            rot->right = std::make_shared<Node>(nullptr,nullptr,nullptr);
            rot->right->parent = rot;
            
            rot->right->val = i;
            std::cout << rot->right->parent->val << "*****" << rot->right->val << "\n";
            s += 1;
            // if (rot->left)
            // {
            //     std::cout << "set left\n";
            //     rot->left->parent = rot;
            // }
        }          
    }
    std::cout << "in add function size is : " << s << " " << rot.use_count() << "\n";
}

BST BST::operator+(int i)
{
    BST b = *this;
    b.add(i);
    std::cout << b.root() << " the root is in copy " << this->root() << "\n";
    return b;
}

bool BST::search(int i,std::shared_ptr<BST::Node> rot)
{
    // std::cout << i << " " << rot->val << " " << rot.use_count() << " entrance\n";
    if (rot == NULL) 
        return false;
    else if (rot->val == i) 
        return true;
    else if (i<=rot->val) 
        return search(i,rot->left);
    else 
        return search(i,rot->right); 
}

BST* BST::remove(int i)
{
    remove(i,proot);
    return this;
}

void BST::remove(int i , std::shared_ptr<BST::Node> rot)
{
    std::shared_ptr<BST::Node> temp;
    std::cout << i << " " << rot->val << " " << rot.use_count() << " entrance\n";

    if (rot == NULL)
    {
        std::cout << "There is no match for i\n";
    }   
    else if(i < rot->val)
        remove(i,rot->left);
    else if(i > rot->val)
        remove(i,rot->right);
    else
    {
        // case 1: No child
        if (rot->right==NULL && rot->left==NULL)
        {
            std::cout << "no hand\n";
            if (rot->parent == NULL)
            {
                std::cout << "null\n";
                proot=nullptr;
                rot=nullptr;                
            }else
            {
                std::cout << rot->parent->val << " has parent\n";
                if ( rot->val <= rot->parent->val )
                {
                    rot = rot->parent;
                    // rot->left.reset();
                    // std::cout << rot->left->val << "\n";
                    rot->left = nullptr;
                    // std::cout << rot->left << "\n";
                }
                else if (rot->val > rot->parent->val)
                {
                    rot = rot->parent;
                    rot->right = nullptr;
                }
            }
            s -= 1; 
        }

        // case2: One child
        else if (rot->right==NULL)
        {
            std::cout << "has left hand\n";
            temp = rot->left;
            if (rot->parent == NULL)
            {
                std::cout << "parent null\n";
                proot=nullptr;
                proot=temp;
                rot = temp;

            }else
            {
                std::cout << "Swap\n";
                rot = Swap(rot,temp);
            }
            s -= 1; 
        }
        else if (rot->left==NULL)
        {
            std::cout << "has right hand\n";
            temp = rot->right;
            if (rot->parent == NULL)
            {
                proot=nullptr;
                proot=temp;
                rot = proot;
            }else
            {
                Swap(rot,temp);
            }
            s -= 1; 
        }

        // case 2: Two children
        else
        {
            std::cout << "has two children\n";
            std::cout << rot->right->val << " " << rot->left->val << "\n";
            temp = FindMin(rot->right);
            std::cout << temp->parent->val << " ** " << rot->val << "**" << temp->val << std::endl;
            if (temp->parent == proot)
            {
                temp->left=proot->left;
                proot=temp;
            }else
            {
                // rot->val = temp->val;
                if (temp->val <= temp->parent->val)
                {
                    rot->val = temp->val;
                    temp->parent->left = nullptr;

                }  
                else
                {
                    rot->val = temp->val;
                    temp->parent->right = nullptr;
                } 
            }
            std::cout << "***" << std::endl;
            s -= 1;   
        }

    }
    // std::cout << proot->left->right->left->val << std::endl;
    // std::cout << i << " " << rot->val << " " << rot.use_count() << " exit\n";
    // std::cout << "proot when exiting " << proot->val <<"\n";
    std::cout << "out!" << std::endl;
}

std::shared_ptr<BST::Node> BST::Swap(std::shared_ptr<BST::Node> rot , std::shared_ptr<BST::Node> temp)
{
    if (rot->val < rot->parent->val)
    {
        rot=rot->parent;
        rot->left = nullptr;
        rot->left = temp;
    } 
    else if (rot->val > rot->parent->val)
    {
        std::cout << rot->val << "bigger than" << rot->parent->val << "\n";

        rot=rot->parent;
        // std::cout << rot->val << "bigger than" << rot->parent->val << "right" << rot->right->val<< "\n";
        rot->right = nullptr;
        // std::cout << rot->val << "bigger than" << rot->parent->val << "right" << rot->right->val<< "\n";
        rot->right = temp;
        // std::cout << rot->val << "bigger than" << rot->parent->val << "right" << rot->right->val<< "\n";
    }
    return rot;
}

std::shared_ptr<BST::Node> BST::FindMin(std::shared_ptr<BST::Node> rot) 
{
    std::shared_ptr<BST::Node> temp = rot; 
  
    while (temp && temp->left != NULL) 
        temp = temp->left; 

    std::cout << temp->val << "\n";  
    return temp; 
} 

std::vector<int> BST::inorder()
{
    vec.clear();
    inorder(proot);
    return vec;
}

void BST::inorder(std::shared_ptr<BST::Node> rot)
{
    if (rot!=NULL)
    {
        inorder(rot->left);
        // std::cout << rot->val << "\n";
        vec.push_back(rot->val);
        inorder(rot->right);
    }
    
}

std::vector<int> BST::preorder()
{
    vec.clear();
    preorder(proot);
    return vec;
}

void BST::preorder(std::shared_ptr<BST::Node> rot)
{
    if (rot!=NULL)
    {
        // std::cout << rot->val << "\n";
        vec.push_back(rot->val);
        preorder(rot->left); 
        preorder(rot->right);
    }
    
}

std::vector<int> BST::postorder()
{
    vec.clear();
    postorder(proot);
    return vec;
}

void BST::postorder(std::shared_ptr<BST::Node> rot)
{
    if (rot!=NULL)
    {
        postorder(rot->left);
        postorder(rot->right);
        // std::cout << rot->val << "\n";
        vec.push_back(rot->val);
    }
    
}

int BST::operator[](int index)
{
    this->inorder();
    return vec[index];
}

void BST::show()
{
    this->inorder();
    for (auto a : vec)
        std::cout << a << " ";
    std::cout << std::endl;
    // proot->show();
    // rot->show();
}