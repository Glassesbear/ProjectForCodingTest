
//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
// ��ũ�帮��Ʈ ���� ����
// new ListNode�� ���� ���ο� ����Ʈ�� �����Ͽ� ó�� �� �� �ִ����� ���� ����
// ������ ������
// L1, L2�� ������ ���� �� ���� ���Ͽ�
// ���ο� ����Ʈ�� ����� �����ϴ� ����


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


            // ���� �������� �Ѿ�� �κ�
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