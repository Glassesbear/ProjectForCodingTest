
//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
// 링크드리스트 이해 문제
// new ListNode를 통해 새로운 리스트를 생성하여 처리 할 수 있는지에 대한 이해
// 간단한 로직은
// L1, L2가 끝나지 않을 때 까지 더하여
// 새로운 리스트를 만들며 진행하는 형태


class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        int nCarry = 0;
        int nSum = 0;

        ListNode* result = new ListNode();
        ListNode* lCurrent = result;
        while (l1 != nullptr || l2 != nullptr) {


            nSum = nCarry;
            nCarry = 0;
            //printf("1 sum : %d\n", nSum);
            if (l1 != nullptr)
                nSum += l1->val;

            if (l2 != nullptr)
                nSum += l2->val;

            //printf("3 sum : %d\n", nSum);
            // carry check
            if (nSum > 9) {
                nSum = nSum % 10;
                nCarry = 1;
            }

            //printf("fin sum : %d\n", nSum);
            lCurrent->next = new ListNode(nSum);
            lCurrent = lCurrent->next;


            // 다음 과정으로 넘어가는 부분
            if (l1 != nullptr) {
                l1 = l1->next;
            }
            else
                l1 = nullptr;

            if (l2 != nullptr) {
                l2 = l2->next;
            }
            else
                l2 = nullptr;
        }

        if (nCarry > 0) {
            lCurrent->next = new ListNode(nCarry);
        }


        return result->next;
    }
};