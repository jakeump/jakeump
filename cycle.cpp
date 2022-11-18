/* 
 * cycle.cpp 
 * Univeristy of Michigan, Ann Arbor
 * EECS 281 Lab 9 Written.
 * SUBMIT ONLY THIS FILE TO GRADESCOPE.
 */

// Common #includes for convience.
// No need to use them. 
// Remove any of them if you want.
#include <algorithm>
#include <deque>
#include <functional>
#include <iostream>
#include <iterator>
#include <limits>
#include <list>
#include <map>
#include <math.h>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

#include "cycle.h"

using namespace std;

bool dfs(int idx, int parent, const vector<vector<int>> &adj_list, vector<bool> &visited) {
  if (visited[idx]) return true; // there is a cycle
  visited[idx] = true;
  for (size_t i = 0; i < adj_list[i].size(); i++) {
    if (adj_list[idx][i] == parent) continue; // won't be a cycle, just undirected edge
    return dfs(adj_list[idx][i], idx, adj_list, visited);
  }
  return false;
}

bool is_graph_cyclic(const vector<vector<int>> &adj_list) {
  vector<bool> visited(adj_list.size(), false);
  for (int i = 0; i < adj_list.size(); i++) {
    if (!visited[i]) {
      if (dfs(i, i, adj_list, visited)) return true; // cycle
    }
  }
  return false;
}
