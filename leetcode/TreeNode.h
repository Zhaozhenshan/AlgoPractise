#pragma once
#include <iostream>
#include <limits.h>
#include <queue>
#include <string>
#include <vector>
using namespace std;
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x)
        : val(x)
        , left(nullptr)
        , right(nullptr) {};
};