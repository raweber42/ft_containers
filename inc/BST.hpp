/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BST.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raweber <raweber@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 16:36:47 by raweber           #+#    #+#             */
/*   Updated: 2022/12/08 15:34:11 by raweber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BST_HPP
#define BST_HPP

#include "utils.hpp"
#include <iostream>
#include <memory>
#include <functional>

namespace ft
{
	template< typename Key, typename T, typename Compare = std::less<Key>, typename Alloc = std::allocator<ft::pair<const Key, T> > >
	class BST {

//---------------------------NODE DECLARATION---------------------------------------//

		public:

			struct Node {
				ft::pair<const Key, T>	content;
				Node*					left;
				Node*					right;
				Node*					parent;
			};
			
			typedef Key													key_type;
			typedef T													mapped_type;
			typedef pair<const Key, T>									value_type;
			typedef std::size_t											size_type;
			typedef std::ptrdiff_t										difference_type;
			typedef Compare												key_compare;
			typedef Alloc												alloc_type;
			typedef typename Alloc::reference		 					reference;
			typedef typename Alloc::const_reference						const_reference;
			typedef typename Alloc::pointer								pointer;
			typedef typename Alloc::const_pointer						const_pointer;
			typedef Node*												node_pointer;
			typedef const Node*											const_node_pointer;
		


//---------------------------MEMBER VARIABLES---------------------------------------//


		public: //make public?
			key_compare				m_comp;
			size_type				m_tree_size;
			std::allocator<Node>	m_node_alloc;
			alloc_type				m_alloc;


		public:
			Node	*m_tree_root;


//---------------------------CONSTRUCTOR---------------------------------------//

		public:
			BST(const Compare& comp = Compare()) : m_comp(comp), m_tree_size(0), m_tree_root(NULL) {}


//---------------------------------------DESTRUCTOR-------------------------------------------//


			~BST() {} // clear() will be called from map class
			
			
//---------------------------COPY ASSIGNMENT OPERATOR----------------------------------------//


			BST& operator=( const BST& rhs ) {
				
				
				deleteAll();
				copyTree(rhs.getRoot());
				return (*this);
			}
			
			void copyTree(node_pointer root = NULL) {
				
				if (root == NULL)
					return;
				insertNode(root->content);
				copyTree(root->left);
				copyTree(root->right);
			}


//-------------------------------GET ALLOC-----------------------------------------------//


//---------------------------ELEMENT ACCESS----------------------------------------//


//---------------------------ITERATOR FUNCTIONS----------------------------------------//


			node_pointer begin(void) const {
				
				node_pointer tmp = m_tree_root;
				while (tmp && tmp->left)
					tmp = tmp->left;
				return (tmp);
			}

			node_pointer end(void) const {
				
				node_pointer tmp = m_tree_root;
				if (!tmp)
					return (NULL);
				while (tmp && tmp->right)
					tmp = tmp->right;
				return (tmp->right);
			}


//---------------------------CAPACITY----------------------------------------//


			bool empty() const { return !m_tree_size; }

			size_type size() const { return m_tree_size; }

			size_type max_size() const { return m_alloc.max_size();	}


//---------------------------MODIFIERS----------------------------------------//


			node_pointer createNewNode(const value_type &new_content, node_pointer parent = NULL) {
				
				node_pointer newNode = m_node_alloc.allocate(1);
				m_alloc.construct(&(newNode->content), new_content);
				newNode->left = NULL;
				newNode->right = NULL;
				newNode->parent = parent;
				m_tree_size++;
				return (newNode);
			}

			node_pointer insertNode(const value_type &data) {
				
				if (m_tree_root == NULL)
				{
					m_tree_root = createNewNode(data);
					return (m_tree_root);
				}

				node_pointer found = findKey(data.first);
				node_pointer tmp = NULL;
				if (found)
					return (found);
				found = m_tree_root;
				while (found != NULL) {
					tmp = found;
					if (data.first < found->content.first)
						found = found->left;
					else
						found = found->right;
				}
				found = createNewNode(data, tmp);
				if (data.first < tmp->content.first)
					tmp->left = found;
				else
					tmp->right = found;
				return (found);
			}

			value_type successor(node_pointer root) {

				root = root->right;
				while (root->left)
					root = root->left;
				return (root->content);
			}

			value_type predecessor(node_pointer root) {

				root = root->left;
				while (root->right)
					root = root->right;
				return (root->content);
			}

			
//++++++++++++++++++++EDGARS STYLE BEGIN+++++++++++++++++++++++++++
		

			node_pointer maxNode(node_pointer curr) {
				
				while (curr && curr->right)
					curr = curr->right;
				return (curr);
			}

			node_pointer minNode(node_pointer curr) {
				
				while (curr && curr->left)
					curr = curr->left;
				return (curr);
			}

			void deleteNode(node_pointer to_delete) {

				node_pointer tmp = NULL;
				if (!to_delete)
					return;
				if (!to_delete->left && !to_delete->right)
					deleteLeaf(to_delete);
				else {
					if (to_delete->left) {
						tmp = maxNode(to_delete->left);
					}
					else if (to_delete->right) {
						tmp = minNode(to_delete->right);
					}
					m_alloc.construct(&(to_delete->content), tmp->content);
					deleteNode(tmp);
				}
			}

			size_type erase(const key_type &key) {

				node_pointer found = findKey(key);

				if (!m_tree_root || !found)
					return (0);
				deleteNode(found);
				return (1);
			}

			void swap( BST& other ) {
				
				if (this == &other) return;
				std::swap(this->m_tree_root, other.m_tree_root);
				std::swap(this->m_tree_size, other.m_tree_size);
			}


//++++++++++++++++++++EDGARS STYLE END+++++++++++++++++++++++++++++


			void deleteLeaf(node_pointer to_delete) {

				if (to_delete == NULL)
					return;
				node_pointer parent = to_delete->parent;
				if (parent == NULL)
					m_tree_root = NULL;
				else if (to_delete == parent->left)
					parent->left = NULL;
				else if (to_delete == parent->right)
					parent->right = NULL;
				m_node_alloc.destroy(to_delete);
				m_node_alloc.deallocate(to_delete, 1);
			}

			void deleteAll(node_pointer root = NULL) {
				
				if (root == NULL)
					root = m_tree_root;
				if (root == NULL)
					return;
				if (root->left != NULL)
					deleteAll(root->left);
				if (root->right != NULL)
					deleteAll(root->right);
				deleteLeaf(root);				
			}


//---------------------------LOOKUP----------------------------------------//




//---------------------------OBSERVERS----------------------------------------//


			bool sameKeyExists(const key_type &data, node_pointer m_root) const {
				
				if (m_root == NULL)
					return false;
				if (m_root->content.first == data) // user COMP here! ASK MAGGI!
					return true;
				else if (m_root->content.first <= data) // user COMP here! ASK MAGGI!
					return sameKeyExists(data, m_root->right);
				else
					return sameKeyExists(data, m_root->left);
			}

			node_pointer findKey(const key_type &key) const {
				
				node_pointer tmp = m_tree_root;

				while ( tmp != NULL && tmp->content.first != key)
				{
					if (m_comp(key, tmp->content.first))
						tmp = tmp->left;
					else
						tmp = tmp->right;
				}
				return (tmp);
			}


			void printTreeRecursive(const std::string& prefix, node_pointer m_root, bool isLeft) const {
				
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


			node_pointer getRoot(void) const { return m_tree_root; }
	

	};
	
} // namespace ft

#endif