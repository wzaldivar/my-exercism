#include <array>
#include <string>
#include <vector>
#include <cmath>
#include <sstream>

// Round down all provided student scores.
std::vector<int> round_down_scores(std::vector<double> student_scores)
{
    std::vector<int> scores;
    for (auto it = student_scores.begin(); it != student_scores.end(); ++it)
    {
        scores.push_back(std::floor(*it));
    }
    return scores;
}

// Count the number of failing students out of the group provided.
int count_failed_students(std::vector<int> student_scores)
{
    int counter = 0;
    for (auto it = student_scores.begin(); it != student_scores.end(); ++it)
    {
        if (*it <= 40)
        {
            counter++;
        }
    }
    return counter;
}

// Determine how many of the provided student scores were 'the best' based on the provided threshold.
std::vector<int> above_threshold(std::vector<int> student_scores, int threshold)
{
    std::vector<int> scores;
    for (auto it = student_scores.begin(); it != student_scores.end(); ++it)
    {
        if (*it >= threshold)
        {
            scores.push_back(*it);
        }
    }
    return scores;
}

// Create a list of grade thresholds based on the provided highest grade.
std::array<int, 4> letter_grades(int highest_score)
{
    int delta = (highest_score - 40) / 4;
    std::array<int, 4> grades;
    for (size_t i = 0; i < 4; ++i)
    {
        grades[i] = 41 + i * delta;
    }
    return grades;
}

// Organize the student's rank, name, and grade information in ascending order.
std::vector<std::string> student_ranking(std::vector<int> student_scores, std::vector<std::string> student_names)
{
    std::vector<std::string> ranking;

    for (size_t i = 0; i < student_scores.size(); ++i)
    {
        std::stringstream ss;
        ss << i + 1 << ". " << student_names[i] << ": " << student_scores[i];
        ranking.push_back(ss.str());
    }

    return ranking;
}

// Create a string that contains the name of the first student to make a perfect score on the exam.
std::string perfect_score(std::vector<int> student_scores, std::vector<std::string> student_names)
{
    auto score_it = student_scores.begin();
    auto name_it = student_names.begin();

    while (score_it != student_scores.end())
    {
        {
            if (*score_it == 100)
            {
                return *name_it;
            }
            ++score_it;
            ++name_it;
        }
    }

    return "";
}