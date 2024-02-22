/**
 * Given the head of a linked list, return the node where the cycle begins. If there is no cycle, return null.
 * 
 * There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to (0-indexed). It is -1 if there is no cycle. Note that pos is not passed as a parameter.
 * 
 * Do not modify the linked list.
 * 
 *  
 * 
 * Example 1:
 * 
 * 
 * Input: head = [3,2,0,-4], pos = 1
 * Output: tail connects to node index 1
 * Explanation: There is a cycle in the linked list, where tail connects to the second node.
 * Example 2:
 * 
 * 
 * Input: head = [1,2], pos = 0
 * Output: tail connects to node index 0
 * Explanation: There is a cycle in the linked list, where tail connects to the first node.
 * Example 3:
 * 
 * 
 * Input: head = [1], pos = -1
 * Output: no cycle
 * Explanation: There is no cycle in the linked list.
 *  
 * 
 * Constraints:
 * 
 * The number of the nodes in the list is in the range [0, 104].
 * -105 <= Node.val <= 105
 * pos is -1 or a valid index in the linked-list.
 *  
 * 
 * Follow up: Can you solve it using O(1) (i.e. constant) memory?
 */
#include<iostream>
#include<vector>

using namespace std;

/**
 * Here is the solution class to be implemented.
*/
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode *solv(ListNode *head){
        ListNode *fast = head, *slow = head;
        if (!head)
            return NULL;
        do {
            fast = fast->next;
            if (fast)
                fast = fast->next;
            else    
                return NULL;
            slow = slow->next;
        }while (fast && slow && fast != slow);
        if (fast == slow){
            ListNode *ans = head;
            while (ans != slow){
                slow = slow->next;
                ans = ans->next;
            }
            return ans;
        }
        return NULL;
    }
};

/**
 * Here is the main function to execute the solving class.
*/
int main(){
    Solution solv;
    ListNode *head;
    ListNode node1(3), node2(2), node3(0), node4(-4);
    head = &node1;
    node1.next = &node2;
    node2.next = &node3;
    node3.next = &node4;
    node4.next = &node2;
    // return value should be modified according to the implementation of Solution.solv()
    ListNode *result;

    cout << "Input:" << endl;
    ListNode *temp = head;
    while (temp->val != -4){
        cout << temp->val << "->";
        temp = temp->next;
    }

    result = solv.solv(head);
    
    cout << "\nResult:" << endl;
    cout << result->val;
    return 0;
}