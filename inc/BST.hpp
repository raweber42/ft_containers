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

#ifndef BST_HPP
#define BST_HPP

#include "utils.hpp"
#include <iostream>
// #include "map_iterator.hpp"
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

//---------------------------CONSTRUCTORS---------------------------------------//

		public:

			BST(const Compare& comp = Compare()) : m_comp(comp), m_tree_size(0), m_tree_root(NULL) {}


//---------------------------------------DESTRUCTOR-------------------------------------------//


			~BST() {} // clear() will be called from map class
			
			
//---------------------------COPY ASSIGNMENT OPERATOR----------------------------------------//

			void copyTree(Node *root = NULL) {
				
				if (root == NULL)
					return;
				insertNode(&m_tree_root, root->content);
				copyTree(root->left);
				copyTree(root->right);
			}

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


			Node *createNewNode(const value_type &new_content, Node *parent = NULL) {
				
				Node *newNode = m_node_alloc.allocate(1);
				m_alloc.construct(&(newNode->content), new_content);
				newNode->left = NULL;
				newNode->right = NULL;
				newNode->parent = parent;
				return (newNode);
			}

			Node *insertNode(Node **m_root, const value_type &data, Node *parent = NULL) {
				
				if (*m_root == NULL) //here parent is set to NULL
				{
					*m_root = createNewNode(data, parent);
					m_tree_size++;
				}

				else if (m_comp(data.first, ((*m_root)->content).first))
				{
					(*m_root)->left = insertNode(&(*m_root)->left, data, *m_root);
				}
				else if (m_comp(((*m_root)->content).first, data.first))
				{
					(*m_root)->right = insertNode(&(*m_root)->right, data, *m_root);
				}
				return (*m_root);
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

			
			// MY OLD VERSION
			// node_pointer erase(key_type key, node_pointer root) {

			// 	if (root == NULL)
			// 		return (NULL);
			// 	if (m_comp(key, root->content.first))
			// 		root->left = erase(key, root->left);
			// 	else if (m_comp(root->content.first, key))
			// 		root->right = erase(key, root->right);
			// 	else {
			// 		if (root->left == NULL && root->right == NULL) {
			// 			m_node_alloc.destroy(root);
			// 			m_node_alloc.deallocate(root, 1);
			// 			root = NULL;
			// 		}
			// 		else if (root->right != NULL) { // check with ->left 
			// 			m_alloc.destroy(&(root->content));
			// 			m_alloc.construct(&(root->content), successor(root));
			// 			root->right = erase(root->content.first, root->right);
			// 		}
			// 		else {
			// 			m_alloc.destroy(&(root->content));
			// 			m_alloc.construct(&(root->content), predecessor(root));
			// 			root->left = erase(root->content.first, root->left);
			// 		}
			// 	}
			// 	return (root);
			// }

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
				// m_tree_size--; // needed?
			}

			void deleteAll(Node *root = NULL) {
				
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


			bool sameNodeExists(const value_type &data, Node *m_root) const {
				
				if (m_root == NULL)
					return false;
				if (m_root->content == data) // user COMP here! ASK MAGGI!
					return true;
				else if (m_root->content <= data) // user COMP here! ASK MAGGI!
					return sameNodeExists(data, m_root->right);
				else
					return sameNodeExists(data, m_root->left);
			}


			bool sameKeyExists(const key_type &data, Node *m_root) const {
				
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
				// if (m_root == NULL)
				// 	return end();
				// if (m_root->content.first == data) // use COMP here! ASK MAGGI!
				// 	return m_root;
				// else if (m_root->content.first <= data) // use COMP here! ASK MAGGI!
				// 	return findKey(data, m_root->right);
				// else
				// 	return findKey(data, m_root->left);
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


			Node *getRoot(void) const { return m_tree_root; }

			

	};
	
} // namespace ft

#endif