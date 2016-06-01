/*

        o
   o         o
 o   o     o   o

*/

vector<vector<Node *>> levels;

void addLevels(Node *node, int level) {
   if (levels.size() < level) {
      levels.push_back(vector<Node *>());
   } 

   for (Node *child : node->children) {
      levels[level].push_back(child);
      addLevels(child, level + 1);
   }
}

void printLevels(vector<vector<Node *>> levels) {
   for (int i = levels.size() - 1; i >= 0; --1) {
      for (auto const &item : levels[i]) {
         cout << item->message << endl;
      }
   }
}