#include <iostream>
#include <vector>
#include <map>
using namespace std;

class iter
{
public:
        int
        iter_print(vector<int> a) {
                int cnt;
                vector<int>::iterator begin;
                vector<int>::iterator end;

                for (cnt = 0, begin = a.begin(), end = a.end();
                     begin != end; begin++, cnt++)
                        cout << *begin << endl;
                return cnt;
        }

        int
        iter_print(map<string, string> maps)
        {
                int cnt;
                map<string, string>::iterator begin;
                map<string, string>::iterator end;

                for (cnt = 0, begin = maps.begin(), end = maps.end();
                     begin != end; begin++, cnt++)
                        cout << begin->first << "-->" << begin->second << endl;

                return cnt;
        }
};

int
main ()
{
        char key[5][10]   = {"asdf", "jkl;", "wqer", "poiu", "zxcv"};
        char value[5][10] = {"1234", "2345", "3456", "4567", "5678"};
        iter iter_obj;

        // working with vectors
        vector<int> a(10);
        for (int i = 0; i < 10; i++)
                a[i] = i + 1;
        iter_obj.iter_print(a);

        // working with maps
        map<string, string> maps;
        for (int i = 0; i < 5; i++)
                maps[key[i]] = value[i];
        iter_obj.iter_print(maps);

        return 0;
}
