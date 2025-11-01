class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> valuesToRemove(nums.begin(), nums.end());

        // Remove leading nodes by advancing head (do NOT delete nodes)
        while (head != nullptr && valuesToRemove.count(head->val) > 0) {
            head = head->next;
        }

        if (head == nullptr) return nullptr;

        ListNode* current = head;
        while (current->next != nullptr) {
            if (valuesToRemove.count(current->next->val) > 0) {
                // skip the next node (do not delete)
                current->next = current->next->next;
            } else {
                current = current->next;
            }
        }
        return head;
    }
};
