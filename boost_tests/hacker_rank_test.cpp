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

    BOOST_AUTO_TEST_CASE(shortest_path_test){
        int n = 4;
        int fromArr[] = {1, 1, 4};
        int toArr[] = {2, 3, 2};
        int idArr[] = {1, 2, 1, 1};
        int t = 1;
        vector <int> fromVec(fromArr, fromArr+3);
        vector <int> toVec(toArr, toArr+3);
        vector <long> ids(idArr, idArr + 4);

        int res = findShortest(n, fromVec, toVec, ids, t);
        int ll;
}

    BOOST_AUTO_TEST_CASE(colleage_equal_test){

        int arr[] = {2, 5, 5, 5, 5, 5};
        vector <int> arrVec(arr, arr+6);
        int res = colleageEqual(arrVec);

        BOOST_CHECK_EQUAL(res, 6);

    }
    BOOST_AUTO_TEST_CASE(cost_test){

        int arr[] = {1, 2, 3};
        vector <int> arrVec(arr, arr+3);
        sherlockcost(arrVec);

//        BOOST_CHECK_EQUAL(res, 6);

    }

    BOOST_AUTO_TEST_CASE(common_child_test){
        string s1 = "HARRY";
        string s2 = "SALLY";
        int res = commonChild(s1, s2);


        BOOST_CHECK_EQUAL(res, 2);

    }

    BOOST_AUTO_TEST_CASE(reverse_shuffle_merge_test){
        string s1 = "eggegg";
        string r = reverseShuffleMerge(s1);


        BOOST_CHECK_EQUAL(r, "egg");

    }

    BOOST_AUTO_TEST_CASE(mst_test){
        KruskalMST();

    }

    BOOST_AUTO_TEST_CASE(min_time_test){
        int n = 5;
        vector<vector<int>> roads;
        vector<int> r1 = {0, 3, 3};
        vector<int> r2 = {1, 4, 4};
        vector<int> r3 = {1, 3, 4};
        vector<int> r4 = {0, 2, 5};
        roads.push_back(r1);
        roads.push_back(r2);
        roads.push_back(r3);
        roads.push_back(r4);
        vector<int> machines = {1, 3, 4};

        minTime(n, roads, machines);

    }

    BOOST_AUTO_TEST_CASE(step_perm_test){
        int n = 3;
        stepPerms(n);
    }

    BOOST_AUTO_TEST_CASE(super_digit_test){
        superDigit("861568688536788", 100000);
    }

BOOST_AUTO_TEST_SUITE_END()

//BOOST_AUTO_TEST_CASE(constructor_test)
//{
//    Student st("andy");
//
//    BOOST_CHECK_EQUAL(st.studentName(), "ady");
//}
