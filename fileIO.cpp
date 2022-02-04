/* *~*~*
File Input Output functions to be included in main
Written by: Valery Leslie Tanada
IDE: Xcode
*~**/

// function prototypes
void buildManager (string input, BinarySearchTree<County> &bst, HashTable<County> &hash);
int nextPrime (int size);
bool isPrime(int num);
int key_to_index(const County &key, int size);
void writeOutput (HashTable<County> &hash);

void buildManager (string input, BinarySearchTree<County> &bst, HashTable<County> &hash)
{
    // opening the file
    ifstream inFile;
    inFile.open(input.c_str());

    if(inFile.fail())
    {
        cout << "Error opening the input file: \""<< input << "\"" << endl;
        exit(EXIT_FAILURE);
    }

    int hashSize = 0; // hash size
    int numRows, numEntries = 0; // to hold the number of rows and entries

    // reading the number of rows and entries
    inFile >> numRows >> numEntries;
    cout << "Number of Entries: " << numEntries << endl;
    
    hashSize = nextPrime(numEntries*2);
    HashTable<County> temp(hashSize);

    // County member variables
    string c; // county
    string cd; // code
    int pop; // population
    int cs; // cases
    int dh; // deaths
    County arr[numEntries*5];   // array of county objects for insertion with different
                                // addresses into the BST
    int count = 0;
    
    // making County objects and inserting to hash and BST
    for (int i = 0; i < numRows; i++)
    {
        inFile >> c >> pop;
        for (int k = 0; k < 5; k++)
        {
            inFile >> cd >> cs >> dh;
            arr[count].setCounty(c);
            arr[count].setPopulation(pop);
            arr[count].setCases(cs);
            arr[count].setDeaths(dh);
            arr[count].setCode(cd);
            County* ptr = &(arr[count]);
            hash.insert(arr[count], key_to_index);
            bst.insert(c, ptr);
            count++;
        }
    }
    
    hash = temp; // make the hash the temp, with the correct hashSize

    inFile.close(); // close the file
}

// Function to find the next prime number
int nextPrime (int size)
{
    int prime = size;
    bool flag = false;
    
    if (size <= 1)
        return 2;
    while (!flag)
    {
        prime++;
        if (isPrime(prime))
            flag = true;
    }
    return prime;
}

// Function that returns true if num is a prime number
// and false otherwise
bool isPrime(int num)
{
    for (int i = 2; i < num; i++)
    {
        if (num % i == 0)
            return false;
    }
    return true;
}

/*~*~*~*
 Hash function: takes the key and returns the index in the hash table
 *~**/
int key_to_index(const County &key, int size)
{
    string k = key.getCode();
    int sum = 0;
    for (int i = 0; k[i]; i++)
        sum += k[i];
    return sum % size;
}

/*~*~*~*
writeOutput function, writes into the output file in order of the hash function
*~**/
void writeOutput (HashTable<County> &hash)
{
    string output;
    cout << "Enter the name of your output file: " << endl;
    cin >> output;
    
    ofstream oFile;
    oFile.open(output);
    int num = 0;
    
    for (int i = 0; i < hash.getSize(); i++)
    {
        County out;
        bool flag = hash.remove(out, i);
        if (flag)
        {
            oFile << left;
            oFile << setw(7) << out.getCounty();
            oFile << setw(11) << out.getPopulation();
            oFile << setw(8) << out.getCode();
            oFile << setw(6) << out.getCases();
            oFile << out.getDeaths() << endl;
        }
    }

    oFile.close();
}
