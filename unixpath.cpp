#include <vector>
#include "unixpath.h"

std::string NormalizePath(std::string_view current_working_dir, std::string_view path) {
    std::vector<std::string> stack;
    const char sep = '/';
    if (path[0] != sep) {
        std::string current;
        for (char c : current_working_dir) {
            if (c == sep) {
                if (!current.empty()) {
                    stack.push_back(current);
                }
                current.clear();
            } else {
                current += c;
            }
        }
        if (!current.empty()) {
            stack.push_back(current);
        }
    }
    std::string current;
    for (char c : path) {
        if (c == sep) {
            if (current == "..") {
                if (!stack.empty()) {
                    stack.pop_back();
                }
            } else if (!current.empty() && current != ".") {
                stack.push_back(current);
            }
        }
    }
    if (current == "..") {
        if (!stack.empty()) {
            stack.pop_back();
        }
    } else if (!current.empty() && current != ".") {
        stack.push_back(current);
    }
    std::string answer;
    for (std::string &el : stack) {
        answer += sep;
        answer = answer + el;
    }
    if (answer.empty()) {
        answer += sep;
    }
    return answer;
}
