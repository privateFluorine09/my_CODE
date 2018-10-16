
//Not a actual header, just my notebook

static const auto _ = []()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();


static int x=[]()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();




/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */



class Solution
{
public:

    bool isSameTree(TreeNode* p, TreeNode* q)
    {

        if(p==NULL && q==NULL)
            return true;

        if(p==NULL || q==NULL)
            return false;

        if(p->val==q->val)
            return isSameTree(p->left, q->left)&&isSameTree(p->right, q->right);

        else
            return false;

    }


};


class Solution
{
public:
    bool isSameTree(TreeNode* p, TreeNode* q)
    {
        if(p == NULL && q == NULL) return true;
        if(p == NULL && q != NULL) return false;
        if(p != NULL && q == NULL) return false;
        if(p->val != q->val) return false;
        return isSameTree(p->left,q->left)&&isSameTree(p->right,q->right);
    }
};


class Solution
{
public:

    bool flag = false;

    bool hasPathSum(TreeNode* root, int sum)
    {
        preorder(root, sum);
        return flag;
    }

    void preorder(TreeNode* root, int sum)
    {
        if(root != NULL)
        {
            int value = root -> val;
            if(sum == value && root ->left == NULL && root -> right == NULL)
            {
                flag = true;
            }

            preorder(root->left, sum-value);
            preorder(root->right, sum-value);

        }
    }
};


class Solution
{
public:
    int maxProfit(vector<int>& prices)
    {
        int buy = INT_MAX;
        int profit = 0;
        for (int i = 0; i < prices.size(); ++i)
        {
            if (prices[i] < buy)
            {
                buy = prices[i];
                continue;
            }
            if (buy<INT_MAX&&prices[i] - buy>profit)
                profit = prices[i] - buy;
        }
        return profit;
    }
};

//possible solution:

class Solution
{
public:
    int maxProfit(vector<int>& prices)
    {

        if(prices.empty())
            return 0;

        vector<int>::iterator itr=prices.begin();

        vector<int>::iterator buy, sell;

        buy=itr, sell=prices.end();

        itr++;

        while(itr!=prices.end())
        {

            if(*itr<*buy)
            {
                buy=itr;
                itr++;
                continue;
            }

            if(sell==prices.end())
            {
                if(*itr>*buy && itr-buy>0)
                {
                    sell=itr;
                    itr++;
                    continue;
                }
            }

            if(*itr>*sell && itr-buy>0)
            {
                sell=itr;
            }

            itr++;
        }

        if(sell=prices.end())
            return 0;

        return *sell-*buy;
    }
};


//from the paste:

#include <map>
#include <string>
#include <utility>
#include <algorithm>

using std::map;
using std::pair;
using std::make_pair;
using std::string;

map<int, char> list;

class find_
{
private:
    char n;
public:
    find_() = default;
    find_(char _n) : n(_n) {}
    bool operator()(pair<int, char> p)
    {
        return this->n == p.second;
    }
};

static void init()
{
    list.insert(make_pair<int, char>(0, '0'));
    list.insert(make_pair<int, char>(1, '1'));
    list.insert(make_pair<int, char>(2, '2'));
    list.insert(make_pair<int, char>(3, '3'));
    list.insert(make_pair<int, char>(4, '4'));
    list.insert(make_pair<int, char>(5, '5'));
    list.insert(make_pair<int, char>(6, '6'));
    list.insert(make_pair<int, char>(7, '7'));
    list.insert(make_pair<int, char>(8, '8'));
    list.insert(make_pair<int, char>(9, '9'));
    list.insert(make_pair<int, char>(10, 'A'));
    list.insert(make_pair<int, char>(11, 'B'));
    list.insert(make_pair<int, char>(12, 'C'));
    list.insert(make_pair<int, char>(13, 'D'));
    list.insert(make_pair<int, char>(14, 'E'));
    list.insert(make_pair<int, char>(15, 'F'));
}

static int pow(int n, int p)
{
    if (p == 0)
        return 1;
    else
        return n * pow(n, p - 1);
}

int vtod(string s, int v);

int main()
{
    init();
    std::ios::sync_with_stdio(false);
    auto e = vtod("AAAA", 12);
    return 0;
}

int vtod(string s, int v)
{
    int res = 0;
    for (int i = 0; i < s.size(); ++i)
    {
        auto tmp = find_if(list.begin(), list.end(), find_(s[s.size() - i - 1]))->first;
        res += tmp * pow(v, i);
    }
    return res;
}

//file ends here
