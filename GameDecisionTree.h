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
    std::unordered_map<Node<T>*, Node<T>*> nodeMap;

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
            std::string eventStr, description, leftStr, rightStr;

            //Get current node and left and right node
            int number = std::stoi(eventStr);
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

            Node<T>* currentNode = nodeMap[number];

            // Create or link right child
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

    }
};

#endif // GAMEDECISIONTREE_H