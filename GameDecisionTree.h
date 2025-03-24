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

public:
    // TODO: Constructor
    GameDecisionTree() : root(nullptr) {}

    // TODO: Function to load story data from a text file and build the binary tree
    void loadStoryFromFile(const std::string& filename, char delimiter) {
        string line;
        //Load file
        ifstream file("filename.txt");
        //check if file was opened
        if (!file.is_open()) {
            cout << "File could not be opened";
            return;
        }
        //Create temp vars for description, event #, left #, right #, go through each line
        while (getline(file,line)) {
            stringstream ss(line);
            string part;
            int values[4];
            int i = 0;

            //set values list to each value in the line
            while (getline(ss, part, delimiter) && i < 4) {
                values[i++] = stoi(part);
            }
            Story *tempStory = new Story(std::to_string(values[0]), values[1], values[2], values[3]);
            Node<Story> *node = new Node<Story>(*tempStory);

            Node
            if (node->data.eventNumber < root->data.eventNumber) {
                while (node->left != nullptr) {

                }
            }

        }

    }

    // TODO: Function to start the game and traverse the tree based on user input
    void playGame() {

    }
};

#endif // GAMEDECISIONTREE_H