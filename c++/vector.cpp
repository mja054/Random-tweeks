#include <iostream>
#include <vector>
using namespace std;

/* Method's declared under vector class
   - size()
   - push_back: <vector_variable>.push_back(element)
   - end()
   - begin()
*/
struct node {
        int a;
        char c;
};
typedef struct node Node;

int
main ()
{
        vector<Node> list(10);
        Node tmp;

        tmp.a = 100;
        tmp.c = 'R';

        for (int i = 0; i < 10; i++) {
                list[i].a = i;
                list[i].c = 0x41 + i;
        }

        cout << "size of vector = " << list.size() << endl;

        list.push_back(tmp);

        cout << "size of vector = " << list.size() << endl;

        for (int i = 0; i < list.size(); i++)
                cout << list[i].a << " " << list[i].c << endl;

        return 0;
}
