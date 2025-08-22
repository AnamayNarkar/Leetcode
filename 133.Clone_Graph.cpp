// Clone Graph - deep copy

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
private:
    unordered_map<int,Node*> mapping;
    queue<Node*> myQueue;
    unordered_set<int> visited;
public:
    Node* cloneGraph(Node* node) {
        if(node==nullptr || node->neighbors.empty()){
            return node==nullptr ? nullptr : new Node(1,{});
        }

        myQueue.push(node);

        while(!myQueue.empty()){
            Node* tempNode = myQueue.front();
            myQueue.pop();

            if (visited.find(tempNode->val) != visited.end()) {
                continue;
            }

            if(this->mapping.find(tempNode->val)==this->mapping.end()){
                this->mapping[tempNode->val]=new Node(tempNode->val);
            }

            this->visited.insert(tempNode->val);

            for(Node* temp: tempNode->neighbors){
                if(this->visited.find(temp->val)==this->visited.end()){
                    this->myQueue.push(temp);
                }
                if(this->mapping.find(temp->val)==this->mapping.end()){
                    this->mapping[temp->val]=new Node(temp->val);
                }
            }

            for(Node* temp: tempNode->neighbors){
                this->mapping[tempNode->val]->neighbors.push_back(this->mapping[temp->val]);
            }
        }

        return this->mapping[1];

    }
};
