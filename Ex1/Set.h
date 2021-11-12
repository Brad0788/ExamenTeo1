#include "V.h"
#include "E.h"
#include <vector>
using namespace std; 
class Set{
    
};

class SetV : public Set{
    public:
        SetV();
        SetV(vector<V>);
        vector<V> w;
};

class SetE : public Set{
    public:
        SetE();
        SetE(vector<E>);
        vector<E> w;
};