[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/jIKk4bke)
# CS210 Data Structures SP25
## Programming Assignment 2: Text-Based RPG Using Decision Trees

### **Student Name:** `Priyesh Patel`  
### **Student ID:** `131613518`  

---

## **1. Project Overview**
This project implements a text-based RPG using a binary decision tree where the player takes on the role of a mercenary climbing the Tower of Ash . The game events are represented with node corresponds to a unique event with two possible outcomes. At each stage, the player chooses between two paths (left or right), influencing the story and their character's progression. The decision tree is built by parsing an external text file (mystory1.txt), which contains the event descriptions and branching logic. The game ends when the player reaches a leaf node. The tree also includes one shared child node.
---

## **2. Folder & File Structure**
(Explain the role of each file in your project.)

- **`main.cpp`** → `This is where the game starts. It loads the story from mystory1.txt using the decision tree and calls the play function to begin the RPG.`  
- **`GameDecisionTree.h`** → `ontains the GameDecisionTree class, which is responsible for building the binary tree from the story file and handling gameplay traversal based on player input. It ties everything together.`  
- **`Node.h`** → `Defines a templated Node<T> class that represents each node in the decision tree. Each node holds a Story object and has pointers to its left and right child events.`  
- **`Story.h`** → `Declares the Story class, which stores information about each game event, including its description, event number, and the event numbers for the next left and right choices. It’s used as the data type inside each node.`  
- **`story.txt`** → ` Holds all the actual story events. Each line describes an event and its branching options using the format: eventNumber|description|leftEvent|rightEvent. This file drives the game’s structure and is loaded at runtime.`  

---

## **3. Decision Tree Construction**

- How are `Story` objects created from the text file?  
- Each line of the story.txt file is split using a delimiter (|). The line is parsed into four parts: the event number, the description, and the left and right event numbers. These values are passed into the Story class constructor to create a Story object that represents that event in the game.
- How are nodes linked based on left and right event numbers?  
- As the tree is built, each Story object is wrapped inside a Node<Story>. If the left or right event number isn't -1, the program checks if a node for that event number already exists. If not, it creates a placeholder node. Then, it connects the current node's left and right pointers to the corresponding child nodes based on those event numbers. This builds the structure of the binary tree.
- What happens if an event has `-1` as left or right children?  
- A -1 means that there’s no further event in that direction — it marks a leaf node. If both left and right are -1, that node is a dead end in the story, and the game ends once the player reaches it.

---

## **4. Game Traversal**
(Describe how the game moves through the decision tree.)

- How does user input determine the path taken?  
- The player enters 1 to go left or 2 to go right. The game follows the chosen path in the tree.
- What happens when the player reaches a leaf node?  
-  The game ends and the final event description is shown.
- Explain the special case where multiple events lead to the same outcome.  
- Two or more events point to the same node, reusing it instead of creating a duplicate.

---

## **5. File Parsing & Data Loading**
(Explain the process of reading `story.txt` and constructing the decision tree.)

- How is the file read and parsed using a delimiter?  
- The file is opened using std::ifstream, and each line is read with std::getline(). A std::stringstream is then used to split each line into parts using std::getline(ss, token, delimiter) for the | delimiter. The string parts are converted into integers using std::stoi() for the event numbers
- How do you ensure nodes are properly linked?  
- A map stores nodes by event number so they can be reused and linked correctly as left or right children.
- Any challenges faced while handling file input?  
- I forgot to close the file which caused the error and had errors with having the wrong input types when ggettign the input also figuring out how to use the delimiters to get each of the variables caused errors.

---

## **6. Debugging Process (Errors & Fixes)**
(Describe one or more debugging challenges you faced and how you fixed them.)

Example:
When I was testing my  load method i used stoi incorrectly and tried to convert a invalid string. This happend because I called it on a variable that didnt need to be changed. I delete this call to fix the problem. 

---

## **7. Sample Output & Walkthrough**
Example:
You stand before the Tower of Ash — its top lost in the clouds. A door creaks open.

What do you want to do?
1. Go left
2. Go right
   Enter choice: 1

A goblin ambushes you in the crumbling entrance hall.

What do you want to do?
1. Go left
2. Go right
   Enter choice: 2

You avoid confrontation but feel a dark presence watching.

What do you want to do?
1. Go left
2. Go right
   Enter choice: 1

A stone altar offers a blessing for a price. Carve your name or walk past?

What do you want to do?
1. Go left
2. Go right
   Enter choice: 2

You leave the altar untouched. A chill follows you as you climb.
---

## **8. Big-O Analysis of Core Methods**
(Analyze the complexity of key methods.)

- **Loading the tree from the file** → `O(n)`  
- **Searching for an event in the tree** → `O(1)`  
- **Game traversal efficiency** → `O(h)` - height of tree  

---

## **9. Edge Cases & Testing**

---

## **10. Justification of Additional Features (If Any)**
I didnt add any addition features
---

## **Final Notes**
- **README is mandatory** → `(-10 points deduction if missing).`  
- **Code must compile and run** → `(Code that does not run will receive a 0).`  
- **Do not modify provided skeleton code** → `(You may only add to it).`  

---
