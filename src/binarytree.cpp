#include <iostream>
#include <binarytree.hpp>
#include <algorithm>


int Tree::node_height(Node *node){
    if(!node)
        return 0;
    else
    {
        return node->height;
    }
    
}

void Tree::add_value(int v){

    Node *node = new Node(v);
    add_node(root, node);

}

Node* Tree::get_node(int v){

    Node *x = root;
    while(x){
        if(v == x->data){
            break;
        }
        else if(v < x->data){
            x = x->left;
        }
        else{
            x = x->right;
        } 

    }
    return x;
}

Node* Tree::min_node(Node *sub){
    if(sub->left){
        return min_node(sub->left);
    }
    else{
        return sub;
    }
}

void Tree::transplant(Node *z, Node *y){
    Node *z_parent = z->parent;
    if(z_parent){
        if(z_parent->left == z){
            z_parent->left = y;
        }
        else{
            z_parent->right = y;
        }

    }
    else{
        root = y;
    }
    if(y && y->parent)
        y->parent = z_parent;
}

void Tree::remove_value(int v){
    Node *target = get_node(v);
    if(target){
        if(!target->left){
            transplant(target, target->right);
        }
        else if(!target->right){
            transplant(target, target->left);
        }
        else{
            Node *min_s = min_node(target->right);
            if(min_s->parent != target){
                if(min_s->right) transplant(min_s, min_s->right);
                min_s->right = target->right;
                min_s->right->parent = min_s;
            }
            transplant(target, min_s);
            min_s->left = target->left;
            min_s->left->parent = min_s;
        }
        target->left = NULL;
        target->right = NULL;
        delete target;
        height_update(root);
    }

}

void Tree::add_node(Node *parent, Node *node){
    if(!root){
        root = node;
    }
    else{
        if(node->data > parent->data){
            if(parent->right){
                add_node(parent->right, node);
            }
            else{
                node->parent = parent;
                parent->right = node;
            }
        }
        else{
            if(parent->left){
                add_node(parent->left, node);
            }
            else{
                node->parent = parent;
                parent->left = node;
            }
        }
        parent->height = std::max(node_height(parent->left), node_height(parent->right)) + 1;
        int height_diff = node_height(parent->left) - node_height(parent->right);
        if(height_diff > 1){
            if(node->data < parent->left->data){
                right_rotate(parent);
            }
            else{
                left_rotate(parent->left);
                right_rotate(parent);
            }

        }
        else if(height_diff < -1){
            if(node->data > parent->right->data){
                left_rotate(parent);
            }
            else{
                right_rotate(parent->right);
                left_rotate(parent);
            }
        }
    }
}

void Tree::right_rotate(Node *node){

    Node *y = node->left;
    Node *t = y->right;

    y->parent = node->parent;
    y->right = node;
    y->parent->left = y;

    node->parent = y;
    node->left = t;
    if(t) t->parent = node;

    node->height = std::max(node_height(node->left), node_height(node->right)) + 1;
    y->height = std::max(node_height(y->left), node_height(y->right)) + 1;

}

void Tree::left_rotate(Node *node){

    Node *y = node->right;
    Node *t = y->left;

    y->parent = node->parent;
    y->left = node;
    y->parent->right = y;

    node->parent = y;
    node->right = t;
    if(t) t->parent = node;

    node->height = std::max(node_height(node->left), node_height(node->right)) + 1;
    y->height = std::max(node_height(y->left), node_height(y->right)) + 1;
}


void Tree::height_update(Node *node){
    if(node->left)
        height_update(node->left);
    if(node->right)
        height_update(node->right);
    node->height = std::max(node_height(node->left), node_height(node->right)) + 1;

}

void Tree::inorder_print(Node *node){
    if(node->left)
        inorder_print(node->left);
    std::cout << node->data << std::endl;
    if(node->right)
        inorder_print(node->right);

}
