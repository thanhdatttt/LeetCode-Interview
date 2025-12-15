#include <iostream>
#include <stack>
#include <sstream>
using namespace std;

string simplifyPath(string path) {
    // stack<string> st;
    // string token;

    // // rewrite the path in stack
    // for (int i = 0; i <= path.size(); i++) {
    //     // a complete token when end with "/"
    //     if (i == path.size() || path[i] == '/') {
    //         // skip when token is "." or empty
    //         if (token == "" || token == ".") {
    //             continue;
    //         }
    //         // pop when token is ".." 
    //         else if (token == "..") {
    //             if (!st.empty()) {
    //                 st.pop();
    //             }
    //         }
    //         // other token push 
    //         else {
    //             st.push(token);
    //         }
    //         // reset token
    //         token = "";
    //     } else {
    //         // get token from every letters
    //         token += path[i];
    //     }
    // }

    // // get the new path from stack
    // string res = "";
    // while (!st.empty()) {
    //     res = "/" + st.top() + res;
    //     st.pop();
    // }

    // return res.empty() ? "/" : res;

    // second solution using stringstream
    stack<string> st;
    string token;
    stringstream ss(path);

    while (getline(ss, token, '/')) {
        if (token == "" || token == ".") {
            continue;
        } else if (token == "..") {
            if (!st.empty()) st.pop();
        } else {
            st.push(token);
        }
    }

    string res = "";
    while (!st.empty()) {
        res = "/" + st.top() + res;
        st.pop();
    }

    return res.empty() ? "/" : res;
}

int main() {
    string  path = "/a//b////c/d//././/..";

    cout << simplifyPath(path) << endl;
    return 0;
}