/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
	vector<int> preorderTraversal(TreeNode* root) {
		stack<TreeNode*> s;
		TreeNode* pCur = root;;
		s.push(root);
		vector<int> v;
		while (!s.empty() && pCur)
		{
			pCur = s.top();
			v.push_back(pCur->val);
			s.pop();

			if (pCur->right)
				s.push(pCur->right);
			if (pCur->left)
				s.push(pCur->left);
		}
		return v;
	}
	/*        vector<int> v;
			preOrder(v,root);
			return v;
		}
		void  preOrder(vector<int>& v,TreeNode* root)
		{
			if(root)
			{
				v.push_back(root->val);
				preOrder(v,root->left);
				preOrder(v,root->right);
			}
		}
		*/


};


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 /////////////////////////////////////
 /////////////////////////////////////
 ////////////////////////////////////


class Solution {
public:
	vector<int> inorderTraversal(TreeNode* root) {
		vector<int> v;
		stack<TreeNode*> s;
		TreeNode* pCur = root;
		if (root)
		{
			while (pCur || !s.empty())
			{
				//×ó
				while (pCur)
				{
					s.push(pCur);
					pCur = pCur->left;
				}
				//¸ù
				pCur = s.top();
				v.push_back(pCur->val);
				s.pop();
				//ÓÒ
				pCur = pCur->right;
			}
		}
		return v;
		/*
			   vector<int> v;
			   InOrder(v,root);
			   return v;
		   }
		   void InOrder(vector<int>& v,TreeNode* root)
		   {
			   if(root)
			   {
				   InOrder(v,root->left);
				   v.push_back(root->val);
				   InOrder(v,root->right);
			   }
		   }
		*/
	}
};











/////////////////////////////////////
/////////////////////////////////////
////////////////////////////////////
class Solution {
public:
	vector<int> postorderTraversal(TreeNode* root) {
		vector<int> v;
		stack<TreeNode*> s;
		TreeNode* pCur = root;
		TreeNode* pPre = NULL;

		if (root)
		{
			while (pCur || !s.empty())
			{
				while (pCur)
				{
					s.push(pCur);
					pCur = pCur->left;
				}
				TreeNode* pTop = s.top();
				if (pTop->right == NULL || pPre == pTop->right)
				{
					v.push_back(pTop->val);
					pPre = pTop;
					s.pop();
				}
				else
				{
					pCur = pTop->right;
				}
			}

		}
		return v;
	}
	/*
		vector<int> v;
		PostOrder(v,root);
		return v;
	}

	void PostOrder(vector<int>& v,TreeNode* root)
	{
		if(root)
		{
			PostOrder(v,root->left);
			PostOrder(v,root->right);
			v.push_back(root->val);
		}
	}
	*/
};

/////////////////////////////////////
/////////////////////////////////////
////////////////////////////////////
class Solution {
public:
	vector<vector<int>> levelOrder(TreeNode* root) {
		vector<vector<int>> vv;
		if (root == nullptr)
			return vv;

		queue<TreeNode*> q;
		q.push(root);
		while (!q.empty())
		{
			vector<int> v;
			int start = 0;
			int end = q.size();
			while (start++ < end)
			{
				TreeNode* pCur = q.front();
				q.pop();
				v.push_back(pCur->val);
				if (pCur->left)
					q.push(pCur->left);
				if (pCur->right)
					q.push(pCur->right);
			}
			vv.push_back(v);
		}
		return vv;
	}
};