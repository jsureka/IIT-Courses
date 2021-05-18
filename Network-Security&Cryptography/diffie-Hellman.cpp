#include<bits/stdc++.h>
using namespace std;
bool check_prim(long long p,long long g)
{
    if(__gcd(p, g)==1)
        return true;
    return false;
}

long long int power(long long int a, long long int b,
                                     long long int P)
{
    if (b == 1)
        return a;

    else
        return (((long long int)pow(a, b)) % P);
}

//Driver program
int main()
{
    long long int P, G, x, a, y, b, ka, kb;
    P = 101;
    printf("The value of P : %lld\n", P);

    G = 3;
    printf("The value of G : %lld\n\n", G);
    if(!check_prim(P,G))
        {
            cout<< "Not a primitive Root";
            return 0;

        }
    a = 4;
    printf("The private key a for Alice : %lld\n", a);
    x = power(G, a, P);

    b = 3;
    printf("The private key b for Bob : %lld\n\n", b);
    y = power(G, b, P); // gets the generated key
    ka = power(y, a, P); // Secret key for Alice
    kb = power(x, b, P); // Secret key for Bob

    printf("Secret key for the Alice is : %lld\n", ka);
    printf("Secret Key for the Bob is : %lld\n", kb);

    return 0;
}
