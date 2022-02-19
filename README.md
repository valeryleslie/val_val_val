# val_val_val
COVID - Bay Area Tracker June 2020 (C++)

The following project is meant as a practice of loading web-based data and applying the C++
binary search tree data structures onto Bay Area's Covid-19 cases by county. Statistical 
data taken from the web include biweekly datadates, deaths, cases, and population numbers. Data from
nine counties are accounted for (due to the vague nature of what is considered 'Bay Area'):
Alameda (ALM), Contra Costa (CC), Marin (MN), Napa (NP), San Mateo (SM), Santa Clara (SC), 
Solano (SL), Sonoma (SN), and San Francisco (SF).

A binary search tree would allow the insert, search, and deletion of data under user request.
The hash table is a method towards inserting, deleting, and searching the data. The difference between
these two would be to have user's be able to search through the data using different sets of keys,
by hash, users are able to search by the county codes (comprised of its initials and dates),
through the binary search. Other than that, display options of country rankings
are available through population numbers, number of deaths, and number of cases.

The structure of data loading, displaying, and search manager is as follows:
- Read Input File (inputfile.txt)
    - Build a County-based Class Object (County.h, County.cpp)
    - Build Binary Search Tree (BinaryNode.h, BinarySearchTree.h, BinaryTree.h)
        - BST data insert
- User interactive Menu
  - Add new county data
  - Delete a county data
  - Display all Bay Area Data Alphabetically
    - Binary Search Tree Display Manager (indented or ranking-wise display)
  - Search by County or Code
  - Save to Output File (e.g. outputfile.txt)
  - County Guides (showing users county codes)
  - Exit Program
