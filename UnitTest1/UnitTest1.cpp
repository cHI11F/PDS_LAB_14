#include "pch.h"
#include "CppUnitTest.h"
#include <vector>
#include <unordered_set>
#include <string>
#include <iostream>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
    TEST_CLASS(UnitTest1)
    {
    public:


        bool isIrreflexive(const std::vector<std::vector<int>>& adjList) {
            for (int i = 1; i < adjList.size(); ++i) {
                for (int neighbor : adjList[i]) {
                    if (neighbor == i) {
                        return false;
                    }
                }
            }
            return true;
        }


        bool isSymmetric(const std::vector<std::vector<int>>& adjList) {
            std::unordered_set<std::string> edges;


            for (int i = 1; i < adjList.size(); ++i) {
                for (int neighbor : adjList[i]) {
                    edges.insert(std::to_string(i) + "-" + std::to_string(neighbor));
                }
            }

            for (int i = 1; i < adjList.size(); ++i) {
                for (int neighbor : adjList[i]) {
                    std::string edge = std::to_string(neighbor) + "-" + std::to_string(i);
                    if (edges.find(edge) == edges.end()) {
                        return false;
                    }
                }
            }

            return true;
        }


        TEST_METHOD(TestIsIrreflexive)
        {
            std::vector<std::vector<int>> adjList1 = {
                {},
                {2},
                {},
                {4},
                {}
            };

            Assert::IsTrue(isIrreflexive(adjList1));

            std::vector<std::vector<int>> adjList2 = {
                {},
                {2},
                {1},
                {3},
                {}
            };

            Assert::IsFalse(isIrreflexive(adjList2));
        }


        TEST_METHOD(TestIsSymmetric)
        {
            std::vector<std::vector<int>> adjList1 = {
                {},
                {2},
                {1},
                {4},
                {3}
            };

            Assert::IsTrue(isSymmetric(adjList1));

            std::vector<std::vector<int>> adjList2 = {
                {},
                {2},
                {},
                {4},
                {}
            };

            Assert::IsFalse(isSymmetric(adjList2));
        }
    };
}
