/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BST.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raweber <raweber@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 16:36:47 by raweber           #+#    #+#             */
/*   Updated: 2022/11/28 11:44:11 by raweber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "utils.hpp"
#include "iterator.hpp"
#include <memory>

namespace ft
{
	
	template<typename T>
	struct Node {
		T		content;
		Node*	left;
		Node*	right;
	};

	template<typename Key, typename T, typename Alloc = std::allocator<Node<Key, T> > >
	class BinarySearchTree {

//---------------------------END MAP MEMBER FUNCTION TRANSLATIONS----------------------------------------//
	
		public:
			BinarySearchTree() : m_root(NULL), m_size(0) {}
			~BinarySearchTree() {} // destroy stuff here!
			
			

			
			Node<Key, T> *createNewNode(pair<Key, T> new_content) {
				
				Node<Key, T> *newNode = m_alloc.allocate(1);
				m_alloc.construct(newNode);
				newNode->content = new_content;
				newNode->left = NULL;
				newNode->right = NULL;
				return (newNode);
			}

			// HERE!!! DOUBLE OR SINGLE POINTER???
			Node<Key, T> *insertNode(Node<Key, T> **m_root, pair<Key, T> data) {
				
				if (*m_root == NULL)
					*m_root = createNewNode(data);
				else if (data <= (*m_root)->content)
					(*m_root)->left = insertNode(&(*m_root)->left, data);
				else
					(*m_root)->right = insertNode(&(*m_root)->right, data);
				m_size++;
				return (*m_root);
			}

			bool searchNode(Node<Key, T> *m_root, pair<Key, T> data) {
				
				if (m_root == NULL)
					return false;
				if (m_root->content == data)
					return true;
				else if (m_root->content <= data)
					return searchNode(m_root->left);
				else
					return searchNode(m_root->right);
			}

			void printTree(const std::string& prefix, Node<Key, T> *m_root, bool isLeft) {
				
				if (m_root)
				{
					std::cout << prefix;
					std::cout << (isLeft ? "├──" : "└──");
					std::cout << "(" << m_root->content.first << ")>[" << m_root->content.second << "] " << std::endl;
					// if (m_root->left)
					printTree(prefix + (isLeft ? "│   " : "    "), m_root->left, true);
					// if (m_root->right)
					printTree(prefix + (isLeft ? "│   " : "    "), m_root->right, false);	
				}
			}

			Node<Key, T> *getRoot(void) { return m_root; }

		
		public:
			Node<Key, T>	*m_root;
			size_t			m_size;
			Alloc			m_alloc;
	};
	
} // namespace ft

