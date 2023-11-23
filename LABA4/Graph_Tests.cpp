#include "pch.h"
#include "CppUnitTest.h"
#include "..//Lab4/Graph.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace Modified_Wirth_structure;

namespace Modified_Wirth_structure {
	TEST_CLASS(Graph_Tests)
	{
	public:
		TEST_METHOD(Test_Nodes)
		{
			Graph<int> a;
			a.add_node(1);
			a.add_node(2);
			a.begin_nodes();
			a.end_nodes();
			a.reverse_begin_nodes();
			a.reverse_end_nodes();
			a.check_node(1);
			a.check_node(999);
			a.remove_node(1);
			a.get_number_of_nodes();
			a.get_node_degree(2);
		}
		TEST_METHOD(Test_Edges)
		{
			Graph<int> a;
			a.add_node(1);
			a.add_node(2);
			a.add_edge(1, 2);
			a.add_edge(2, 1);
			a.check_edge(2, 1);
			a.check_edge(99, 999);
			a.remove_edge(1, 2);
			a.get_number_of_edges();
		}
		TEST_METHOD(Test_Errors_Add_Edge)
		{
			Graph<int> a;
			a.add_node(1);
			a.add_node(2);
			Assert::ExpectException<exception>([&]() {
				a.add_edge(1, 3);
			});
		}
		TEST_METHOD(Test_Errors_Add_Edge_Duplicate)
		{
			Graph<int> a;
			a.add_node(1);
			a.add_node(2);
			Assert::ExpectException<exception>([&]() {
				a.add_edge(1, 2);
				a.add_edge(1, 2);
			});
		}
		TEST_METHOD(Test_Errors_Remove_Edge)
		{
			Graph<int> a;
			a.add_node(1);
			a.add_node(2);
			Assert::ExpectException<exception>([&]() {
				a.remove_edge(99, 99);
			});
		}
		TEST_METHOD(Test_Errors_Remove_Node)
		{
			Graph<int> a;
			a.add_node(1);
			a.add_node(2);
			Assert::ExpectException<exception>([&]() {
				a.remove_node(999);
			});
		}
		TEST_METHOD(Test_Print_Graph_Assignment)
		{
			Graph<double> A;
			A.add_node(100);
			A.add_node(200);
			Graph<double> B = A;
			B.print_graph();
		}
	};
}
