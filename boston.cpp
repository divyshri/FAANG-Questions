#include <iostream>
#include <vector>
#include <cmath>
#define ll long long int
using namespace std;

vector<ll> get_all_prime_fector(ll n)
{
    vector<ll> v;

    while (n % 2 == 0)
    {
        n /= 2;
        v.push_back(2);
    }
    for (int i = 3; i <= sqrt(n) + 1; i += 2)
    {
        while (n % i == 0)
        {
            v.push_back(i);
            n /= i;
        }
    }
    if (n > 2)
        v.push_back(n);

    return v;
}

int compute_sum(vector<ll> arr)
{
    int sum = 0;
    for (auto i : arr)
    {
        while (i)
        {
            sum += i % 10;
            i /= 10;
        }
    }

    return sum;
}

bool is_boston(ll num)
{
    ll x = num, sum = 0;
    while (x)
    {
        sum += x % 10;
        x /= 10;
    }

    vector<ll> v = get_all_prime_fector(num);
    ll sum2 = compute_sum(v);
    return sum == sum2;
}
int main()
{
    ll x;
    cin >> x;
    cout << is_boston(x);
    return 0;
}