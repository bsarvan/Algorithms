#include <iostream>
#include <vector>
#include <unordered_map>
#include <memory>
using namespace std;

template <typename T>
struct BinaryTreeNode {
    T data;
    unique_ptr<BinaryTreeNode<T>> left,right;
};


unique_ptr<BinaryTreeNode<int>> BinaryTreeHelper(const vector<int> &preorder, size_t preorder_start, size_t preorder_end,
                                                 size_t inorder_start, size_t inorder_end, unordered_map<int, int> node_to_indorder_index) {
    
    cout<<"PreStart - "<<preorder_start<<",PreEnd - "<<preorder_end<<",InStart - "<<inorder_start<<",InEnd - "<<inorder_end<<endl;
    if(preorder_end <= preorder_start || inorder_end<=inorder_start)
        return nullptr;
    
    cout<<"Preorder[preStart] - "<<preorder[preorder_start]<<endl;
    size_t root_inorder_index = node_to_indorder_index.at(preorder[preorder_start]);
    cout<<"Inorder root index - "<<root_inorder_index<<endl;
    size_t left_tree_size = root_inorder_index - inorder_start;
    
    return make_unique<BinaryTreeNode<int>>(BinaryTreeNode<int>{
        preorder[preorder_start],
        BinaryTreeHelper(preorder, preorder_start+1, preorder_start+1+left_tree_size, inorder_start, root_inorder_index, node_to_indorder_index),
        BinaryTreeHelper(preorder, preorder_start+1+left_tree_size, preorder_end, root_inorder_index+1, inorder_end, node_to_indorder_index)
    });
}


unique_ptr<BinaryTreeNode<int>> BinaryTreeFromInorderPreorder(const vector<int> &inorder,
                                                              const vector<int> &preorder) {
    
    unordered_map<int,int> node_to_inorder_index;
    for(size_t i = 0;i<inorder.size();i++){
        node_to_inorder_index.emplace(inorder[i],i);
    }
    
    return BinaryTreeHelper(preorder,0,preorder.size(),0,inorder.size(),node_to_inorder_index);
}


void Traversal(const unique_ptr<BinaryTreeNode<int>> &root) {
    if(root) {
        Traversal(root->left);
        cout<<root->data<<" ";
        Traversal(root->right);
    }
}

int main() {
    const vector<int> inorder = {6,2,1,5,8,3,4,9,7};
    const vector<int> preorder = {8,2,6,5,1,3,4,7,9};
    unique_ptr<BinaryTreeNode<int>> root = BinaryTreeFromInorderPreorder(inorder,preorder);
    Traversal(root);
    return 0;
}
