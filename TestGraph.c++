// --------------------------------
// projects/g++/graph/TestGraph.c++
// Copyright (C) 2015
// Glenn P. Downing
// --------------------------------

// --------
// includes
// --------

#include <iostream> // cout, endl
#include <iterator> // ostream_iterator
#include <sstream>  // ostringstream
#include <utility>  // pair

#include "boost/graph/adjacency_list.hpp"  // adjacency_list
#include "boost/graph/topological_sort.hpp"// topological_sort

#include "gtest/gtest.h"

#include "Graph.h"

using namespace std;

using testing::Test;
using testing::Types;

// ---------
// TestGraph
// ---------

template <typename G>
struct TestGraph : Test {
    // --------
    // typedefs
    // --------

    typedef          G                     graph_type;
    typedef typename G::vertex_descriptor  vertex_descriptor;
    typedef typename G::edge_descriptor    edge_descriptor;
    typedef typename G::vertex_iterator    vertex_iterator;
    typedef typename G::edge_iterator      edge_iterator;
    typedef typename G::adjacency_iterator adjacency_iterator;
    typedef typename G::vertices_size_type vertices_size_type;
    typedef typename G::edges_size_type    edges_size_type;};

// directed, sparse, unweighted
// possibly connected
// possibly cyclic
typedef Types<
            boost::adjacency_list<boost::setS, boost::vecS, boost::directedS>,
            Graph>
        graph_types;

TYPED_TEST_CASE(TestGraph, graph_types);

// ------
// vertex
// ------

TYPED_TEST(TestGraph, test_vertex_1) {
    typedef typename TestFixture::graph_type         graph_type;
    typedef typename TestFixture::vertex_descriptor  vertex_descriptor;
    typedef typename TestFixture::edge_descriptor    edge_descriptor;
    typedef typename TestFixture::vertex_iterator    vertex_iterator;
    typedef typename TestFixture::edge_iterator      edge_iterator;
    typedef typename TestFixture::adjacency_iterator adjacency_iterator;
    typedef typename TestFixture::vertices_size_type vertices_size_type;
    typedef typename TestFixture::edges_size_type    edges_size_type;

    graph_type g;

    vertex_descriptor vdA = add_vertex(g);

    vertex_descriptor vd = vertex(0, g);
    ASSERT_EQ(vdA, vd);

    vertices_size_type vs = num_vertices(g);
    ASSERT_EQ(1, vs);
}

TYPED_TEST(TestGraph, test_vertex_2) {
    typedef typename TestFixture::graph_type         graph_type;
    typedef typename TestFixture::vertex_descriptor  vertex_descriptor;
    typedef typename TestFixture::edge_descriptor    edge_descriptor;
    typedef typename TestFixture::vertex_iterator    vertex_iterator;
    typedef typename TestFixture::edge_iterator      edge_iterator;
    typedef typename TestFixture::adjacency_iterator adjacency_iterator;
    typedef typename TestFixture::vertices_size_type vertices_size_type;
    typedef typename TestFixture::edges_size_type    edges_size_type;

    graph_type g;

    vertex_descriptor vdA = add_vertex(g);

    vertex_descriptor vdB = vertex(1, g);
    ASSERT_NE(vdA, vdB);

    vertices_size_type vs = num_vertices(g);
    ASSERT_EQ(1, vs);
}

TYPED_TEST(TestGraph, test_vertex_3) {
    typedef typename TestFixture::graph_type         graph_type;
    typedef typename TestFixture::vertex_descriptor  vertex_descriptor;
    typedef typename TestFixture::edge_descriptor    edge_descriptor;
    typedef typename TestFixture::vertex_iterator    vertex_iterator;
    typedef typename TestFixture::edge_iterator      edge_iterator;
    typedef typename TestFixture::adjacency_iterator adjacency_iterator;
    typedef typename TestFixture::vertices_size_type vertices_size_type;
    typedef typename TestFixture::edges_size_type    edges_size_type;

    graph_type g;

    vertex_descriptor vdA = add_vertex(g);
    vertex_descriptor vdB = add_vertex(g);
    ASSERT_NE(vdA, vdB);

    vertex_descriptor vd1 = vertex(0, g);
    vertex_descriptor vd2 = vertex(1, g);
    ASSERT_NE(vd1, vd2);
    
    ASSERT_EQ(vdA, vd1);
    ASSERT_EQ(vdB, vd2);

    vertices_size_type vs = num_vertices(g);
    ASSERT_EQ(2, vs);
}

// ------------
// num_vertices
// ------------

TYPED_TEST(TestGraph, test_num_vertices_1) {
    typedef typename TestFixture::graph_type         graph_type;
    typedef typename TestFixture::vertex_descriptor  vertex_descriptor;
    typedef typename TestFixture::edge_descriptor    edge_descriptor;
    typedef typename TestFixture::vertex_iterator    vertex_iterator;
    typedef typename TestFixture::edge_iterator      edge_iterator;
    typedef typename TestFixture::adjacency_iterator adjacency_iterator;
    typedef typename TestFixture::vertices_size_type vertices_size_type;
    typedef typename TestFixture::edges_size_type    edges_size_type;

    graph_type g;

    add_vertex(g);

    vertices_size_type vs = num_vertices(g);
    ASSERT_EQ(1, vs);
}

TYPED_TEST(TestGraph, test_num_vertices_2) {
    typedef typename TestFixture::graph_type         graph_type;
    typedef typename TestFixture::vertex_descriptor  vertex_descriptor;
    typedef typename TestFixture::edge_descriptor    edge_descriptor;
    typedef typename TestFixture::vertex_iterator    vertex_iterator;
    typedef typename TestFixture::edge_iterator      edge_iterator;
    typedef typename TestFixture::adjacency_iterator adjacency_iterator;
    typedef typename TestFixture::vertices_size_type vertices_size_type;
    typedef typename TestFixture::edges_size_type    edges_size_type;

    graph_type g;

    add_vertex(g);
    add_vertex(g);
    add_vertex(g);

    vertices_size_type vs = num_vertices(g);
    ASSERT_EQ(3, vs);
}

TYPED_TEST(TestGraph, test_num_vertices_3) {
    typedef typename TestFixture::graph_type         graph_type;
    typedef typename TestFixture::vertex_descriptor  vertex_descriptor;
    typedef typename TestFixture::edge_descriptor    edge_descriptor;
    typedef typename TestFixture::vertex_iterator    vertex_iterator;
    typedef typename TestFixture::edge_iterator      edge_iterator;
    typedef typename TestFixture::adjacency_iterator adjacency_iterator;
    typedef typename TestFixture::vertices_size_type vertices_size_type;
    typedef typename TestFixture::edges_size_type    edges_size_type;

    graph_type g;
    for(int i = 0; i < 1000; ++i)
        add_vertex(g);

    vertices_size_type vs = num_vertices(g);
    ASSERT_EQ(1000, vs);
}

TYPED_TEST(TestGraph, test_num_vertices_4) {
    typedef typename TestFixture::graph_type         graph_type;
    typedef typename TestFixture::vertex_descriptor  vertex_descriptor;
    typedef typename TestFixture::edge_descriptor    edge_descriptor;
    typedef typename TestFixture::vertex_iterator    vertex_iterator;
    typedef typename TestFixture::edge_iterator      edge_iterator;
    typedef typename TestFixture::adjacency_iterator adjacency_iterator;
    typedef typename TestFixture::vertices_size_type vertices_size_type;
    typedef typename TestFixture::edges_size_type    edges_size_type;

    graph_type g;
    for(int i = 0; i < 1000; ++i)
        add_vertex(g);

    vertices_size_type vs = num_vertices(g);
    ASSERT_EQ(1000, vs);

    add_vertex(g);
    vs = num_vertices(g);
    ASSERT_EQ(1001, vs);
}

TYPED_TEST(TestGraph, test_num_vertices_5) {
    typedef typename TestFixture::graph_type         graph_type;
    typedef typename TestFixture::vertex_descriptor  vertex_descriptor;
    typedef typename TestFixture::edge_descriptor    edge_descriptor;
    typedef typename TestFixture::vertex_iterator    vertex_iterator;
    typedef typename TestFixture::edge_iterator      edge_iterator;
    typedef typename TestFixture::adjacency_iterator adjacency_iterator;
    typedef typename TestFixture::vertices_size_type vertices_size_type;
    typedef typename TestFixture::edges_size_type    edges_size_type;

    graph_type g;
    
    vertices_size_type vs = num_vertices(g);
    ASSERT_EQ(0, vs);

    for(int i = 0; i < 1000; ++i){
        add_vertex(g);
        vs = num_vertices(g);
        ASSERT_EQ(i + 1, vs);
    }
}


// ----
// edge
// ----

TYPED_TEST(TestGraph, test_edge_1) {
    typedef typename TestFixture::graph_type         graph_type;
    typedef typename TestFixture::vertex_descriptor  vertex_descriptor;
    typedef typename TestFixture::edge_descriptor    edge_descriptor;
    typedef typename TestFixture::vertex_iterator    vertex_iterator;
    typedef typename TestFixture::edge_iterator      edge_iterator;
    typedef typename TestFixture::adjacency_iterator adjacency_iterator;
    typedef typename TestFixture::vertices_size_type vertices_size_type;
    typedef typename TestFixture::edges_size_type    edges_size_type;

    graph_type g;

    vertex_descriptor vdA = add_vertex(g);
    vertex_descriptor vdB = add_vertex(g);
    ASSERT_NE(vdA, vdB);

    //Failure Case
    pair<edge_descriptor, bool> p2 = edge(vdA, vdB, g);
    ASSERT_FALSE(p2.second);

    vertices_size_type vs = num_vertices(g);
    ASSERT_EQ(2, vs);
}

TYPED_TEST(TestGraph, test_edge_2) {
    typedef typename TestFixture::graph_type         graph_type;
    typedef typename TestFixture::vertex_descriptor  vertex_descriptor;
    typedef typename TestFixture::edge_descriptor    edge_descriptor;
    typedef typename TestFixture::vertex_iterator    vertex_iterator;
    typedef typename TestFixture::edge_iterator      edge_iterator;
    typedef typename TestFixture::adjacency_iterator adjacency_iterator;
    typedef typename TestFixture::vertices_size_type vertices_size_type;
    typedef typename TestFixture::edges_size_type    edges_size_type;

    graph_type g;

    vertex_descriptor vdA = add_vertex(g);
    vertex_descriptor vdB = add_vertex(g);
    pair<edge_descriptor, bool> p1 = add_edge(vdA, vdB, g);
    ASSERT_TRUE(p1.second);
    
    //normal case.
    pair<edge_descriptor, bool> p2 = edge(vdA, vdB, g);
    ASSERT_TRUE(p2.second);
    ASSERT_EQ(p1.first, p2.first);

    vertices_size_type vs = num_vertices(g);
    ASSERT_EQ(2, vs);
}

TYPED_TEST(TestGraph, test_edge_3) {
    typedef typename TestFixture::graph_type         graph_type;
    typedef typename TestFixture::vertex_descriptor  vertex_descriptor;
    typedef typename TestFixture::edge_descriptor    edge_descriptor;
    typedef typename TestFixture::vertex_iterator    vertex_iterator;
    typedef typename TestFixture::edge_iterator      edge_iterator;
    typedef typename TestFixture::adjacency_iterator adjacency_iterator;
    typedef typename TestFixture::vertices_size_type vertices_size_type;
    typedef typename TestFixture::edges_size_type    edges_size_type;

    graph_type g;

    vertex_descriptor vdA = add_vertex(g);
    vertex_descriptor vdB = add_vertex(g);
    pair<edge_descriptor, bool> p1 = add_edge(vdA, vdB, g);
    ASSERT_TRUE(p1.second);
    
    //normal case.
    pair<edge_descriptor, bool> p2 = edge(vdA, vdB, g);
    ASSERT_TRUE(p2.second);
    ASSERT_EQ(p1.first, p2.first);
    
    vertex_descriptor vdC = add_vertex(g);
    vertex_descriptor vdD = add_vertex(g);
    //failure case
    p2 = edge(vdC, vdD, g);
    ASSERT_FALSE(p2.second);
}

// --------
// add_edge
// --------

TYPED_TEST(TestGraph, test_add_edge_1) {
    typedef typename TestFixture::graph_type         graph_type;
    typedef typename TestFixture::vertex_descriptor  vertex_descriptor;
    typedef typename TestFixture::edge_descriptor    edge_descriptor;
    typedef typename TestFixture::vertex_iterator    vertex_iterator;
    typedef typename TestFixture::edge_iterator      edge_iterator;
    typedef typename TestFixture::adjacency_iterator adjacency_iterator;
    typedef typename TestFixture::vertices_size_type vertices_size_type;
    typedef typename TestFixture::edges_size_type    edges_size_type;

    graph_type g;

    vertex_descriptor vdA = add_vertex(g);
    vertex_descriptor vdB = add_vertex(g);

    pair<edge_descriptor, bool> p1 = add_edge(vdA, vdB, g);

    ASSERT_TRUE(p1.second);

    pair<edge_descriptor, bool> p2 = edge(vdA, vdB, g);
    ASSERT_TRUE(p2.second);
    ASSERT_EQ(p1.first, p2.first);



}

TYPED_TEST(TestGraph, test_add_edge_2) {
    typedef typename TestFixture::graph_type         graph_type;
    typedef typename TestFixture::vertex_descriptor  vertex_descriptor;
    typedef typename TestFixture::edge_descriptor    edge_descriptor;
    typedef typename TestFixture::vertex_iterator    vertex_iterator;
    typedef typename TestFixture::edge_iterator      edge_iterator;
    typedef typename TestFixture::adjacency_iterator adjacency_iterator;
    typedef typename TestFixture::vertices_size_type vertices_size_type;
    typedef typename TestFixture::edges_size_type    edges_size_type;

    graph_type g;

    //add an edge between two unitialized vertices.
    vertex_descriptor vdA = 0;
    vertex_descriptor vdB = 1;

    pair<edge_descriptor, bool> p1 = add_edge(vdA, vdB, g);
    ASSERT_TRUE(p1.second);

    pair<edge_descriptor, bool> p2 = edge(vdA, vdB, g);
    ASSERT_TRUE(p2.second);
    
    ASSERT_EQ(p1.first, p2.first);
    ASSERT_EQ(2, num_vertices(g));
}

TYPED_TEST(TestGraph, test_add_edge_3) {
    typedef typename TestFixture::graph_type         graph_type;
    typedef typename TestFixture::vertex_descriptor  vertex_descriptor;
    typedef typename TestFixture::edge_descriptor    edge_descriptor;
    typedef typename TestFixture::vertex_iterator    vertex_iterator;
    typedef typename TestFixture::edge_iterator      edge_iterator;
    typedef typename TestFixture::adjacency_iterator adjacency_iterator;
    typedef typename TestFixture::vertices_size_type vertices_size_type;
    typedef typename TestFixture::edges_size_type    edges_size_type;

    graph_type g;

    vertex_descriptor vdA = add_vertex(g);
    vertex_descriptor vdB = add_vertex(g);

    pair<edge_descriptor, bool> p1 = add_edge(vdA, vdB, g);
    ASSERT_TRUE(p1.second);

    //add an edge between two out of range vertices.
    vertex_descriptor vd1 = 10;
    vertex_descriptor vd2 = 11;
    p1 = add_edge(vd1, vd2, g);
    ASSERT_TRUE(p1.second);

    pair<edge_descriptor, bool> p2 = edge(vd1, vd2, g);
    ASSERT_TRUE(p2.second);
    
    ASSERT_EQ(p2.first, p1.first);
    ASSERT_EQ(12, num_vertices(g));
}

TYPED_TEST(TestGraph, test_add_edge_4) {
    typedef typename TestFixture::graph_type         graph_type;
    typedef typename TestFixture::vertex_descriptor  vertex_descriptor;
    typedef typename TestFixture::edge_descriptor    edge_descriptor;
    typedef typename TestFixture::vertex_iterator    vertex_iterator;
    typedef typename TestFixture::edge_iterator      edge_iterator;
    typedef typename TestFixture::adjacency_iterator adjacency_iterator;
    typedef typename TestFixture::vertices_size_type vertices_size_type;
    typedef typename TestFixture::edges_size_type    edges_size_type;

    graph_type g;

    vertex_descriptor vdA = add_vertex(g);
    vertex_descriptor vdB = add_vertex(g);

    //add the same edge twice.
    pair<edge_descriptor, bool> p1 = add_edge(vdA, vdB, g);
    pair<edge_descriptor, bool> p2 = add_edge(vdA, vdB, g);
    ASSERT_TRUE(p1.second);
    ASSERT_FALSE(p2.second);
    ASSERT_EQ(p1.first, p2.first);

}

// ---------
// num_edges
// ---------

TYPED_TEST(TestGraph, test_num_edges_1) {
    typedef typename TestFixture::graph_type         graph_type;
    typedef typename TestFixture::vertex_descriptor  vertex_descriptor;
    typedef typename TestFixture::edge_descriptor    edge_descriptor;
    typedef typename TestFixture::vertex_iterator    vertex_iterator;
    typedef typename TestFixture::edge_iterator      edge_iterator;
    typedef typename TestFixture::adjacency_iterator adjacency_iterator;
    typedef typename TestFixture::vertices_size_type vertices_size_type;
    typedef typename TestFixture::edges_size_type    edges_size_type;

    graph_type g;

    //add an edge between two unitialized vertices.
    vertex_descriptor vdA = add_vertex(g);
    vertex_descriptor vdB = add_vertex(g);
    ASSERT_EQ(2, num_vertices(g));

    pair<edge_descriptor, bool> p1 = add_edge(vdA, vdB, g);
    ASSERT_TRUE(p1.second);

    pair<edge_descriptor, bool> p2 = edge(vdA, vdB, g);
    ASSERT_TRUE(p2.second);
    
    ASSERT_EQ(p1.first, p2.first);
    ASSERT_EQ(1, num_edges(g));
}

TYPED_TEST(TestGraph, test_num_edges_2) {
    typedef typename TestFixture::graph_type         graph_type;
    typedef typename TestFixture::vertex_descriptor  vertex_descriptor;
    typedef typename TestFixture::edge_descriptor    edge_descriptor;
    typedef typename TestFixture::vertex_iterator    vertex_iterator;
    typedef typename TestFixture::edge_iterator      edge_iterator;
    typedef typename TestFixture::adjacency_iterator adjacency_iterator;
    typedef typename TestFixture::vertices_size_type vertices_size_type;
    typedef typename TestFixture::edges_size_type    edges_size_type;

    graph_type g;

    //add an edge between two unitialized vertices.
    vertex_descriptor vdA = 0;
    vertex_descriptor vdB = 1;

    pair<edge_descriptor, bool> p1 = add_edge(vdA, vdB, g);
    ASSERT_TRUE(p1.second);

    pair<edge_descriptor, bool> p2 = edge(vdA, vdB, g);
    ASSERT_TRUE(p2.second);
    
    ASSERT_EQ(p1.first, p2.first);
    ASSERT_EQ(1, num_edges(g));
}

TYPED_TEST(TestGraph, test_num_edges_3) {
    typedef typename TestFixture::graph_type         graph_type;
    typedef typename TestFixture::vertex_descriptor  vertex_descriptor;
    typedef typename TestFixture::edge_descriptor    edge_descriptor;
    typedef typename TestFixture::vertex_iterator    vertex_iterator;
    typedef typename TestFixture::edge_iterator      edge_iterator;
    typedef typename TestFixture::adjacency_iterator adjacency_iterator;
    typedef typename TestFixture::vertices_size_type vertices_size_type;
    typedef typename TestFixture::edges_size_type    edges_size_type;

    graph_type g;

    //try to add two edges that are the same.
    vertex_descriptor vdA = add_vertex(g);
    vertex_descriptor vdB = add_vertex(g);
    ASSERT_EQ(2, num_vertices(g));

    pair<edge_descriptor, bool> p1 = add_edge(vdA, vdB, g);
    ASSERT_TRUE(p1.second);

    pair<edge_descriptor, bool> p2 = add_edge(vdA, vdB, g);
    ASSERT_FALSE(p2.second);

    pair<edge_descriptor, bool> p3 = edge(vdA, vdB, g);
    ASSERT_TRUE(p3.second);
    
    ASSERT_EQ(p3.first, p2.first);
    ASSERT_EQ(p3.first, p1.first);
    ASSERT_EQ(1, num_edges(g));
}

TYPED_TEST(TestGraph, test_num_edges_4) {
    typedef typename TestFixture::graph_type         graph_type;
    typedef typename TestFixture::vertex_descriptor  vertex_descriptor;
    typedef typename TestFixture::edge_descriptor    edge_descriptor;
    typedef typename TestFixture::vertex_iterator    vertex_iterator;
    typedef typename TestFixture::edge_iterator      edge_iterator;
    typedef typename TestFixture::adjacency_iterator adjacency_iterator;
    typedef typename TestFixture::vertices_size_type vertices_size_type;
    typedef typename TestFixture::edges_size_type    edges_size_type;

    graph_type g;

    //add multiple edges.
    vertex_descriptor vdA;
    vertex_descriptor vdB;

    for(int i = 0; i < 10; ++i){
        vdA = add_vertex(g);
        vdB = add_vertex(g);
        ASSERT_TRUE(add_edge(vdA, vdB, g).second);
    }

    ASSERT_EQ(10, num_edges(g));
}

// ------
// source
// ------

TYPED_TEST(TestGraph, test_source_1) {
    typedef typename TestFixture::graph_type         graph_type;
    typedef typename TestFixture::vertex_descriptor  vertex_descriptor;
    typedef typename TestFixture::edge_descriptor    edge_descriptor;
    typedef typename TestFixture::vertex_iterator    vertex_iterator;
    typedef typename TestFixture::edge_iterator      edge_iterator;
    typedef typename TestFixture::adjacency_iterator adjacency_iterator;
    typedef typename TestFixture::vertices_size_type vertices_size_type;
    typedef typename TestFixture::edges_size_type    edges_size_type;

    graph_type g;

    vertex_descriptor vdA = add_vertex(g);
    vertex_descriptor vdB = add_vertex(g);
    ASSERT_EQ(2, num_vertices(g));
    
    pair<edge_descriptor, bool> p1 = add_edge(vdA, vdB, g);
    ASSERT_TRUE(p1.second);
    ASSERT_EQ(1, num_edges(g));

    vertex_descriptor vdC = source(p1.first, g);
    ASSERT_EQ(vdA, vdC);    
}

TYPED_TEST(TestGraph, test_source_2) {
    typedef typename TestFixture::graph_type         graph_type;
    typedef typename TestFixture::vertex_descriptor  vertex_descriptor;
    typedef typename TestFixture::edge_descriptor    edge_descriptor;
    typedef typename TestFixture::vertex_iterator    vertex_iterator;
    typedef typename TestFixture::edge_iterator      edge_iterator;
    typedef typename TestFixture::adjacency_iterator adjacency_iterator;
    typedef typename TestFixture::vertices_size_type vertices_size_type;
    typedef typename TestFixture::edges_size_type    edges_size_type;

    graph_type g;

    vertex_descriptor vdA = add_vertex(g);
    vertex_descriptor vdB = add_vertex(g);
    ASSERT_EQ(2, num_vertices(g));
    
    pair<edge_descriptor, bool> p1 = add_edge(vdA, vdB, g);
    pair<edge_descriptor, bool> p2 = add_edge(vdA, vdB, g);
    ASSERT_TRUE(p1.second);
    ASSERT_FALSE(p2.second);
    ASSERT_EQ(1, num_edges(g));

    vertex_descriptor vdC = source(p1.first, g);
    ASSERT_EQ(vdA, vdC);
    vertex_descriptor vdD = source(p2.first, g);
    ASSERT_EQ(vdA, vdD);
}

TYPED_TEST(TestGraph, test_source_3) {
    typedef typename TestFixture::graph_type         graph_type;
    typedef typename TestFixture::vertex_descriptor  vertex_descriptor;
    typedef typename TestFixture::edge_descriptor    edge_descriptor;
    typedef typename TestFixture::vertex_iterator    vertex_iterator;
    typedef typename TestFixture::edge_iterator      edge_iterator;
    typedef typename TestFixture::adjacency_iterator adjacency_iterator;
    typedef typename TestFixture::vertices_size_type vertices_size_type;
    typedef typename TestFixture::edges_size_type    edges_size_type;

    graph_type g;

    vertex_descriptor vdA = add_vertex(g);
    vertex_descriptor vdB = add_vertex(g);
    vertex_descriptor vdC = add_vertex(g);
    vertex_descriptor vdD = add_vertex(g);
    ASSERT_EQ(4, num_vertices(g));
    
    pair<edge_descriptor, bool> p1 = add_edge(vdA, vdB, g);
    pair<edge_descriptor, bool> p2 = add_edge(vdC, vdD, g);
    ASSERT_TRUE(p1.second);
    ASSERT_TRUE(p2.second);
    ASSERT_EQ(2, num_edges(g));

    vertex_descriptor vdE = source(p1.first, g);
    ASSERT_EQ(vdA, vdE);
    vertex_descriptor vdF = source(p2.first, g);
    ASSERT_EQ(vdC, vdF);
    ASSERT_NE(vdE, vdF);
}

// ------
// target
// ------

TYPED_TEST(TestGraph, test_target_1) {
    typedef typename TestFixture::graph_type         graph_type;
    typedef typename TestFixture::vertex_descriptor  vertex_descriptor;
    typedef typename TestFixture::edge_descriptor    edge_descriptor;
    typedef typename TestFixture::vertex_iterator    vertex_iterator;
    typedef typename TestFixture::edge_iterator      edge_iterator;
    typedef typename TestFixture::adjacency_iterator adjacency_iterator;
    typedef typename TestFixture::vertices_size_type vertices_size_type;
    typedef typename TestFixture::edges_size_type    edges_size_type;

    graph_type g;

    vertex_descriptor vdA = add_vertex(g);
    vertex_descriptor vdB = add_vertex(g);
    ASSERT_EQ(2, num_vertices(g));
    
    pair<edge_descriptor, bool> p1 = add_edge(vdA, vdB, g);
    ASSERT_TRUE(p1.second);
    ASSERT_EQ(1, num_edges(g));

    vertex_descriptor vdC = target(p1.first, g);
    ASSERT_EQ(vdB, vdC);    
}

TYPED_TEST(TestGraph, test_target_2) {
    typedef typename TestFixture::graph_type         graph_type;
    typedef typename TestFixture::vertex_descriptor  vertex_descriptor;
    typedef typename TestFixture::edge_descriptor    edge_descriptor;
    typedef typename TestFixture::vertex_iterator    vertex_iterator;
    typedef typename TestFixture::edge_iterator      edge_iterator;
    typedef typename TestFixture::adjacency_iterator adjacency_iterator;
    typedef typename TestFixture::vertices_size_type vertices_size_type;
    typedef typename TestFixture::edges_size_type    edges_size_type;

    graph_type g;

    vertex_descriptor vdA = add_vertex(g);
    vertex_descriptor vdB = add_vertex(g);
    ASSERT_EQ(2, num_vertices(g));
    
    pair<edge_descriptor, bool> p1 = add_edge(vdA, vdB, g);
    pair<edge_descriptor, bool> p2 = add_edge(vdA, vdB, g);
    ASSERT_TRUE(p1.second);
    ASSERT_FALSE(p2.second);
    ASSERT_EQ(1, num_edges(g));

    vertex_descriptor vdC = target(p1.first, g);
    ASSERT_EQ(vdB, vdC);
    vertex_descriptor vdD = target(p2.first, g);
    ASSERT_EQ(vdB, vdD);
}

TYPED_TEST(TestGraph, test_target_3) {
    typedef typename TestFixture::graph_type         graph_type;
    typedef typename TestFixture::vertex_descriptor  vertex_descriptor;
    typedef typename TestFixture::edge_descriptor    edge_descriptor;
    typedef typename TestFixture::vertex_iterator    vertex_iterator;
    typedef typename TestFixture::edge_iterator      edge_iterator;
    typedef typename TestFixture::adjacency_iterator adjacency_iterator;
    typedef typename TestFixture::vertices_size_type vertices_size_type;
    typedef typename TestFixture::edges_size_type    edges_size_type;

    graph_type g;

    vertex_descriptor vdA = add_vertex(g);
    vertex_descriptor vdB = add_vertex(g);
    vertex_descriptor vdC = add_vertex(g);
    vertex_descriptor vdD = add_vertex(g);
    ASSERT_EQ(4, num_vertices(g));
    
    pair<edge_descriptor, bool> p1 = add_edge(vdA, vdB, g);
    pair<edge_descriptor, bool> p2 = add_edge(vdC, vdD, g);
    ASSERT_TRUE(p1.second);
    ASSERT_TRUE(p2.second);
    ASSERT_EQ(2, num_edges(g));

    vertex_descriptor vdE = target(p1.first, g);
    ASSERT_EQ(vdB, vdE);
    vertex_descriptor vdF = target(p2.first, g);
    ASSERT_EQ(vdD, vdF);
    ASSERT_NE(vdE, vdF);
}


// TYPED_TEST(TestGraph, test_edge) {
//     typedef typename TestFixture::graph_type         graph_type;
//     typedef typename TestFixture::vertex_descriptor  vertex_descriptor;
//     typedef typename TestFixture::edge_descriptor    edge_descriptor;
//     typedef typename TestFixture::vertex_iterator    vertex_iterator;
//     typedef typename TestFixture::edge_iterator      edge_iterator;
//     typedef typename TestFixture::adjacency_iterator adjacency_iterator;
//     typedef typename TestFixture::vertices_size_type vertices_size_type;
//     typedef typename TestFixture::edges_size_type    edges_size_type;

//     graph_type g;

//     vertex_descriptor vdA = add_vertex(g);
//     vertex_descriptor vdB = add_vertex(g);

//     edge_descriptor edAB = add_edge(vdA, vdB, g).first;

//     pair<edge_descriptor, bool> p1 = add_edge(vdA, vdB, g);
//     ASSERT_EQ(edAB,  p1.first);
//     ASSERT_EQ(false, p1.second);

//     pair<edge_descriptor, bool> p2 = edge(vdA, vdB, g);
//     ASSERT_EQ(edAB, p2.first);
//     ASSERT_EQ(true, p2.second);

//     edges_size_type es = num_edges(g);
//     ASSERT_EQ(1, es);

//     vertex_descriptor vd1 = source(edAB, g);
//     ASSERT_EQ(vdA, vd1);

//     vertex_descriptor vd2 = target(edAB, g);
//     ASSERT_EQ(vdB, vd2);}

// --------
// vertices
// --------
    

TYPED_TEST(TestGraph, test_vertices) {
    typedef typename TestFixture::graph_type         graph_type;
    typedef typename TestFixture::vertex_descriptor  vertex_descriptor;
    typedef typename TestFixture::edge_descriptor    edge_descriptor;
    typedef typename TestFixture::vertex_iterator    vertex_iterator;
    typedef typename TestFixture::edge_iterator      edge_iterator;
    typedef typename TestFixture::adjacency_iterator adjacency_iterator;
    typedef typename TestFixture::vertices_size_type vertices_size_type;
    typedef typename TestFixture::edges_size_type    edges_size_type;

    graph_type g;

    vertex_descriptor vdA = add_vertex(g);
    vertex_descriptor vdB = add_vertex(g);

    pair<vertex_iterator, vertex_iterator> p = vertices(g);
    vertex_iterator                        b = p.first;
    vertex_iterator                        e = p.second;
    
    if (b != e) {
        vertex_descriptor vd = *b;
        ASSERT_EQ(vdA, vd);}
    ++b;
    if (b != e) {
        vertex_descriptor vd = *b;
        ASSERT_EQ(vdB, vd);}
    ++b;
    ASSERT_EQ(e, b);
}

// TYPED_TEST(TestGraph, test_edges) {
//     typedef typename TestFixture::graph_type         graph_type;
//     typedef typename TestFixture::vertex_descriptor  vertex_descriptor;
//     typedef typename TestFixture::edge_descriptor    edge_descriptor;
//     typedef typename TestFixture::vertex_iterator    vertex_iterator;
//     typedef typename TestFixture::edge_iterator      edge_iterator;
//     typedef typename TestFixture::adjacency_iterator adjacency_iterator;
//     typedef typename TestFixture::vertices_size_type vertices_size_type;
//     typedef typename TestFixture::edges_size_type    edges_size_type;

//     graph_type g;

//     vertex_descriptor vdA = add_vertex(g);
//     vertex_descriptor vdB = add_vertex(g);
//     vertex_descriptor vdC = add_vertex(g);

//     edge_descriptor edAB = add_edge(vdA, vdB, g).first;
//     edge_descriptor edAC = add_edge(vdA, vdC, g).first;

//     pair<edge_iterator, edge_iterator> p = edges(g);
//     edge_iterator                      b = p.first;
//     edge_iterator                      e = p.second;
//     if (b != e) {
//         edge_descriptor ed = *b;
//         ASSERT_EQ(edAB, ed);}
//     ++b;
//     if (b != e) {
//         edge_descriptor ed = *b;
//         ASSERT_EQ(edAC, ed);}
//     ++b;
//     ASSERT_EQ(e, b);}


// TYPED_TEST(TestGraph, test_adjacent_vertices) {
//     typedef typename TestFixture::graph_type         graph_type;
//     typedef typename TestFixture::vertex_descriptor  vertex_descriptor;
//     typedef typename TestFixture::edge_descriptor    edge_descriptor;
//     typedef typename TestFixture::vertex_iterator    vertex_iterator;
//     typedef typename TestFixture::edge_iterator      edge_iterator;
//     typedef typename TestFixture::adjacency_iterator adjacency_iterator;
//     typedef typename TestFixture::vertices_size_type vertices_size_type;
//     typedef typename TestFixture::edges_size_type    edges_size_type;

//     graph_type g;

//     vertex_descriptor vdA = add_vertex(g);
//     vertex_descriptor vdB = add_vertex(g);
//     vertex_descriptor vdC = add_vertex(g);

//     add_edge(vdA, vdB, g);
//     add_edge(vdA, vdC, g);

//     pair<adjacency_iterator, adjacency_iterator> p = adjacent_vertices(vdA, g);
//     adjacency_iterator                           b = p.first;
//     adjacency_iterator                           e = p.second;
//     if (b != e) {
//         vertex_descriptor vd = *b;
//         ASSERT_EQ(vdB, vd);}
//     ++b;
//     if (b != e) {
//         vertex_descriptor vd = *b;
//         ASSERT_EQ(vdC, vd);}
//     ++b;
//     ASSERT_EQ(e, b);}
