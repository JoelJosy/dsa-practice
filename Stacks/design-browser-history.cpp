// Stack
class BrowserHistory {
public:
    stack<string> prev;
    stack<string> next;
    BrowserHistory(string homepage) {
        prev.push(homepage);
    }
    
    void visit(string url) {
        prev.push(url);
        while (!next.empty()) 
            next.pop();
    }
    
    string back(int steps) {
        while (prev.size() > 1 && steps--) {
            next.push(prev.top());
            prev.pop();
        }
        return prev.top();
    }
    
    string forward(int steps) {
        while (!next.empty() && steps--) {
            prev.push(next.top());
            next.pop();
        }
        return prev.top();
    }
};

// DLL
class BrowserHistory {
public:
    struct Node {
        string url;
        Node* prev;
        Node* next;

        Node(string url) {
            this->url = url;
            prev = nullptr;
            next = nullptr;
        }
    };

    Node* curr;

    BrowserHistory(string homepage) {
        curr = new Node(homepage);
    }
    
    void visit(string url) {
        // delete forward history
        curr->next = nullptr;

        Node* newNode = new Node(url);

        newNode->prev = curr;
        curr->next = newNode;

        curr = newNode;
    }
    
    string back(int steps) {
        while (curr->prev != nullptr && steps--) {
            curr = curr->prev;
        }

        return curr->url;
    }
    
    string forward(int steps) {
        while (curr->next != nullptr && steps--) {
            curr = curr->next;
        }

        return curr->url;
    }
};