#include "suffix-tree.h"
#include <iterator>


//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!------------ Suffix tree class definitions --------!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

suffix_tree::suffix_tree()
{
    root = new Node_STree();
}


//Checks if the word w is present in the given document.
list<int> suffix_tree::IsPresent(string w)
{
    list<int> res = ispresent_helper(w, Root());
    res.unique();
    return res;
}



Node_STree* suffix_tree::Root()
{
    return root;
}



//Inserts the word w and its line number line_num into the suffix tree.
void suffix_tree::Insert(string w, int line_num)
{
    //Node_STree* t = Root();
    int i = w.length();
    for (int k = 0; k < i; k++)
    {
        insert_helper(w.substr(k), Root(), line_num);
        //cout << w.substr(k) << "  :  ";
    }
}


void suffix_tree::Display()
{
    cout << "*" << endl;
    display_helper(Root(), 1);
}

//#####################################################----- Private functions -----####################################################

bool suffix_tree::isleaf(Node_STree* t)
{
    if (t->ChildList.empty())
        return true;
    else
        return false;
}



//Helper function to find the extent to which string node_val and v match.returns -1 if they do not match at all.
int suffix_tree::FindSubstring(string node_val, string v)
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


//Helper function for the IsPresent() function.The function basically traverses the path of the string w in the tree.returns true only if the word is 
//completely present in the suffix tree path.
list<int> suffix_tree::ispresent_helper(string w, Node_STree* ht)
{
    list<Node_STree*>::iterator itr = ht->ChildList.begin();
    int last_pos;
    while (itr != ht->ChildList.end())
    {
        last_pos = FindSubstring((*itr)->node_str, w);
        if (last_pos != -1)
        {
            if ((unsigned)last_pos == w.length())
                return (*itr)->Line_numlist;
            else
                return ispresent_helper(w.substr(last_pos), *itr);
        }
        else
            itr++;
    }
    list<int> v;
    return v;
}



//Helper function to Insert function.
void suffix_tree::insert_helper(string w, Node_STree* ht, int line_num)
{
    list<Node_STree*>::iterator itr = ht->ChildList.begin();
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
                (*itr)->Line_numlist.push_back(line_num);
                return void();
            }
            else
            {
                if (last_pos < ((*itr)->node_str.length() - 1))
                {
                    Node_STree* tn = new Node_STree();
                    tn->node_str = (*itr)->node_str.substr(last_pos + 1);
                    (*itr)->Line_numlist.push_back(line_num);
                    tn->Line_numlist = (*itr)->Line_numlist;
                    //Adding the children of the present to the divided node.
                    while(!(*itr)->ChildList.empty())
                    {
                        tn->ChildList.push_back((*itr)->ChildList.front());
                        (*itr)->ChildList.pop_front();
                    }
                    (*itr)->node_str = w.substr(0, last_pos + 1);
                    (*itr)->ChildList.push_back(tn);
                    Node_STree* tm = new Node_STree();
                    tm->node_str = w.substr(last_pos + 1);
                    tm->Line_numlist.push_back(line_num);
                    (*itr)->ChildList.push_back(tm);
                    return void();
                }
                else
                {
                    (*itr)->Line_numlist.push_back(line_num);
                    insert_helper(w.substr(last_pos+1), (*itr), line_num);
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
    Node_STree* tn = new Node_STree();
    tn->node_str = w;
    tn->Line_numlist.push_back(line_num);
    ht->ChildList.push_back(tn);
}


void suffix_tree::display_helper(Node_STree* t, int v)
{
    int i = 0;
    if (isleaf(t))
    {
        return void();
    }
    list<Node_STree*>::iterator itr = t->ChildList.begin();
    while (itr != t->ChildList.end())
    {
        for (i = 0; i < v; i++)
            cout << " ";
        cout << (*itr)->node_str << endl;
        display_helper(*itr, v + 1);
        itr++;
    }
}
