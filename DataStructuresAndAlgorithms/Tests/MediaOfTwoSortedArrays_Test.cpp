// https://leetcode.com/problems/median-of-two-sorted-arrays/

#include <gtest/gtest.h>

#include "../MedianOfTwoSortedArrays.h"

using namespace std;

class ParameterizedMedianOfTwoSortedArrays : public ::testing::TestWithParam<tuple<vector<int>, vector<int>, double>> {};
TEST_P(ParameterizedMedianOfTwoSortedArrays, GetsMedian)
{
    vector<int> nums1 = std::get<0>(GetParam());
    vector<int> nums2 = std::get<1>(GetParam());
    const double actual = Algorithms::findMedianSortedArrays(nums1, nums2);
    const double expected = std::get<2>(GetParam());
    ASSERT_EQ(expected, actual);
}
INSTANTIATE_TEST_CASE_P(
    GetMedians,
    ParameterizedMedianOfTwoSortedArrays,
    ::testing::Values(
        std::make_tuple(vector<int>{}, vector<int>{}, 0.0),
        std::make_tuple(vector<int>{1}, vector<int>{}, 1.0),
        std::make_tuple(vector<int>{1}, vector<int>{1}, 1.0),
        std::make_tuple(vector<int>{1,3}, vector<int>{2}, 2),
        std::make_tuple(vector<int>{1,2}, vector<int>{3,4}, 2.5),
        std::make_tuple(vector<int>{1,2,3,4}, vector<int>{5}, 3),
        std::make_tuple(vector<int>{1}, vector<int>{100,101}, 100)
    )
);