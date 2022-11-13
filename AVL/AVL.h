#ifndef AVL_H
#define AVL_H


/**
 * Gonna try a different approach to implementing this class based on some reflection I have been doing. 
 * In short: going to try only implement what is necessary and keep the code as clean as possible. 
*/
template<typename T> 
class AVLTree{

private:
    /**
     * Is there a need for getters and setters here? This class is only really a glorified struct,
     * and won't be accessible to classes other than AVLTree. For this reason I am going to experiment 
     * not adding unnecessary code and trying to keep things simple.
    */
    class Node{
        public:
            T data;
            Node * left;
            Node * right;

            Node(T val){
                data = val;
            }
    };

public: 
    AVLTree();
    ~AVLTree();

    void insert(T);
    void remove(T);
};



#endif