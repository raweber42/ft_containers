/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BST.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raweber <raweber@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 16:36:47 by raweber           #+#    #+#             */
/*   Updated: 2022/11/26 17:06:53 by raweber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "utils.hpp"

namespace ft
{
	
	template<typename Key, typename T>
	struct Node {
		pair<Key, T>	content;
		Node			*left;
		Node			*right;
	};

	template<typename T>
	class BinarySearchTree {

		BinarySearchTree() : root(NULL) {}
		~BinarySearchTree() {} // destroy stuff here!
		
		Node *createNewNode(T new_content) {
			
			Node *newNode = new Node();
			newNode->content = new_content;
			newNode->left = NULL;
			newNode->right = NULL;
			return (newNode);
		}

		void insertNode(T data) {
			
			if (root == NULL)
				root = createNewNode(data);
			else if (data <= root->data)
				root->left = insertNode(root->left, data);
			else
				root->right = insertNode(root->right, data);
			return (root);
		}

		bool searchNode(T data) {
			
			if (root == NULL)
				return false;
			if (root->data == data)
				return true;
			else if (root->data <= data)
				return searchNode(root->left);
			else
				return searchNode(root->right);
		}

		
		private:
			Node *root;
		
	};
	
} // namespace ft

