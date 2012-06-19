#include "dictionary-compressed.h"
#include <iterator>


//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!----------- Node of the dictionary ----------!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

Node_Dict::Node_Dict()
{
    node_str = "";
}


//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!------------ Suffix tree class definitions --------!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

Dictionary::Dictionary()
{
    root = new Node_Dict();
}


//Returns the pointer to the root of the suffix tree.
Node_Dict* Dictionary::Root()
{
    return root;
}


//Adds the word t whose meaning is m to the the dictionary(tree).
void Dictionary::Add_To_Dict(string t, string m)
{
    adder_helper(t, Root(), m);
}


//Finds the meaning of the word w.returns the meaning if w is valid,else returns not found.
string Dictionary::Find_Meaning(string w)
{
    return isvalid_helper(w, Root());
}


void Dictionary::Display()
{
    cout << "*" << endl;
    display_helper(Root(), 1);
}

//#####################################################----- Private functions -----####################################################

bool Dictionary::isleaf(Node_Dict* t)
{
    if (t->ChildList.empty())
        return true;
    else
        return false;
}



//Helper function to find the extent to which string node_val and v match.returns -1 if they do not match at all.
int Dictionary::FindSubstring(string node_val, string v)
{
    if (node_val.length() >= v.length())
    {
        if (node_val.substr(0, v.length()) == v)
            return v.length();
        else
            return -1;
    }
    else
    {
        if (v.substr(0, node_val.length()) == node_val)
            return (node_val.length());
        else
            return -1;
    }
}


//Helper function to check if a word completely found in the dict is valid or not,by checking whether a word ends at position v in the string of node t.
string Dictionary::isvalidword(int v, Node_Dict* t)
{
    map<int, string>::iterator itr1 = t->meaninglist.find(v);
    if (itr1 == t->meaninglist.end())
        return "not found";
    else
        return (*itr1).second;
}


//Helper function for the IsPresent() function.The function basically traverses the path of the string w in the tree.returns true only if the word is 
//valid as decided by the isvalidword function above.
string Dictionary::isvalid_helper(string w, Node_Dict* ht)
{
    list<Node_Dict*>::iterator itr = ht->ChildList.begin();
    int last_pos;
    while (itr != ht->ChildList.end())
    {
        last_pos = FindSubstring((*itr)->node_str, w);
        cout << last_pos << endl;
        if (last_pos != -1)
        {
            if ((unsigned)last_pos == w.length())
            {
                return isvalidword(last_pos - 1, (*itr));
            }
            else
                return isvalid_helper(w.substr(last_pos), *itr);
        }
        else
            itr++;
    }
    return "not found.";
}


//Helper function for Add_To_Dict function.
void Dictionary::adder_helper(string w, Node_Dict* ht, string m)
{
    list<Node_Dict*>::iterator itr = ht->ChildList.begin();
    int last_pos = -1;
    //Checking if the word w matches to a certain extent with one of the children of node ht.If so a recursive call is made with remaining substring to
    //that child of ht.
    while (itr != ht->ChildList.end())
    {
        last_pos = -1;
        for (int kl = 0; (unsigned)kl < w.length(); kl++)
        {
            if (w[kl] == (*itr)->node_str[kl])
                last_pos += 1;
            else
                break;
        }
        if (last_pos != -1)
        {
            if (last_pos == (w.length() - 1))
            {
                ht->meaninglist[last_pos] = m;
                return void();
            }
            else
            {
                if (last_pos < ((*itr)->node_str.length() - 1))
                {
                    Node_Dict* tn = new Node_Dict();
                    tn->node_str = (*itr)->node_str.substr(last_pos + 1);
                    //Adding the children of the present to the divided node.
                    while (!(*itr)->ChildList.empty())
                    {
                        tn->ChildList.push_back((*itr)->ChildList.front());
                        (*itr)->ChildList.pop_front();
                    }
                    //Changing the valid positions of the remaining substring.
                    list<int> removelist;
                    map<int, string>::iterator itr1 = (*itr)->meaninglist.begin();
                    for ( ; itr1 != (*itr)->meaninglist.end(); itr1++)
                    {
                        if ((*itr1).first > last_pos)
                        {
                            tn->meaninglist[((*itr1).first - last_pos - 1)] = (*itr1).second;
                            removelist.push_back((*itr1).first);
                        }
                    }
                    while (!removelist.empty())
                    {
                        (*itr)->meaninglist.erase(removelist.front());
                        removelist.pop_front();
                    }
                    //Finished dividing the node.Making the required changes to the new and the old nodes.
                    (*itr)->node_str = w.substr(0,last_pos + 1);
                    (*itr)->ChildList.push_back(tn);
                    Node_Dict* tm = new Node_Dict();
                    tm->node_str = w.substr(last_pos + 1);
                    tm->meaninglist[tm->node_str.length() - 1] = m;
                    (*itr)->ChildList.push_back(tm);
                    return void();
                }
                else
                {
                    adder_helper(w.substr(last_pos + 1), (*itr), m);
                    return void();
                }
            }
        }
        else
        {
            itr++;
        }
    }
    //Adding a new node to the children of ht if none of the children of node ht contain even a part of the substring w.
    Node_Dict* tn = new Node_Dict();
    tn->node_str = w;
    tn->meaninglist[w.length() - 1] = m;
    ht->ChildList.push_back(tn);
}


void Dictionary::display_helper(Node_Dict* t, int v)
{
    int i = 0;
    if (isleaf(t))
    {
        return void();
    }
    list<Node_Dict*>::iterator itr = t->ChildList.begin();
    while (itr != t->ChildList.end())
    {
        for (i = 0; i < v; i++)
        cout << " ";
        cout << (*itr)->node_str << endl;
        display_helper(*itr, v + 1);
        itr++;
    }
}
