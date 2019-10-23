

struct Node{

    int data;
    int height;
    struct Node *parent = nullptr;
    struct Node *left = nullptr;
    struct Node *right = nullptr;

    Node(){}
    explicit Node(int v):data(v), height(1){}

    virtual ~Node(){
        if(left)
            delete left;
        if(right)
            delete right;
    }

};


struct Tree{

    Node *root = nullptr;

    Tree(){}
    virtual ~Tree(){
        if(root)
            delete root;
    }

    void add_value(int v);

    void add_node(Node *parent, Node *node);

    void add_balance_node(Node *parent, Node *node);

    Node* get_node(int v);

    Node* min_node(Node *sub);

    int node_height(Node *node);

    void transplant(Node *z, Node *y);
    
    void remove_value(int v);

    void height_update(Node *node);

    void inorder_print(Node *node);

    void left_rotate(Node *node);
    
    void right_rotate(Node *node);

};