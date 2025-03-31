#ifndef GAMEDECISIONTREE_H
#define GAMEDECISIONTREE_H

#include <unordered_map>
#include <fstream>
#include <sstream>
#include <iostream>
#include "Node.h"
#include "Story.h"

template <typename T>
class GameDecisionTree {
private:
    Node<T>* root;
    //For the tree
    std::unordered_map<int, Node<T>*> nodeMap;

public:
    // TODO: Constructor
    GameDecisionTree() : root(nullptr) {}

    // TODO: Function to load story data from a text file and build the binary tree
    void loadStoryFromFile(const std::string& filename, char delimiter) {
        //open file
        std::ifstream file(filename);
        //if file is not open print output failed to open file
        if (!file.is_open()) {
            std::cerr << "Failed to open file: " << filename << std::endl;
            return;
        }
        //vairable for each line
        std::string line;
        //look while there are lines
        while (std::getline(file, line)) {
            //variable for string stream, variables for inputs
            std::stringstream ss(line);
            std::string eventNum, description, leftStr, rightStr;
            //get info
            std::getline(ss, eventNum, delimiter);
            std::getline(ss, description, delimiter);
            std::getline(ss, leftStr, delimiter);
            std::getline(ss, rightStr, delimiter);
            //set current node and left and right node
            int number = std::stoi(eventNum);
            int leftEventNumber = std::stoi(leftStr);
            int rightEventNumber = std::stoi(rightStr);

            //create story variable with the inputs
            T story(description,number ,leftEventNumber, rightEventNumber);

            // Create node for this event if it doesn't exist
            if (nodeMap.find(number) == nodeMap.end()) {
                nodeMap[number] = new Node<T>(story);
            } else {
                nodeMap[number]->data = story;
            }
			//set pointer of the current node to the node map at this event number
            Node<T>* currentNode = nodeMap[number];

            // Create or link left and right child
            //check if valid left child
            if (leftEventNumber != -1) {
                //if node with the left event number doesnt already exist you have to create it
    			if (nodeMap.find(leftEventNumber) == nodeMap.end()) {
      	  		nodeMap[leftEventNumber] = new Node<T>(T());
   				 }
                                 //link the current nodes left to the where the left event number is in the node map
    		currentNode->left = nodeMap[leftEventNumber];
			}

                        //same process as adding the left child
			if (rightEventNumber != -1) {
   			 if (nodeMap.find(rightEventNumber) == nodeMap.end()) {
       			 nodeMap[rightEventNumber] = new Node<T>(T());
  				  }
   			 currentNode->right = nodeMap[rightEventNumber];
				}


            // Set root from the first event processed
            if (!root) {
                root = currentNode;
            }
        }
        //remeber to close file
        file.close();


    }



    // TODO: Function to start the game and traverse the tree based on user input
    void playGame() {
        // Check if the tree has been loaded
        if (!root) {
            std::cout << "Game tree is empty. Load a story first.\n";
            return;
        }

        // Start at the root node
        Node<T>* current = root;

        // Traverse the tree based on player choices
        while (current) {
            // Print the current event description
            std::cout << current->data.description << std::endl;

            // If we've reached a leaf node, end the game
            if (!current->left && !current->right) {
                std::cout << "\n--- End of Story ---\n";
                break;
            }

            // Display options for the player
            std::cout << "\nWhat do you want to do?\n";
            std::cout << "1. Go left\n";
            std::cout << "2. Go right\n";
            std::cout << "Enter choice: ";

            int choice;
            std::cin >> choice;

            // Move to the corresponding child node based on choice
            if (choice == 1 && current->left) {
                current = current->left;
            } else if (choice == 2 && current->right) {
                current = current->right;
            } else {
                // Invalid choice or no path in that direction
                std::cout << "Invalid choice or no further path. Game over.\n";
                break;
            }

            std::cout << "\n";
        }
    }
};

#endif // GAMEDECISIONTREE_H