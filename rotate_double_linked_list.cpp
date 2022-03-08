// CODE BY :- AJAY PAL IIT (BHU) VARANASI
#include <bits/stdc++.h>
#define ll long long int
#define ld long double
#define kk '\n'
using namespace std;

typedef struct node
{
    int data;
    struct node *next, *prev;

    node(int x)
    {
        data = x;
        next = NULL;
        prev = NULL;
    }

} Node;

  
class Solution
{
public:
    Node *update(Node *head, int n)
    {
        if (head == NULL or head->next == NULL or n == 0)
        {
            return head;
        }

        Node *cur = head;

        int cnt = 1;
        while (cur and cnt < n)
        {
            cur = cur->next;
            cnt++;
        }

        Node *nthnode = cur;

        while (cur->next)
        {
            cur = cur->next;
        }

        cur->next = head;
        head->prev = cur;

        head = nthnode->next;
        head->prev = NULL;
        nthnode->next = NULL;
 
        return head;
    }
};