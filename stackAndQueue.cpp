// #include <iostream>
// using namespace std;

// class stackImp
// {
// public:
//     const int size = 10;

//     int top = -1;

//     int st[10];
//     void push(int x)
//     {
//         if (top >= size)
//         {
//             cout << "out of memory";
//         }
//         top = top + 1;
//         st[top] = x;
//         cout << st[top] << "  pushed in stack" << endl;
//     }
//     void peek()
//     {
//         if (top == -1)
//         {
//             cout << "stack is empty";
//         }
//         cout << "topmost elemnt is  " << st[top] << endl;
//     }
//     void pop()
//     {
//         if (top == -1)
//         {
//             cout << "stack is empty";
//         }
//         top = top - 1;
//     }
//     void display()
//     {
//         if (top == -1)
//         {
//             cout << "stack is empty";
//         }
//         for (int i = top; i >= 0; i--)
//         {
//             cout << st[i] << "  ";
//         }
//         cout << endl;
//     }
// };

// int main()
// {
//     stackImp stack;
//     stack.push(5);
//     stack.peek();
//     stack.push(4);
//     stack.pop();
//     stack.push(8);
//     stack.display();
//     stack.peek();
//     stack.pop();
//     stack.display();
//     stack.peek();
//     stack.push(9);
//     stack.display();
// }

// Implementing queue using arrays

// #include <iostream>
// using namespace std;

// class qImp
// {
// public:
//     int size = 10;
//     int curSize = 0;
//     int start, end = -1;
//     int q[10];

//     void push(int x)
//     {
//         if (curSize == size)
//         {
//             cout << "limit exceeds";
//         }
//         if (curSize == 0)
//         {
//             start = 0;
//             end = 0;
//         }
//         else
//         {
//             end = (end + 1) % size;
//         }
//         q[end] = x;
//         curSize += 1;
//         cout << x << " pushed in queue" << endl;
//     }
//     void pop()
//     {
//         if (curSize == 0)
//         {
//             cout << "empty queue";
//         }
//         int el = q[start];
//         if (curSize == 1)
//         {
//             start = end = -1;
//         }
//         else
//         {
//             start = (start + 1) % size;
//         }
//         curSize -= 1;
//     }
//     void top()
//     {
//         if (curSize == 0)
//         {
//             cout << "empty queue";
//         }
//         {
//             cout << "The top element is " << q[start] << endl;
//         }
//     }
//     void length()
//     {
//         cout << curSize << endl;
//     }
//     void display()
//     {
//         if (curSize == 0)
//         {
//             cout << "Queue is empty\n";
//             return;
//         }
//         int i = start;
//         for (int cnt = 0; cnt < curSize; cnt++)
//         {
//             cout << q[i] << " ";
//             i = (i + 1) % size;
//         }
//         cout << endl;
//     }
// };

// int main()
// {
//     qImp Queue;
//     Queue.push(9);
//     Queue.push(8);
//     Queue.top();
//     Queue.display();
//     Queue.pop();
//     Queue.push(6);
//     Queue.top();
//     Queue.push(3);
//     Queue.pop();
//     Queue.display();
//     Queue.length();
// }

// infix to postfix

// #include <bits/stdc++.h>
// #include <iostream>
// #include <stack>
// using namespace std;

// int precedence(char op)
// {
//     if (op == '^')
//         return 3;
//     else if (op == '*' || op == '/')
//         return 2;
//     else if (op == '+' || op == '-')
//         return 1;
//     return 0;
// }

// string infixTOpostfix(string s)
// {
//     stack<char> st;
//     string postfix = "";
//     for (char ch : s)
//     {
//         if (isalnum(ch))
//         {
//             postfix += ch;
//         }
//         else if (ch == '(')
//         {
//             st.push(ch);
//         }
//         else if (ch == ')')
//         {
//             while (!st.empty() && st.top() != '(')
//             {
//                 postfix += st.top();
//                 st.pop();
//             }
//             st.pop();
//         }
//         else
//         {
//             while (!st.empty() && precedence(st.top()) >= precedence(ch))
//             {
//                 postfix += st.top();
//                 st.pop();
//             }
//             st.push(ch);
//         }
//     }
//     while (!st.empty())
//     {
//         postfix += st.top();
//         st.pop();
//     }
//     return postfix;
// }

// int main()
// {
//     string s;
//     cin >> s;
//     cout << "postfix expression is :  " << infixTOpostfix(s);
//     return 0;
// }

// infix to prefix

// #include <bits/stdc++.h>
// using namespace std;

// string rev(string s)
// {
//     reverse(s.begin(), s.end());
//     return s;
// }
// string swapBrackets(string s)
// {
//     for (char &ch : s)
//     {
//         if (ch == '(')
//             ch = ')';
//         else if (ch == ')')
//             ch = '(';
//     }
//     return s;
// }
// int precedence(char op)
// {
//     if (op == '^')
//         return 3;
//     if (op == '*' || op == '/')
//         return 2;
//     if (op == '+' || op == '-')
//         return 1;
//     return 0;
// }
// string infixToPostfix(string ans)
// {
//     stack<char> st;
//     string postfix = "";

//     for (char ch : ans)
//     {
//         if (isalnum(ch))
//         {
//             postfix += ch;
//         }
//         else if (ch == '(')
//         {
//             st.push('(');
//         }
//         else if (ch == ')')
//         {
//             while (!st.empty() && st.top() != '(')
//             {
//                 postfix += st.top();
//                 st.pop();
//             }
//             st.pop();
//         }
//         else
//         {
//             while (!st.empty() && precedence(st.top()) > precedence(ch))
//             {
//                 postfix += st.top();
//                 st.pop();
//             }
//             st.push(ch);
//         }
//     }
//     while (!st.empty())
//     {
//         postfix += st.top();
//         st.pop();
//     }
//     return postfix;
// }

// int main()
// {
//     string s;
//     cin >> s;
//     string ans = rev(s);
//     ans = swapBrackets(ans);
//     string ans2 = infixToPostfix(ans);

//     cout << rev(ans2);
// }

// #include <bits/stdc++.h>
// using namespace std;

// string postfixToInfix(string s)
// {
//     stack<string> st;
//     string x;
//     for (char ch : s)
//     {
//         if (isalnum(ch))
//         {
//             st.push(string(1, ch));
//         }
//         else
//         {
//             string t1 = st.top();
//             st.pop();
//             string t2 = st.top();
//             st.pop();
//             x = '(' + t2 + ch + t1 + ')';
//             st.push(x);
//         }
//         }
//     return st.top();
// }

// int main()
// {
//     string s;
//     cin >> s;
//     cout << postfixToInfix(s);
// }

// prefix to infix conversion

// #include <bits/stdc++.h>
// using namespace std;

// string prefixToInfix(string s)
// {
//     stack<string> st;
//     string x;
//     reverse(s.begin(), s.end());
//     for (char ch : s)
//     {
//         if (isalnum(ch))
//         {
//             st.push(string(1, ch));
//         }
//         else
//         {
//             string t1 = st.top();
//             st.pop();
//             string t2 = st.top();
//             st.pop();
//             x = '(' + t1 + ch + t2 + ')';
//             st.push(x);
//         }
//     }
//     return st.top();
// }
// int main()
// {
//     string s;
//     cin >> s;
//     cout << prefixToInfix(s);
// }

// postfix to prefix conversion

// #include <bits/stdc++.h>
// using namespace std;

// string postfixToPrefix(string s)
// {
//     stack<string> st;
//     string x;
//     for (char ch : s)
//     {
//         if (isalnum(ch))
//         {
//             st.push(string(1, ch));
//         }
//         else
//         {
//             string t1 = st.top();
//             st.pop();
//             string t2 = st.top();
//             st.pop();
//             x = ch + t2 + t1;
//             st.push(x);
//         }
//     }
//     return st.top();
// }

// int main()
// {
//     string s;
//     cin >> s;
//     cout << postfixToPrefix(s);
//     return 0;
// }

// prefix to postfix conversion

// #include <bits/stdc++.h>
// using namespace std;

// string prefixToPostfix(string s)
// {
//     stack<string> st;
//     string x;
//     reverse(s.begin(), s.end());
//     for (char ch : s)
//     {
//         if (isalnum(ch))
//         {
//             st.push(string(1, ch));
//         }
//         else
//         {
//             string t1 = st.top();
//             st.pop();
//             string t2 = st.top();
//             st.pop();
//             x = t1 + t2 + ch;
//             st.push(x);
//         }
//     }
//     return st.top();
// }

// int main()
// {
//     string s;
//     cin >> s;
//     cout << postfixToPrefix(s);
//     return 0;
// }

// next greater element
// brute froce approach

// #include <iostream>
// #include <vector>
// using namespace std;

// vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
//     vector<int> ans;

//     for (int i = 0; i < nums1.size(); i++) {
//         int j;
//         for (j = 0; j < nums2.size(); j++) {
//             if (nums1[i] == nums2[j])
//                 break;
//         }

//         int nextGreater = -1;
//         for (int k = j + 1; k < nums2.size(); k++) {
//             if (nums2[k] > nums1[i]) {
//                 nextGreater = nums2[k];
//                 break;
//             }
//         }

//         ans.push_back(nextGreater);
//     }

//     return ans;
// }

// int main() {
//     vector<int> nums1 = {4,1,2};
//     vector<int> nums2 = {1,3,4,2};

//     vector<int> res = nextGreaterElement(nums1, nums2);
//     for (int x : res)
//         cout << x << " ";
// }

// optimized approach

// #include <iostream>
// #include <vector>
// #include <stack>
// #include <unordered_map>
// using namespace std;

// vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
// {
//     unordered_map<int, int> mp; // stores next greater for nums2
//     stack<int> st;

//     // Step 1: Process nums2
//     for (int num : nums2)
//     {
//         while (!st.empty() && st.top() < num)
//         {
//             mp[st.top()] = num;
//             st.pop();
//         }
//         st.push(num);
//     }

//     // Step 2: Remaining elements have no greater element
//     while (!st.empty())
//     {
//         mp[st.top()] = -1;
//         st.pop();
//     }

//     // Step 3: Build answer for nums1
//     vector<int> ans;
//     for (int num : nums1)
//     {
//         ans.push_back(mp[num]);
//     }

//     return ans;
// }

// int main()
// {
//     vector<int> nums1 = {4, 1, 2};
//     vector<int> nums2 = {1, 3, 4, 2};

//     vector<int> res = nextGreaterElement(nums1, nums2);
//     for (int x : res)
//         cout << x << " ";
// }

// Trapping Rainwater

// brute force approach
// #include <bits/stdc++.h>
// using namespace std;

// int trap(int n, vector<int> &arr, vector<int> &prefix, vector<int> &suffix)
// {
//     int total = 0;
//     for (int i = 1; i < n - 1; i++)
//     {
//         int water = min(prefix[i], suffix[i]) - arr[i];
//         if (water > 0)
//         {
//             total += water;
//         }
//     }
//     return total;
// }

// int main()
// {
//     vector<int> arr = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
//     int n = arr.size();

//     vector<int> prefix(n);
//     prefix[0] = arr[0];
//     for (int i = 1; i < n - 1; i++)
//     {
//         prefix[i] = max(prefix[i - 1], arr[i]);
//     }
//     vector<int> suffix(n);
//     suffix[n - 1] = arr[n - 1];
//     for (int i = n - 2; i >= 0; i--)
//     {
//         suffix[i] = max(suffix[i + 1], arr[i]);
//     }
//     cout << trap(n, arr, prefix, suffix);
// }

// previous Smaller element

#include <bits/stdc++.h>
using namespace std;

vector<int> nse()
{
    vector<int> arr = {2, 4, 3, 8, 7, 6, 5, 9};
    stack<int> st;
    vector<int> nse;
    for (int i = 0; i < arr.size(); i++)
    {
        while (!st.empty() && st.top() >= arr[i])
        {
            st.pop();
        }
        nse.push_back(st.empty() ? -1 : st.top());
        st.push(arr[i]);
    }
    return nse;
}

int main()
{
    vector<int> ans = nse();
    for (int i : ans)
    {
        cout << i << "  ";
    }
}