// ASSUME MAX_OTHER IS THE MOST POSSIBLE CONNECTED NODES
// ASSUME THIS IS 16

// FIXED STRUCT: 16 + 16 + 16 * 16 = 256 + 32 = 288 bytes
struct node {
  uint32 my_id;
  uint32 other_count;
  uint32 other_ids[MAX_OTHER];
}

// assume that we allow 128 nodes in memory at any time
// assume that a page of nodes on disk contains 64 nodes (2 pages in memory)

int load_page(int page_id, node* nodes);

// a struct to map a node to a page
// FIXED SIZE : 8 bytes large
struct node_page_entry {
  uint32 node_id;
  uint32 page_id;
}

// assume that one page held 128 node_page_entries

struct node {
 int id;
 Bool visited; // init to false
 node** other_nodes;
 int other_node_count;
}

boolean has_loop(node* start) {

}

/*
 * Truths
 * 1. A loop is finding a node that has previously been visited.
 * 2. A special case is handling the node you are coming from.
 */

boolean has_loop(node* start) {
  return has_loop(start, null);
}

boolean has_loop(node* start, node* ignore) {
  if (start->visited) {
    return true;
  }

  start->visited = true;

  for (int child_index = 0; child_index < start->other_node_count; child_index++) {
    node* child = start->other_nodes[child_index];

    if (child != ignore && has_loop(child)) {
      return true;
    }
  }

  return false;
}

boolean has_loop(node* start) {
   start->visited = true;
   Bool totalStatus = true;

   For (int i = 0; i < start->other_node_count; ++i) {
     Node *child = start->other_nodes[i];
     if (!child->visited) {
       For (int j = 0; j < child->other_node_count; ++j) {
         If (child->other_nodes[j] != child && child->other_nodes[j].visited){
             Return false;
         } 
       }
     }
  }

   For (int i = 0; i < start->other_node_count; ++i) {
      Node *child = start->other_nodes[i];
      If (!child->visited) {
          Visited = visited && has_loop(child);
      }
   }

   Return visted;
}

   O--O--O
  /    \
 O--O---O

V-O-O-O-O-O-O-O-O
\              /
 O------------O

S---O--O
     \ |
      \O

bool BFS_has_loop(node *start) {
  queue<node *> nodeq;
  nodeq.push(start);

  while (!nodeq.empty()) {
    node *cur = nodeq.front();
    nodeq.pop();
    cur->visted = true;

    for (int i = 0; i < cur->other_node_count; ++i) {
      node *child = cur->other_nodes[i];
      
      if (child != cur && child.visited) {
        return true;
      }

      nodeq.push(child);
    }
  }

  return false;  
}