#include <iostream>
#include <fstream>

using namespace std;

int process(char* &curr);

int main(void)
{
    // recording the text from file to the array
    char buffer[101];
    char filename[] = "input.txt";
    ifstream in(filename, ios_base::in);
    if (!in.is_open())
    {
        cout << "Error! File " << filename << " not found!\n";
        exit(-1);
    }
    in.getline(buffer, sizeof buffer);
    in.close();
    
    // counting the "ones" and determining the longest chain
    cout << buffer << endl;
    char* current = buffer;
    int result = 0, tmp = 0;
    while (*current)
    {
        tmp = process(current);
        if (tmp > result)
        {
            result = tmp;
        }
    }
    
    // outputting the result
    cout << "There are " << result << " ones in the longest chain!\n";
    
    system("pause");
    return 0;
}

int process(char* &curr)
{
    int ones = 0;
    bool loop = true;
    while (*curr == '0')
    {
        curr++;
    }
    while (loop)
    {
        switch (*curr)
        {
        case '1':
            ones++;
            curr++;
            break;
        case '0':
        case '\0':
            loop = false;
            break;
        default:
            cerr << "Incorrect symbol!\n";
            exit(-2);
        }
    }
    return ones;
}