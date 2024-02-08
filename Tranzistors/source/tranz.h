#ifndef TRANZ_H
#define TRANZ_H
#define PRICE1 50
#define PRICE2 100
#define PRICE3 300
#define UT1 20
#define UT2 30
#define UT3 40
#include<vector>
#include<boost/random.hpp>

using std::vector;
class Tranz{
public:
    unsigned int breakProb;
    unsigned int price;
    Tranz(const unsigned int &bP, const unsigned int &p)
        : breakProb(bP)
        , price(p){};
};
int prob_Gen(vector<float> &v, int &iter){
    int listLen = v.size();
    if(iter<6){
        for (int i = iter; i<listLen; i++){
            v[i]+=0.1f;
        }
    }
    else{
        for (int i = 6; i<listLen; i++){
            v[i]+=0.1f;
        }
    }
    boost::random::discrete_distribution<int, float> dist(v);
    static unsigned int seed = 0;
    boost::mt19937 rng;
    rng.seed((++seed) + time(NULL));
    return dist(rng);
}
#endif // TRANZ_H
