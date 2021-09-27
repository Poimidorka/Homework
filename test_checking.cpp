#include <deque>
#include "tests_checking.h"

std::vector<std::string> StudentsOrder(const std::vector<StudentAction>& student_actions,
                                       const std::vector<size_t>& queries) {
    std::deque<std::string> assesments;
    for (const StudentAction& action : student_actions) {
        if (action.side == Side::Top) {
            assesments.push_front(action.name);
        } else {
            assesments.push_back(action.name);
        }
    }
    std::vector<std::string> answer(queries.size());
    for (size_t i = 0; i < queries.size(); ++i) {
        answer[i] = assesments[queries[i] - 1];
    }
    return answer;
}
