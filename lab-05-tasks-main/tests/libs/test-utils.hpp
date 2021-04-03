#pragma once
#include <iostream>
#include <string>
#include <math.h>
#include <cstdbool>
#include <fstream>
#include <algorithm>
#include <vector>
#include <list>
#include <set>

#include "utils.h"
#include "catch.hpp"

#include "tree.h"

#define TASK1_TEST_FILENAME "../data/test-createbalanced.txt"
#define TASK1_TEST_FILENAME_EXPECTED "../data/test-createbalanced-expected.txt"


void inorderRec(TreeNode* root, TreeNode **arr, int size);

int* initCreateBalanced(const char* fileName);

TreeNode* newNode(int data);

TreeNode* createTreeForLCATest();

