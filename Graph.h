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

        typedef vector<vertex_descriptor>::iterator vertex_iterator;    // fix!
        typedef vector<edge_descriptor>::iterator edge_iterator;      // fix!
        typedef vertex_descriptor* adjacency_iterator; // fix!

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
            if(u > graph.vertex_index || v > graph.vertex_index){
                //increase size of v_list.
                for(int i = graph.vertex_index; i < (std::max(u, v)); ++i)
                    add_vertex(graph);
            }
            
            //store new association in vector container.
            if(graph.v_list.at(u).insert(v).second){
                //store new association in edge container.
                std::vector<vertex_descriptor> e = {u, v};
                graph.e_list.push_back(e);
                ++graph.e_size;                
                return std::make_pair(++graph.edge_index, true);
            }
            //otherwise, get information from e_list
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
            // trys to find the matching edge.
            for(edges_size_type i = 0; i < graph.e_size; ++i){
                std::vector<vertex_descriptor> vec = graph.e_list.at((int)i);
                assert(vec.size() == 2);
                if(vec.at(0) == u && vec.at(1) == v){
                    return std::make_pair(edge_descriptor(i), true);
                }
            }
            //otherwise, the edge does not exist.
            return std::make_pair(edge_descriptor(-1), false);
        }

        // -----
        // edges
        // -----

        /**
         * @param graph the graph instance
         * @return two iterators of type edge_iterator, 
         * which refer to the beginning and ending edges in the graph.
         */
        friend std::pair<edge_iterator, edge_iterator> edges (const Graph& graph) {
            
            static vector<edge_descriptor> ea(graph.e_size);
            for(int i = 0; i < graph.e_size; ++i)
                 ea[i] = edge_descriptor(i);
            
            if(graph.e_size == 0){ //special case due to boost iterator using an array and not vector
                return std::make_pair(ea.begin(), ea.begin());
            }

            return std::make_pair(ea.begin(), ea.end());
        }

        // ---------
        // num_edges
        // ---------

        /**
         * @param graph the graph instance
         * @return the number of edges in the given graph.
         */
        friend edges_size_type num_edges (const Graph& graph) {
            return graph.e_size;
        }

        // ------------
        // num_vertices
        // ------------

        /**
         * @param graph the graph instance
         * @return the number of vertices in the given graph.
         */
        friend vertices_size_type num_vertices (const Graph& graph) {
            return graph.v_size;
        }
        // ------
        // source
        // ------

        /**
         * @param ed an edge descriptor
         * @param graph a graph instance
         * @return the starting vertex of the given edge descriptor.
         */
        friend vertex_descriptor source (edge_descriptor ed, const Graph& graph) {
            if(ed > graph.edge_index && ed < 0)
                return vertex_descriptor(-1);
            return graph.e_list.at(ed).at(0);
        }

        // ------
        // target
        // ------

        /**
         * @param ed an edge descriptor
         * @param graph a graph instance
         * @return the end vertex of the given edge descriptor.
         */
        friend vertex_descriptor target (edge_descriptor ed, const Graph& graph) {
            if(ed > graph.edge_index && ed < 0)
                return vertex_descriptor(-1);
            return graph.e_list.at(ed).at(1);
        }

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
         * @param graph the graph instance
         * @return two iterators of type vertex_iterator, 
         * which refer to the beginning and ending vertices.
         */
        friend std::pair<vertex_iterator, vertex_iterator> vertices (const Graph& graph) {

            static vector<vertex_descriptor> va(graph.v_size);
            for(int i = 0; i < graph.v_size; ++i)
                 va[i] = i;
            
            if(graph.v_size == 0){ //special case due to boost using an array and not vector
                return std::make_pair(va.begin(), va.begin());
            }

            return std::make_pair(va.begin(), va.end());
        }

    private:
        // ----
        // data
        // ----

        std::vector< std::set<vertex_descriptor> > v_list; //vector container 
        std::vector< std::vector<vertex_descriptor> > e_list; //edge container 

        vertex_descriptor vertex_index; //vertex index
        edge_descriptor edge_index; //edge index

        vertices_size_type v_size; // vertex size
        edges_size_type e_size; // edge size
        // -----
        // valid
        // -----

        /**
         * <your documentation>
         */
        bool valid () const {
            return true;}

    public:
        // ------------
        // constructors
        // ------------

        /**
         * Creates an empty Graph instance
         */
        Graph () :    
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
