#ifndef NODE_H
#define NODE_H

class Node {
    public:
        Node();
        Node(int);
        void Num(int);      // Set private variable.
        int  Num() const;   // Get private variable.
        void operator =  (const Node&);
        bool operator == (const Node&);
        bool operator != (const Node&);
        
    private:
        int num; 
};

#endif
