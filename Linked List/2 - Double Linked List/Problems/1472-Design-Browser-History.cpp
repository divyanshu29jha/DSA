// T.C: O(steps)

class Node {
public: 
    string data;
    Node* next;
    Node* prev;

    Node() : data(0), next(nullptr), prev(nullptr) {};   // constructors
    Node(string x) : data(x), next(nullptr), prev(nullptr) {};
}; 

class BrowserHistory {
public:
    Node* currentPage;

    BrowserHistory(string homepage) {    // constructor - O(1)
        currentPage = new Node(homepage);
    }
    
    void visit(string url) {   // O(1)
        Node* newNode = new Node(url);
        currentPage->next = newNode;
        newNode->prev = currentPage;
        currentPage = newNode;        
    }
    
    string back(int steps) {    // O(steps)
        while(steps != 0){
            if(currentPage->prev)
                currentPage = currentPage->prev;
            else
                break;
            
            steps--;
        }
        return currentPage->data;
    }
    
    string forward(int steps) {   // O(steps)
        while(steps != 0){
            if(currentPage->next)
                currentPage = currentPage->next;
            else
                break;
            
            steps--;
        }
        return currentPage->data;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */