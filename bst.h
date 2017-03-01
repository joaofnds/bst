struct node {
  int value;
  struct node *left, *right;
};

/**
 * Creates a new node
 *
 * @param [value] Value that the new node will hold
 *
 * @return Newly created node if succeeds, NULL if not
 */
struct node *bst_create_node(int value);

/**
 * Destroy every node "below" and including the root
 *
 * @param [root] The root of the BST
 */
void bst_destroy(struct node *root);

/**
 * Inserts a value in the BST
 *
 * @param [root] Root of the BST
 * @param [value] Value that the new node will hold
 *
 * @return The node that holds [value], chaing by it's branch all the way to the root.
 */
struct node *bst_insert(struct node *root, int value);

/**
 * Remove a value from the BST
 *
 * @param [root] Root of the BST
 * @param [value] Value to be deleted
 *
 * @return // TODO: define what it returns
 */
struct node *bst_remove(struct node *root, int value);

/**
 * Get the left child of a node
 *
 * @param [node] Parent node
 * 
 * @return Pointer to it's left subtree if exists, NULL if doesn't
 */
struct node *bst_left(struct node *node);

/**
 * Get the right child of a node
 *
 * @param [node] Parent node
 * 
 * @return Pointer to it's right subtree if exists, NULL if doesn't
 */
struct node *bst_right(struct node *node);

/**
 * Find a value in the tree/sub-tree
 *
 * @param [root] Root/node that you want to search [value]
 *
 * @return Pointer to the node that holds [value] if it finds, NULL if it doesn't
 */
struct node *bst_find(struct node *root, int value);

/**
 * Get the max value from the tree/sub-tree
 *
 * @param [root] Root/node that you want to know the max value
 *
 * @return Pointer to the node that holds the max value if there's children, NULL if it doesn't
 */
struct node *bst_max(struct node *root);


/**
 * Get the min value from the tree/sub-tree
 *
 * @param [root] Root/node that you want to know the max value
 *
 * @return Pointer to the node that holds the min value if there's children, NULL if it doesn't
 */
struct node *bst_min(struct node *root);

/**
 * Prints tree In Order Traversal
 *
 * @param [root] Root/node that you want o print from
 */
void bst_inorder_print(struct node *root);

/**
 * Prints tree indented
 *
 * @param [root] Root/node that you want o print from
 */
void bst_indented_print(struct node *root, int level);