#include<iostream>
#include<vector>

using namespace std;

void find_primes_between(int l, int r) {
    vector<bool> is_prime(r+1, true);

    is_prime[0] = is_prime[1] = false;

    for (int i = 2; i*i <= r; ++i) {
        if (is_prime[i]) {
            for (int j = i*i; j <= r; j += i) {
                is_prime[j] = false;
            }
        }
    }

    for(int i = l; i <= r; ++i) {
        if (is_prime[i]) {
            cout<<i<<endl;
        }
    }
}

int main() {
    cout<<"Enter range of numbers to find prime (l, r)"<<endl;

    int l, r;
    cin>>l>>r;

    find_primes_between(l, r);


}