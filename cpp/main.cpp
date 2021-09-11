#include <iostream>
#include "aphw3.h"
#include "gtest/gtest.h"

#include "test.h"

int main(int argc, char **argv)
{
    // ::testing::InitGoogleTest(&argc, argv);
    // std::cout << "RUNNING TESTS ..." << std::endl;
    // int ret{RUN_ALL_TESTS()};
    // if (!ret)
    //     std::cout << "<<<SUCCESS>>>" << std::endl;
    // else
    //     std::cout << "FAILED" << std::endl;
    std::cout << "Hello" << std:endl;
    return 0;

    // Test t{1};
    // Test t2{1,2};
    // Test t3{};
    // std::cout << t2.a << "\n";
    // t.show();

    // std::shared_ptr<BST::Node> p;
    // std::shared_ptr<BST::Node> r;
    // std::shared_ptr<BST::Node> l;
    // BST::Node(p,r,l);
    // std::shared_ptr<BST>mytree{std::make_shared<BST>()};

    // std::shared_ptr<BST>mytree{std::make_shared<BST>()};
    // mytree->add(8);
    // std::cout << "%%%%%%%%%%the root is " << mytree->root() << " size is  " << mytree->size() << std::endl;
    // // mytree->remove(8);
    // // std::cout << "%%%%%%%%%%size is  " << mytree->size() << std::endl;
    // // mytree->add(8);
    // mytree->add(3)->add(10)->add(14);
    // std::cout << "%%%%%%%%%%the root is " << mytree->root() << " size is  " << mytree->size() << std::endl;
    // // mytree->add(3);
    // // *mytree = *mytree + 3;
    // // mytree->add(14);
    // mytree->add(13);
    // // mytree->add(6);
    // *mytree = *mytree + 6;
    // mytree->add(1);
    // // mytree->add(7);
    // mytree->add(7);
    // // *mytree + 9;
    // // mytree->add(4);
    // *mytree = *mytree + 4;
    // // *mytree = *mytree + 7;

    // // std::cout << "search9 : " << mytree->search(9) << std::endl;
    // // std::cout << "#########the root is " << mytree->root() << " size is  " << mytree->size() << std::endl;

    // // std::cout << mytree->remove(7) << std::endl;
    // // mytree->add(11)->remove(4);
    // // mytree->add(11);
    // // std::cout << "#########the root is " << mytree->root() << " size is  " << mytree->size() << std::endl;
    // // std::cout << "search4 : " << mytree->search(4) << std::endl;
    // // mytree->remove(4);
    // // std::cout << "#########the root is " << mytree->root() << " size is  " << mytree->size() << std::endl;
    // // mytree->remove(7)->add(20);
    // // std::cout << "#########the root is " << mytree->root() << " size is  " << mytree->size() << std::endl;
    // // mytree->show();
    // // std::cout << "#########the root is " << mytree->root() << " size is  " << mytree->size() << std::endl;
    // // mytree->remove(11)->remove(20);
    // // std::cout << "#########the root is " << mytree->root() << " size is  " << mytree->size() << std::endl;
    // // mytree->remove(1);
    // // std::cout << "#########the root is " << mytree->root() << " size is  " << mytree->size() << std::endl;
    // mytree->show();

    // mytree->remove(13)->remove(14)->remove(10)->remove(8);
    // std::cout << "#########the root is " << mytree->root() << " size is  " << mytree->size() << std::endl;
    // mytree->show();
    // // mytree->remove(4)->remove(7);
    // // mytree->remove(3);
    // // std::cout << "#########the root is " << mytree->root() << " size is  " << mytree->size() << std::endl;
    // // mytree->show();
    // mytree->remove(14);
    // std::cout << "#########the root is " << mytree->root() << " size is  " << mytree->size() << std::endl;
    // // mytree->show();
    // std::vector<int> vect = mytree->inorder();
    // for (auto a : vect)
    //     std::cout << a << " ";
    // std::cout << "\n";

    // std::cout << "search9 : " << mytree->search(9) << std::endl;
    // std::cout << "#########the root is " << mytree->root() << " size is  " << mytree->size() << std::endl;

    // mytree->remove(10);
    // std::cout << "#########the root is " << mytree->root() << " size is  " << mytree->size() << std::endl;
    // mytree->show();
    // mytree->remove(3);
    // std::cout << "#########the root is " << mytree->root() << " size is  " << mytree->size() << std::endl;




    // std::cout << mytree->remove(14) << std::endl;
    // std::cout << mytree->root() << std::endl;
    // std::cout << mytree->remove(10) << std::endl;

    // // std::cout << mytree->remove(1) << std::endl;
    // // std::vector<int> vect = mytree->inorder();
    // // for (auto a : vect)
    // //     std::cout << a << " ";
    // // std::cout << "\n";
    // std::cout << "the end " << mytree->operator[](3)  << "the end" << "\n";
    // mytree->show();

    ////////////////////////////////////////////////////////////
    // std::shared_ptr<BST>mytree{std::make_shared<BST>()};
    // mytree->add(8);
    // std::cout << "%%%%%%%%%%the root is " << mytree->root() << " size is  " << mytree->size() << std::endl;
    // mytree->remove(8);
    // std::cout << "%%%%%%%%%%size is  " << mytree->size() << std::endl;
    // mytree->show();
    // mytree->add(8)->add(10);
    // std::cout << "befor remove: "; mytree->show();
    // mytree->remove(10);    
    // std::cout << "%%%%%%%%%%the root is " << mytree->root() << " size is  " << mytree->size() << std::endl;
    // std::cout << "after remove "; mytree->show();
    // // mytree->add(10)->remove(8);
    // // std::cout << "%%%%%%%%%%the root is " << mytree->root() << " size is  " << mytree->size() << std::endl;
    // // std::cout << "after remove "; mytree->show();
    // // *mytree+10;
    // *mytree = *mytree + 10;
    // std::cout << "befor remove "; mytree->show();
    // mytree->remove(10);    
    // std::cout << "%%%%%%%%%%the root is " << mytree->root() << " size is  " << mytree->size() << std::endl;
    // std::cout << "after remove "; mytree->show();
    // mytree->add(10)->add(14)->add(13);
    // // mytree->remove(13);
    // // std::cout << "after remove "; mytree->show();
    // // mytree->remove(14);
    // // std::cout << "after remove "; mytree->show();
    // // mytree->remove(10);
    // // std::cout << "after remove "; mytree->show();
    // // mytree->add(17)->remove(14);
    // // std::cout << "after remove "; mytree->show();
    // // mytree->add(17)->add(15)->add(18)->add(11)->remove(14)->remove(13);
    // // std::cout << "after remove "; mytree->show();
    // // mytree->add(3)->remove(8);
    // // std::cout << "after remove " << mytree->root() << "**" ; mytree->show(); 
    // mytree->add(3)->add(1);
    // *mytree = *mytree + 6;
    // mytree->add(4)->add(7);//->remove(3)->remove(6);
    // std::cout << "after remove " << mytree->root() << "**" ; mytree->show(); 

    // std::vector<int> vect = mytree->inorder();
    // for (auto a : vect)
    //     std::cout << a << " ";
    // std::cout << "\n";  

    // vect = mytree->preorder();
    // for (auto a : vect)
    //     std::cout << a << " ";
    // std::cout << "\n"; 

    // vect = mytree->postorder();
    // for (auto a : vect)
    //     std::cout << a << " ";
    // std::cout << "\n"; 



    // return 0;
}
