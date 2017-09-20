#include <iostream>
#include <fstream>

using namespace std;

int process(char* &curr);

int main(void)
{
    // recording the text from file to the array
    char buffer[101];
    char input[] = "input.txt";
    ifstream in(input, ios_base::in);
    if (!in.is_open())
    {
        cout << "Error! File " << input << " not found!\n";
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
    char output[] = "output.txt";
    ofstream out(output, ios_base::out);
    if (!out.is_open())
    {
        cout << "Error! Cannot open " << output << endl;
        exit(-3);
    }
    out << "There are " << result << " ones in the longest chain!\n";
    out.close();
    
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