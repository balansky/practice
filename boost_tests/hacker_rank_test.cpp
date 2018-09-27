//
// Created by andy on 18/08/18.
//
#define BOOST_TEST_MODULE MyTest

//#include <boost/test/included/unit_test.hpp>
#include <boost/test/unit_test.hpp>
#include "hackerrank.h"

using namespace std;
//BOOST_AUTO_TEST_CASE(MyTestCase){
//    Student st("andy");
//    BOOST_CHECK_MESSAGE( st.studentName() == "A student with name andy",  // #6 continues on error
//                         st.studentName() );
//
//}

//int hourglassSum(vector<vector<int>> arr);
//vector<int> rotLeft(vector<int>, int);
//int minimumBribes(vector<int>);

BOOST_AUTO_TEST_SUITE(hacker_rank_suite)

    BOOST_AUTO_TEST_CASE(hourglass_sum_test) {
        stringstream inputstr( "-1 -1 0 -9 -2 -2\n"
                              "-2 -1 -6 -8 -2 -5\n"
                              "-1 -1 -1 -2 -3 -4\n"
                              "-1 -9 -2 -4 -4 -5\n"
                              "-7 -3 -3 -2 -9 -9\n"
                              "-1 -3 -1 -2 -4 -5");
        string tostr;
        vector<vector<int>> testVec;
        while(getline(inputstr, tostr, '\n'))
        {
            vector<int> tVec;
            string toint;
            stringstream rowStr(tostr);
            while(getline(rowStr, toint, ' '))
            {
                int intInput = 0;
                stringstream intStr(toint);
                intStr >> intInput;
                tVec.push_back(intInput);
            }
            testVec.push_back(tVec);

        }
        int ss = hourglassSum(testVec);
        BOOST_CHECK_EQUAL(ss, -6);
    }

    BOOST_AUTO_TEST_CASE(left_rotate_test){
        int arr[] = {1,2,3,4,5};
        int gt[] = {5,1,2,3,4};

        vector<int> vec(arr, arr + sizeof(arr)/sizeof(int));
        vector<int> gtvec(gt, gt + sizeof(gt)/sizeof(int));
        vector<int> res = rotLeft(vec, 4);
        BOOST_CHECK_EQUAL_COLLECTIONS(res.begin(), res.end(),
                                      gtvec.begin(), gtvec.end());

    }

    BOOST_AUTO_TEST_CASE(minimun_bribe_test){

        int arr[] = {2, 1, 5, 3, 4};
        vector<int> vec(arr, arr + sizeof(arr)/sizeof(int));
        int arr2[] = {2,5,1,3,4};
        vector<int> vec2(arr2, arr2 + sizeof(arr2)/sizeof(int));
        int arr3[] = {1,2, 5, 3, 7, 8, 6, 4};
        vector<int> vec3(arr3, arr3 + sizeof(arr3)/sizeof(int));
        BOOST_CHECK_EQUAL(minimumBribes(vec), 3);
        BOOST_CHECK_EQUAL(minimumBribes(vec2), -1);
        BOOST_CHECK_EQUAL(minimumBribes(vec3), 7);
    }

    BOOST_AUTO_TEST_CASE(grade_student_test){

        int arr[] = {73, 67, 38, 33};
        int gt[] = {75, 67, 40, 33};
        vector<int> test(arr, arr + 4);
        vector<int> gt_test(gt, gt + 4);
        vector<int> res = gradingStudents(test);
        BOOST_CHECK_EQUAL_COLLECTIONS(res.begin(), res.end(), gt_test.begin(), gt_test.end());

    }

    BOOST_AUTO_TEST_CASE(apple_orange_test){

        int s = 7;
        int t = 11;
        int a = 5;
        int b = 15;
        int appleArr[] = {-2, 2, 1};
        int orangeArr[] = {5, -6};
        vector <int> apples(appleArr, appleArr+3);
        vector <int> oranges(orangeArr, orangeArr+2);
        countApplesAndOranges(s,t,a,b,apples,oranges);

    }


BOOST_AUTO_TEST_SUITE_END()

//BOOST_AUTO_TEST_CASE(constructor_test)
//{
//    Student st("andy");
//
//    BOOST_CHECK_EQUAL(st.studentName(), "ady");
//}
