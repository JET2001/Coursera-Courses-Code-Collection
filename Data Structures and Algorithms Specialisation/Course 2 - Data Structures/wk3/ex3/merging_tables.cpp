/*
 Problem Introduction
 In this problem, your goal is to simulate a sequence of merge operations with tables in a database.
 Problem Description
 Task. There are π tables stored in some database. The tables are numbered from 1 to π. All tables share the same set of columns. Each table contains either several rows with real data or a symbolic link to another table. Initially, all tables contain data, and π-th table has ππ rows. You need to perform π of the following operations:
 1. Consider table number πππ π‘ππππ‘ππππ. Traverse the path of symbolic links to get to the data. That is,
 while πππ π‘ππππ‘ππππ contains a symbolic link instead of real data do πππ π‘ππππ‘ππππ β symlink(πππ π‘ππππ‘ππππ)
 2. Consider the table number π ππ’ππππ and traverse the path of symbolic links from it in the same manner as for πππ π‘ππππ‘ππππ.
 3. Now, πππ π‘ππππ‘ππππ and π ππ’ππππ are the numbers of two tables with real data. If πππ π‘ππππ‘ππππ ΜΈ= π ππ’ππππ, copy all the rows from table π ππ’ππππ to table πππ π‘ππππ‘ππππ, then clear the table π ππ’ππππ and instead of real data put a symbolic link to πππ π‘ππππ‘ππππ into it.
 4. Print the maximum size among all π tables (recall that size is the number of rows in the table). If the table contains only a symbolic link, its size is considered to be 0.
 
 
 See examples and explanations for further clarifications.

 Input Format. The first line of the input contains two integers π and π β the number of tables in the database and the number of merge queries to perform, respectively.
 The second line of the input contains π integers ππ β the number of rows in the π-th table.
 Then follow π lines describing merge queries. Each of them contains two integers πππ π‘ππππ‘ππππ and π ππ’ππππ β the numbers of the tables to merge.
 
 Constraints. 1 β€ π, π β€ 100 000; 0 β€ π_π β€ 10 000; 1 β€ πππ π‘ππππ‘πππ_π, π ππ’πππ_π β€ π.
 
 Output Format. For each query print a line containing a single integer β the maximum of the sizes of all tables (in terms of the number of rows) after the corresponding operation.
 
 */
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::max;
using std::vector;

using namespace std;
struct DisjointSetsElement {
    int size, parent, rank;
    
    DisjointSetsElement(int size = 0, int parent = -1, int rank = 0): // default values
        size(size), parent(parent), rank(rank) {}//constructor
};

bool compareSize (const DisjointSetsElement &set1, const DisjointSetsElement &set2)
{return (set1.size > set2.size); }//descending order

struct DisjointSets {
    int size;
    int max_table_size;
    vector <DisjointSetsElement> sets; // vector that contains DisjointsetsElements

    DisjointSets(int size): size(size), max_table_size(0), sets(size) {
        for (int i = 0; i < size; i++)
            sets[i].parent = i;
    }

    int getParent(int table) {
        // find parent and compress path
        // Traverse symbolic links to find the set ID
        if (sets[table].parent != table)
        {
            sets[table].parent = getParent(sets[table].parent); // Path compression
        }
        return sets[table].parent;
    }

    void merge(int destination, int source) {
        // Actually I wasn't paying attention to the 1 based index when writing this function
        // Let's see how this goes in the debugger
        if (destination == source)
            return; //Don't waste my program's time.
        int realDestination = getParent(destination);
        int realSource = getParent(source);
        if (realDestination != realSource) {
            // merge two components (Union operation)
            sets[realSource].parent = realDestination; //symbolic link
            // use union by rank heuristic
            sets[realDestination].size += sets[realSource].size; //add 'data' from source to destination
            // set size of the source to 0
            sets[realSource].size = 0;
            // update max_table_size
            max_table_size = max(sets[realDestination].size, max_table_size);
            return;
        }// end outer if
        else // if realDest ==
            return;
    }// end merge
};

int main() {
    int n, m;
    cin >> n >> m;

    DisjointSets tables(n);
    for (auto &table : tables.sets) {
        cin >> table.size;
        tables.max_table_size = max(tables.max_table_size, table.size);
    }

    for (int i = 0; i < m; i++) {
        int destination, source;
        cin >> destination >> source;
                --destination; // decrement by 1
                --source; // decrement by 1
        
        tables.merge(destination, source);
            cout << tables.max_table_size << endl;
    }

    return 0;
}
