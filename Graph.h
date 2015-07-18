// --------------------------
// projects/c++/graph/Graph.h
// Copyright (C) 2015
// Glenn P. Downing
// --------------------------

#ifndef Graph_h
#define Graph_h

// --------
// includes
// --------

#include <cassert> // assert
#include <cstddef> // size_t
#include <utility> // make_pair, pair
#include <vector>  // vector
#include <set>

// -----
// Graph
// -----

using namespace std;

class Graph {
    public:
        // --------
        // typedefs
        // --------

        typedef int vertex_descriptor;  // fix! // an index for a vertex in the graph. 
        typedef int edge_descriptor;    // fix!

        typedef int* vertex_iterator;    // fix!
        typedef int* edge_iterator;      // fix!
        typedef int* adjacency_iterator; // fix!

        typedef std::size_t vertices_size_type;
        typedef std::size_t edges_size_type;

    public:
        // --------
        // add_edge
        // --------

        /**
         * @param u a vertex descriptor of source edge.
         * @param v a vertex descriptor of target edge.
         * @param graph the graph to insert the edge into.
         * @return a std::pair of the resulting edge descriptor and a success boolean.
         * boolean set to true if the edge was made, false otherwise. 
         * NOTE: adds missing vertices to the graph automatically if the vertices don’t exist. 
         */
        friend std::pair<edge_descriptor, bool> add_edge (vertex_descriptor u, vertex_descriptor v, Graph& graph) {
            // <your code>
            if(u > graph.vertex_index || v > graph.vertex_index){
                //cout << "makeing more vertices" << endl;
                //increase size of v_list.
                for(int i = graph.vertex_index; i < (std::max(u, v) + 1); ++i)
                    add_vertex(graph);
            }
            
            //store new association in vector container.
            if(graph.v_list.at(u).insert(v).second){
                //cout << "seems we need to add the edge" << endl;
                //store new association in edge container.
                std::vector<vertex_descriptor> e = {u, v};
                graph.e_list.push_back(e);
                ++graph.e_size;                
                return std::make_pair(++graph.edge_index, true);
            }
            //otherwise, get information from e_list
            //cout << "edge all ready exists apparently" << endl;
            return std::make_pair(edge(u, v, graph).first, false);
        }

        // ----------
        // add_vertex
        // ----------

        /**
         * @param graph the graph to insert the vertex into.
         * @return a vertex_descriptor for this new vertex.
         * Adds a vertex to the graph.
         */
        friend vertex_descriptor add_vertex (Graph& graph) {
            graph.v_list.push_back(std::set<vertex_descriptor> ());
            ++graph.v_size;
            return ++graph.vertex_index;
        }

        // -----------------
        // adjacent_vertices
        // -----------------

        /**
         * returns a pair of iterators that refer to the points a point connects to.
         */
        friend std::pair<adjacency_iterator, adjacency_iterator> adjacent_vertices (vertex_descriptor, const Graph&) {
            // <your code>
            static int a [] = {0, 0};     // dummy data
            adjacency_iterator b = a;
            adjacency_iterator e = a + 2;
            return std::make_pair(b, e);}

        // ----
        // edge
        // ----

        /**
         * @param u a vertex descriptor of source edge.
         * @param v a vertex descriptor of target edge.
         * @param graph the graph to insert the edge into.
         * @return a pair contining an edge descriptor and a success boolean.
         * If an edge from vertex u to vertex v exists, return a pair containing one such edge and true. 
         * If there are no edges between u and v, return a pair with an arbitrary edge descriptor and false.
         */
        friend std::pair<edge_descriptor, bool> edge (vertex_descriptor u, vertex_descriptor v, const Graph& graph) {
            // <your code>

            for(edges_size_type i = 0; i < graph.e_size; ++i){
                std::vector<vertex_descriptor> vec = graph.e_list.at((int)i);
                assert(vec.size() == 2);
                //cout << "in edge: i: " << i << endl;
                if(vec.at(0) == u && vec.at(1) == v){
                    //cout << "in edge: found the right edge" << endl;
                    return std::make_pair(edge_descriptor(i), true);
                }
            }
            //otherwise, the edge does not exist.
            //cout << "in edge: did not find the right edge discriptor" << endl;
            return std::make_pair(edge_descriptor(-1), false);
        }

        // -----
        // edges
        // -----

        /**
         * Provides access to all lines (or edges) in a graph
         * returns two iterators that point to the first and last line (or edge)
         */
        friend std::pair<edge_iterator, edge_iterator> edges (const Graph&) {
            // <your code>
            static int a [] = {0, 0};     // dummy data
            edge_iterator b = a;
            edge_iterator e = a + 2;
            return std::make_pair(b, e);}

        // ---------
        // num_edges
        // ---------

        /**
         * @param graph the graph instance
         * @return the number of edges in the given graph.
         */
        friend edges_size_type num_edges (const Graph& graph) {
            // <your code>
            edges_size_type e = 1; // fix
            return e;
        }

        // ------------
        // num_vertices
        // ------------

        /**
         * @param graph the graph instance
         * @return the number of vertices in the given graph.
         */
        friend vertices_size_type num_vertices (const Graph& graph) {
            // <your code>
            return graph.v_size;
        }
        // ------
        // source
        // ------

        /**
         * The start point is returned
         */
        friend vertex_descriptor source (edge_descriptor, const Graph&) {
            // <your code>
            vertex_descriptor v = 0; // fix
            return v;}

        // ------
        // target
        // ------

        /**
         * returns the end point of a line
         */
        friend vertex_descriptor target (edge_descriptor, const Graph&) {
            // <your code>
            vertex_descriptor v = 0; // fix
            return v;}

        // ------
        // vertex
        // ------

        /**
         * @param n the nth vertex
         * @param graph the graph to be searched.
         * @return the nth vertex in the graph's vertex list.
         */
        friend vertex_descriptor vertex (vertices_size_type n, const Graph& graph) { //tested
            if(n >= 0 && n < graph.v_size)
                return vertex_descriptor(n);
            return vertex_descriptor(-1);
        }

        // --------
        // vertices
        // --------

        /**
         * get all points from a graph
         * This function returns two iterators of type 
         * vertex_iterator, which refer to the beginning and ending points.
         */
        friend std::pair<vertex_iterator, vertex_iterator> vertices (const Graph&) {
            // <your code>
            static int a [] = {0, 0};     // dummy data
            vertex_iterator b = a;
            vertex_iterator e = a + 2;
            return std::make_pair(b, e);}

    private:
        // ----
        // data
        // ----

        std::vector< std::set<vertex_descriptor> > v_list; //vector container 
        std::vector< std::vector<vertex_descriptor> > e_list; //edge container 

        vertex_descriptor vertex_index; //vertex index
        edge_descriptor edge_index; //edge index

        vertices_size_type v_size;
        edges_size_type e_size;
        // -----
        // valid
        // -----

        /**
         * <your documentation>
         */
        bool valid () const {
            // <your code>
            return true;}

    public:
        // ------------
        // constructors
        // ------------

        /**
         * Creates an empty Graph instance
         */
        Graph () :            // <your code>
                v_list(0), 
                e_list(0) {
                vertex_index = edge_index = -1;
                v_size = e_size = 0;
                assert(valid());
        }

        // Default copy, destructor, and copy assignment
        // Graph  (const Graph<T>&);
        // ~Graph ();
        // Graph& operator = (const Graph&);
    };

#endif // Graph_h
