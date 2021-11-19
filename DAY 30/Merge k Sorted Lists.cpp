//23. Merge k Sorted Lists
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
    struct node
    {
        ListNode *curr;
        int idx;
        node(ListNode *a, int b)
        {
            curr = a;
            idx = b;
        }
    };
    struct compare
    {
        bool operator()(node a, node b)
        {
            return a.curr->val > b.curr->val;
        }
    };

public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        int k = lists.size();
        if (k == 0)
            return NULL;
        ListNode *head, *tail;
        head = tail = NULL;
        priority_queue<node, vector<node>, compare> pq;
        vector<ListNode *> ptr(k);
        for (int i = 0; i < k; i++)
        {
            ptr[i] = lists[i];
            if (ptr[i] != NULL)
                pq.push(node(ptr[i], i));
        }
        if (pq.empty())
            return NULL;
        head = tail = pq.top().curr;
        int idx = pq.top().idx;
        pq.pop();
        ptr[idx] = ptr[idx]->next;
        if (ptr[idx])
            pq.push(node(ptr[idx], idx));
        while (!pq.empty())
        {
            ListNode *temp = pq.top().curr;
            idx = pq.top().idx;
            pq.pop();
            tail->next = temp;
            tail = tail->next;
            ptr[idx] = ptr[idx]->next;
            if (ptr[idx])
                pq.push(node(ptr[idx], idx));
        }

        return head;
    }
};