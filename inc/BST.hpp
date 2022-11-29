// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   BST.hpp                                            :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: raweber <raweber@student.42wolfsburg.de    +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2022/11/26 16:36:47 by raweber           #+#    #+#             */
// /*   Updated: 2022/11/28 11:44:11 by raweber          ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

#pragma once
#include "utils.hpp"
// #include "map_iterator.hpp"
#include <memory>
#include <functional>

namespace ft
{
	
	template< typename Key, typename T, typename Compare = std::less<Key>, typename Alloc = std::allocator<pair<const Key, T> > >
	class BST {

		public:
			typedef Key													key_type;
			typedef T													mapped_type;
			typedef pair<const Key, T>									value_type;
			typedef std::size_t											size_type;
			typedef std::ptrdiff_t										difference_type;
			typedef Compare												key_compare;
			typedef Alloc												alloc_type;
			typedef typename Alloc::reference							reference;
			typedef typename Alloc::const_reference						const_reference;
			typedef typename Alloc::pointer								pointer;
			typedef typename Alloc::const_pointer						const_pointer;
		

//---------------------------NODE DECLARATION---------------------------------------//

			struct Node {
				value_type	content;
				Node*		left;
				Node*		right;
			};

//---------------------------MEMBER VARIABLES---------------------------------------//

		private: //make public?
			key_compare				m_comp;
			size_type				m_tree_size;
			std::allocator<Node>	m_node_alloc;
			alloc_type				m_alloc;


		public:
			Node	*m_tree_root;

//---------------------------CONSTRUCTORS---------------------------------------//

		public:

			BST(const Compare& comp = Compare()) : m_comp(comp), m_tree_size(0), m_tree_root(NULL) {}


//---------------------------------------DESTRUCTOR-------------------------------------------//


			~BST() {} // clear() will be called from map class
			
			
//---------------------------COPY ASSIGNMENT OPERATOR----------------------------------------//


//-------------------------------GET ALLOC-----------------------------------------------//


//---------------------------ELEMENT ACCESS----------------------------------------//


//---------------------------ITERATOR FUNCTIONS----------------------------------------//

			Node *begin(void) const {
				
				Node *tmp = m_tree_root;
				while (tmp && tmp->left)
					tmp = tmp->left;
				return (tmp);
			}

			Node *end(void) const {
				
				Node *tmp = m_tree_root;
				while (tmp && tmp->right)
					tmp = tmp->right;
				return (tmp->right);
			}

			Node *plusPlus(Node *current) {

				Node *tmp = m_tree_root;
				while (tmp->content < current->content)
					tmp = tmp->right;
			}

//---------------------------CAPACITY----------------------------------------//

			bool empty() const { return !m_tree_size; }

			size_type size() const { return m_tree_size; }

//---------------------------MODIFIERS----------------------------------------//

			Node *createNewNode(const value_type &new_content) {
				
				Node *newNode = m_node_alloc.allocate(1);
				m_alloc.construct(&(newNode->content), new_content);
				newNode->left = NULL;
				newNode->right = NULL;
				return (newNode);
			}


			Node *insertNode(Node **m_root, const value_type &data) {
				
				if (*m_root == NULL)
					*m_root = createNewNode(data);
				else if (this->m_comp(data, (*m_root)->content))
				{
					(*m_root)->left = insertNode(&(*m_root)->left, data);
					m_tree_size++;
				}
				else if (this->m_comp((*m_root)->content, data))
				{
					(*m_root)->right = insertNode(&(*m_root)->right, data);
					m_tree_size++;
				}
				return (*m_root);
			}

//---------------------------LOOKUP----------------------------------------//


//---------------------------OBSERVERS----------------------------------------//


			bool sameNodeExists(Node *m_root, const value_type &data) {
				
				if (m_root == NULL)
					return false;
				if (m_root->content == data)
					return true;
				else if (m_root->content <= data)
					return sameNodeExists(m_root->left, data);
				else
					return sameNodeExists(m_root->right, data);
			}


			bool sameKeyExists(Node *m_root, const key_type &data) {
				
				if (m_root == NULL)
					return false;
				if (m_root->content.first == data)
					return true;
				else if (m_root->content.first <= data)
					return sameKeyExists(m_root->left, data);
				else
					return sameKeyExists(m_root->right, data);
			}


			void printTreeRecursive(const std::string& prefix, Node *m_root, bool isLeft) const {
				
				if (m_root)
				{
					std::cout << prefix;
					std::cout << (isLeft ? "├──" : "└──");
					std::cout << "(" << m_root->content.first << ")>[" << m_root->content.second << "] " << std::endl;
					// if (m_root->left)
					printTreeRecursive(prefix + (isLeft ? "│   " : "    "), m_root->left, true);
					// if (m_root->right)
					printTreeRecursive(prefix + (isLeft ? "│   " : "    "), m_root->right, false);	
				}
			}


			void printTree(void) const {
			
				printTreeRecursive("", m_tree_root, false);
			}


			Node *getRoot(void) { return m_tree_root; }

			

	};
	
} // namespace ft
