// Q31. Write a function that takes a string and returns true if its parenthesis are balanced.
// A:
#include <string>
#include <stack>
using namespace std;

bool is_par_balanced(const string input)
{
	// "())())" => false
	// "(a(dd)()(()))" => true
	stack<char> par_stack;
	for(auto &c:input)
	{
		if(c==')')
		{
			if(par_stack.empty())
				return false;
			else if(par_stack.top()=='(')
				par_stack.pop();
		}
		else if(c=='(')
			par_stack.push(c);
	}
	return par_stack.empty();
}

// Q32. Write a function that returns the height of an arbitrary binary tree.
// A:
#include <memory> //std::shared_ptr
#include <algorithm> //std::max
using namespace std;

template <typename T>
struct BinaryTree
{
	/* data */
	T data;
	shared_ptr<BinaryTree<T>> left, right;
};

template <typename T>
int height(const shared_ptr<BinaryTree<T>> &tree, int count = -1){
	if(!tree) return count;
	return max(
		height(tree->left, count+1),
		height(tree->right, count+1));
}