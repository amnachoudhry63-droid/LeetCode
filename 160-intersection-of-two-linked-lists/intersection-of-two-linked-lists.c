/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* getIntersectionNode(struct ListNode* headA, struct ListNode* headB) {
    if (!headA || !headB) return NULL;

    struct ListNode *ptrA = headA, *ptrB = headB;

    // Traverse both lists
    while (ptrA != ptrB) {
        // When reaching the end of one list, start at the other list's head
        ptrA = ptrA ? ptrA->next : headB;
        ptrB = ptrB ? ptrB->next : headA;
    }

    return ptrA; // Either intersection node or NULL if no intersection
}
