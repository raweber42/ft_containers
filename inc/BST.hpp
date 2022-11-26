/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BST.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raweber <raweber@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 16:36:47 by raweber           #+#    #+#             */
/*   Updated: 2022/11/26 18:56:57 by raweber          ###   ########.fr       */
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

	template<typename Key, typename T>
	class BinarySearchTree {

		public:
			BinarySearchTree() : root(NULL) {}
			~BinarySearchTree() {} // destroy stuff here!
			
			Node<Key, T> *createNewNode(pair<Key, T> new_content) {
				
				Node<Key, T> *newNode = new Node<Key, T>;
				newNode->content = new_content;
				newNode->left = NULL;
				newNode->right = NULL;
				return (newNode);
			}

			// HERE!!! DOUBLE OR SINGLE POINTER???
			Node<Key, T> *insertNode(Node<Key, T> *root, pair<Key, T> data) {
				
				if (root == NULL)
					root = createNewNode(data);
				else if (data <= root->content)
					root->left = insertNode(root->left, data);
				else
					root->right = insertNode(root->right, data);
				return (root);
			}

			bool searchNode(Node<Key, T> *root, pair<Key, T> data) {
				
				if (root == NULL)
					return false;
				if (root->content == data)
					return true;
				else if (root->content <= data)
					return searchNode(root->left);
				else
					return searchNode(root->right);
			}

		
		public:
			Node<Key, T> *root;
		
	};
	
} // namespace ft

