#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <string>

char Gt(char c) {
    if (c >= 'A' && c <= 'Z') {
        return static_cast<char>(c - 'A' + 'a');
    }
    return c;
}

std::string_view Get(std::string_view a, size_t l, size_t r) {
    std::string_view ans = a;
    ans.remove_prefix(l);
    ans.remove_suffix(a.size() - r - 1);
                std::string_view current = str;
                current.remove_prefix(i - len);
                current.remove_suffix(str.size() - i);
                answer.push_back(Get(str, i - len, i - 1));
            }
            len = 0;
        }
    }
    if (len) {
        answer.push_back(Get(str, str.size() - len, str.size() - 1));
    }
    return answer;
}
            ++len;
        } else {
            if (len) {
                lines.push_back(Line(Get(text, i - len, i - 1), 0));
            }
            len = 0;
        }
    }
    if (len) {
        lines.push_back(Line(Get(text, text.size() - len, text.size() - 1), 0));
    }
    for (auto el : l) {
        size_t counter = 0;
        size_t cnt = 0;
        for (auto line : lines) {
            std::vector<std::string_view> elem = GetList(line.str);
            cnt += (!elem.empty());
            counter += (Count(elem, el) > 0);
        }
        for (auto& line : lines) {
            std::vector<std::string_view> elem = GetList(line.str);
            line.tfdf +=
                static_cast<long double>(Count(elem, el)) / elem.size() * logl(static_cast<long double>(cnt) / counter);
        }
    }
    std::stable_sort(lines.begin(), lines.end(), Greater);
    while (!lines.empty() && fabsl(lines.back().tfdf) < eps) {
        lines.pop_back();
    }
    std::vector<std::string_view> ans;
    for (size_t i = 0; i < std::min(lines.size(), results_count); ++i) {
        ans.push_back(lines[i].str);
    }
    return ans;
}
