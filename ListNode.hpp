#include <cstddef>

class ListNode{
    public:
        ListNode(ListNode* prev, ListNode* next, int data);
        ~ListNode();

        ListNode* getPrev();
        void setPrev(ListNode* prev);

        ListNode* getNext();
        void setNext(ListNode* next);

        int getData();
        void setData(ListNode* data);

    private:
        ListNode* m_prev;
        ListNode* m_next;
        int m_data;    
};