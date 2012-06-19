#include <iostream>
#include <list>
#include <map>
#include <string>

using namespace std;


//Struct for the node of the Dictionary.
/*
 The class members are - 
  node_str - stores the string present in that node.
  Childlist - the list of children of the node.
  meaninglist - the list of meanings of those valid words which end in the node in question.
*/
class Node_Dict
{
    public :
        string node_str;
        list<Node_Dict*> ChildList;
        map<int, string> meaninglist;
        Node_Dict();
};


//Class definition for Suffix-Trie.
/*
 The members are - 
  root - pointer to the root of the tree.Does not store any string.An empty node.
  Member functions are well documented in the .cpp file.
*/
class Dictionary
{
    public :
        void Add_To_Dict(string t, string m);
        string Find_Meaning(string w);
        Node_Dict* Root();
        void Display();
        Dictionary();

    private :
        Node_Dict* root;
        bool isleaf(Node_Dict* t);
        string isvalid_helper(string w, Node_Dict* t);
        void adder_helper(string w, Node_Dict* ht, string m);
        int FindSubstring(string node_val, string v);
        string isvalidword(int v, Node_Dict* t);
        void display_helper(Node_Dict* t, int v);
};
