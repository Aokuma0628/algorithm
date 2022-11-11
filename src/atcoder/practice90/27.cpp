#include <iostream>
#include <cstdint>
#include <array>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iomanip>

using std::cout;
using std::endl;

namespace {
  enum {
    OK = 1,
    NG = 0,
  };

  struct t_TreeNode {
    std::string str;
    t_TreeNode *left;
    t_TreeNode *right;
  };
}

namespace {
  bool insert_tree_node(
    t_TreeNode *root,
    std::string str
  )
  {
    t_TreeNode *node = NULL;

    try {
      node = new t_TreeNode;
    }
    catch (std::bad_alloc &err) {
      cout << "memory exhausted " << err.what() << endl;
      std::exit(1);
    }

    node->str = str;
    node->left = NULL;
    node->right = NULL;

    if (root->str.size() == 0) {
      root->str = node->str;
    }
    else {
      t_TreeNode *search = root;
      while (search) {
        if (search->str < str) {
          if (search->left) {
            search = search->left;
          }
          else {
            search->left = node;
            break;
          }
        }
        else {
          if (search->right) {
            search = search->right;
          }
          else {
            search->right = node;
            break;
          }
        }
      }
    }

    return true;
  }


  t_TreeNode *find_tree_node(
    t_TreeNode *root,
    std::string str
  )
  {
    t_TreeNode *node = root;
    if (!root) return NULL;

    while (node) {
      if (node->str == str) {
        break;
      }
      else if (node->str < str) {
        node = node->left;
      }
      else {
        node = node->right;
      }
    }

    return node;
  }


  void main_logic(
    uint32_t n,
    std::vector<std::string> s
  )
  {
    t_TreeNode root;
    root.str = "";
    root.left = NULL;
    root.right = NULL;

    for (uint32_t i = 0; i < n; i++) {
      t_TreeNode *node = NULL;
      node = find_tree_node(&root, s[i]);
      if (node) continue;

      insert_tree_node(&root, s[i]);
      cout << i + 1 << endl;
    }

    return;
  }
}


int32_t main(void)
{
  uint32_t n = 0;
  uint32_t i;
  std::vector<std::string> s;

  std::cin >> n;

  for (i = 0; i < n; i++) {
    std::string str;
    std::cin >> str;
    s.push_back(str);
  }

  main_logic(n, s);

  return 0;
}