#include <bits/stdc++.h>

#define MOD 1000000007

using namespace std;

namespace math
{
    namespace prime
    {
        vector<long long int> prime;
        vector<long long int> use;
        void init(long long int b)
        {
            use.assign(b+1, 0);
            prime.clear();
            prime.push_back(2);
            use[2]=2;
            for(int i=3; i<use.size(); i+=2)
            {
                if(use[i] == 0LL)
                {
                    prime.push_back(i);
                    use[i]=i;
                    for(int j=i*2;j<use.size();j+=i)
                        use[j]=i;
                }
            }

        }
        int countPrimes()
        {
//            for(int i=0;i<prime.size();i++)
//                cout<<prime.at(i)<<endl;
            return prime.size();
        }
	bool isPrime(int b)
        {
            return binary_search(prime.begin(), prime.end(), b);
        }
    }
}
using namespace math;
int main()
{
    prime::init(100000000);
    cout<<prime::countPrimes();
    return 0;
}
