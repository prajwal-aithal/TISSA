#include <iostream>
#include <list>
#include <string>

using namespace std;


//Struct for the node of the suffix-trie.
/*
 The class members are - 
  node_str - stores the string present in that node.
  Childlist - the list of children of the node.
  Line_numlist - the list of line number of the words ending at the node.
*/
class Node_STree
{
    public :
        string node_str;
        list<Node_STree*> ChildList;
        list<int> Line_numlist;
};


//Class definition for Suffix-Trie.
/*
 The members are - 
  root - pointer to the root of the tree.Does not store any string.An empty node.
  Member functions are well documented in the .cpp file.
*/
class suffix_tree
{
    public :
        void Insert(string w, int line_num);
        list<int> IsPresent(string w);
        Node_STree* Root();
        void Display();
        suffix_tree();

    private :
        Node_STree* root;
        bool isleaf(Node_STree* t);
        list<int> ispresent_helper(string w, Node_STree* t);
        void insert_helper(string w, Node_STree* ht, int line_num);
        int FindSubstring(string node_val, string v);
        void display_helper(Node_STree* t, int v);
};
