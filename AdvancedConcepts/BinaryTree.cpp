//#include <iostream>
//
////-- BINARY SEARCH TREE
//
//class BstNode{
//public:
//	BstNode* left;
//	BstNode* right;
//	int data;
//	BstNode();
//	~BstNode();
//	int finMin(BstNode* root);
//	int finMax(BstNode* root);
//};
//
//BstNode::BstNode(){
//}
//
//BstNode::~BstNode(){
//}
//
//int BstNode::finMin(BstNode* root){
//
//	int min = 0;
//
//	if (root->left == NULL){ //-- we reached the end of the tree
//		return root->data;
//	}
//
//	else
//	{
//		while (root->left != NULL)
//		{
//			return this->finMin(root->left);
//		}
//	}
//}
//
//int BstNode::finMax(BstNode* root){
//
//	int min = 0;
//
//	if (root->right == NULL){ //-- we reached the end of the tree
//		return root->data;
//	}
//
//	else
//	{
//		while (root->right != NULL)
//		{
//			return this->finMin(root->right);
//		}
//	}
//}
//
//
//int main(int* argc, char* argv[])
//{
//	return 0;
//}