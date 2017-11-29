struct Node;
struct AVLTree;

AVLTree *createAVLTree();
void add(AVLTree *tree, char value);
bool contains(AVLTree *tree, char value);
void clearAVLTree(AVLTree *tree);
