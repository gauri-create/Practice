#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Node
{
    Node *links[26];
    bool flag = false;

    Node()
    {
        for (int i = 0; i < 26; i++)
            links[i] = nullptr;
        flag = false;
    }

    bool containsKey(char ch)
    {
        return links[ch - 'a'] != nullptr;
    }

    Node *get(char ch)
    {
        return links[ch - 'a'];
    }

    void put(char ch, Node *node)
    {
        links[ch - 'a'] = node;
    }

    void setEnd()
    {
        flag = true;
    }

    bool isEnd()
    {
        return flag;
    }
};

class Trie
{
private:
    Node *root;

public:
    Trie()
    {
        root = new Node();
    }

    void insert(string word)
    {
        Node *node = root;
        for (int i = 0; i < word.length(); i++)
        {
            if (!node->containsKey(word[i]))
            {
                node->put(word[i], new Node());
            }
            node = node->get(word[i]);
        }
        node->setEnd();
    }

public:
    bool checkIfPrefixExists(string word)
    {
        Node *node = root;
        for (int i = 0; i < word.length(); i++)
        {
            if (!node->containsKey(word[i]))
                return false;
            node = node->get(word[i]);
            if (!node->isEnd())
                return false;
        }
        return true;
    }
};

class Solution
{
public:
    string completeString(vector<string> &nums)
    {
        Trie trie;
        for (auto &it : nums)
        {
            trie.insert(it);
        }
        string longest = "";
        for (auto &it : nums)
        {
            if (trie.checkIfPrefixExists(it))
            {
                if (it.length() > longest.length())
                {
                    longest = it;
                }
                else if (it.length() == longest.length() && it < longest)
                {
                    longest = it;
                }
            }
        }
        if (longest == "")
            return "None";
        return longest;
    }
};

int main()
{
    vector<string> nums = {"n", "ni", "nin", "ninj", "ninja", "nil"};
    Solution obj;
    string ans = obj.completeString(nums);
    cout << ans;
    return 0;
}