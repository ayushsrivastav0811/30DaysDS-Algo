#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
#include <deque>
#include <bitset>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <functional>
#include <numeric>
#include <utility>
#include <limits>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include "bits/stdc++.h"
// #include "ext/pb_ds/assoc_container.hpp"
// #include "ext/pb_ds/tree_policy.hpp"

using namespace std;

/*******  All Required define Pre-Processors and typedef Constants *******/
#define SCD(t) scanf("%d",&t)
#define SCLD(t) scanf("%ld",&t)
#define SCLLD(t) scanf("%lld",&t)
#define SCC(t) scanf("%c",&t)
#define SCS(t) scanf("%s",t)
#define SCF(t) scanf("%f",&t)
#define SCLF(t) scanf("%lf",&t)
#define INP(t) cin>>t
#define INP2(t,u) cin>>t>>u
#define INP3(t,u,v) cin>>t>>u>>v
#define OUT(t) cout<<t<<endl
#define OUT2(t,u) cout<<t<<" "<<u<<endl
#define OUT3(t,u,v) cout<<t<<" "<<u<<" "<<v<<endl
#define MEM(a, b) memset(a, (b), sizeof(a))
#define FOR(i, j, k, in) for (int i=j ; i<k ; i+=in)
#define RFOR(i, j, k, in) for (int i=j ; i>=k ; i-=in)
#define REP(i, j) FOR(i, 0, j, 1)
#define RREP(i, j) RFOR(i, j, 0, 1)
#define INPV(a,n) REP(i, n) INP(a[i])
#define all(cont) cont.begin(), cont.end()
#define rall(cont) cont.end(), cont.begin()
#define FOREACH(it, l) for (auto it = l.begin(); it != l.end(); it++)
#define IN(A, B, C) assert( B <= A && A <= C)
#define MP make_pair
#define PB push_back
#define INF (int)1e9
#define EPS 1e-9
#define PI 3.1415926535897932384626433832795
// #define MOD 1000000007
#define read(type) readInt<type>()
const double pi = acos(-1.0);
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<unsigned long long int> VI64;
typedef vector<string> VS;
typedef vector<PII> VII;
typedef vector<VI> VVI;
typedef map<int, int> MPII;
typedef set<int> SETI;
typedef multiset<int> MSETI;
typedef long int int32;
typedef unsigned long int uint32;
typedef long long int int64;
typedef unsigned long long int  uint64;

/****** Template of some basic operations *****/
template<typename T, typename U> inline void amin(T &x, U y) { if (y < x) x = y; }
template<typename T, typename U> inline void amax(T &x, U y) { if (x < y) x = y; }
/**********************************************/

/****** Template of Fast I/O Methods *********/
template <typename T> inline void write(T x)
{
	int i = 20;
	char buf[21];
	// buf[10] = 0;
	buf[20] = '\n';

	do
	{
		buf[--i] = x % 10 + '0';
		x /= 10;
	} while (x);
	do
	{
		putchar(buf[i]);
	} while (buf[i++] != '\n');
}

template <typename T> inline T readInt()
{
	T n = 0, s = 1;
	char p = getchar();
	if (p == '-')
		s = -1;
	while ((p < '0' || p > '9') && p != EOF && p != '-')
		p = getchar();
	if (p == '-')
		s = -1, p = getchar();
	while (p >= '0' && p <= '9') {
		n = (n << 3) + (n << 1) + (p - '0');
		p = getchar();
	}

	return n * s;
}
/************************************/

/*/---------------------------RNG----------------------/*/
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
inline int64_t random_long(long long l = LLONG_MIN, long long r = LLONG_MAX) {
	uniform_int_distribution<int64_t> generator(l, r);
	return generator(rng);
}
struct custom_hash { // Credits: https://codeforces.com/blog/entry/62393
	static uint64_t splitmix64(uint64_t x) {
		// http://xorshift.di.unimi.it/splitmix64.c
		x += 0x9e3779b97f4a7c15;
		x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
		x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
		return x ^ (x >> 31);
	}
	size_t operator()(uint64_t x) const {
		static const uint64_t FIXED_RANDOM =
		    chrono::steady_clock::now().time_since_epoch().count();
		return splitmix64(x + FIXED_RANDOM);
	}
	template<typename L, typename R>
	size_t operator()(pair<L, R> const& Y) const {
		static const uint64_t FIXED_RANDOM =
		    chrono::steady_clock::now().time_since_epoch().count();
		return splitmix64(Y.first * 31 + Y.second + FIXED_RANDOM);
	}
};

/*/-----------------------Modular Arithmetic---------------/*/
const int mod = 1e9 + 7;
template<const int MOD>
struct modular_int {
	int x;
	static vector<int> inverse_list ;
	const static int inverse_limit;
	const static bool is_prime;
	modular_int() {
		x = 0;
	}
	template<typename T>
	modular_int(const T z) {
		x = (z % MOD);
		if (x < 0) x += MOD;
	}
	modular_int(const modular_int<MOD>* z) {
		x = z->x;
	}
	modular_int(const modular_int<MOD>& z) {
		x = z.x;
	}
	modular_int operator - (const modular_int<MOD>& m) const {
		modular_int<MOD> U;
		U.x = x - m.x;
		if (U.x < 0) U.x += MOD;
		return U;
	}
	modular_int operator + (const modular_int<MOD>& m) const {
		modular_int<MOD> U;
		U.x = x + m.x;
		if (U.x >= MOD) U.x -= MOD;
		return U;
	}
	modular_int& operator -= (const modular_int<MOD>& m) {
		x -= m.x;
		if (x < 0) x += MOD;
		return *this;
	}
	modular_int& operator += (const modular_int<MOD>& m) {
		x += m.x;
		if (x >= MOD) x -= MOD;
		return *this;
	}
	modular_int operator * (const modular_int<MOD>& m) const {
		modular_int<MOD> U;
		U.x = (x * 1ull * m.x) % MOD;
		return U;
	}
	modular_int& operator *= (const modular_int<MOD>& m) {
		x = (x * 1ull * m.x) % MOD;
		return *this;
	}
	template<typename T>
	friend modular_int operator + (const T &l, const modular_int<MOD>& p) {
		return (modular_int<MOD>(l) + p);
	}
	template<typename T>
	friend modular_int operator - (const T &l, const modular_int<MOD>& p) {
		return (modular_int<MOD>(l) - p);
	}
	template<typename T>
	friend modular_int operator * (const T &l, const modular_int<MOD>& p) {
		return (modular_int<MOD>(l) * p);
	}
	template<typename T>
	friend modular_int operator / (const T &l, const modular_int<MOD>& p) {
		return (modular_int<MOD>(l) / p);
	}

	int value() const {
		return x;
	}

	modular_int operator ^ (const modular_int<MOD>& cpower) const {
		modular_int<MOD> ans;
		ans.x = 1;
		modular_int<MOD> curr(this);
		int power = cpower.x;

		if (curr.x <= 1) {
			if (power == 0) curr.x = 1;
			return curr;
		}
		while ( power > 0) {
			if (power & 1) {
				ans *= curr;
			}
			power >>= 1;
			if (power) curr *= curr;
		}
		return ans;
	}


	modular_int operator ^ (long long power) const {
		modular_int<MOD> ans;
		ans.x = 1;
		modular_int<MOD> curr(this);
		if (curr.x <= 1) {
			if (power == 0) curr.x = 1;
			return curr;
		}
		// Prime Mods
		if (power >= MOD && is_prime) {
			power %= (MOD - 1);
		}

		while ( power > 0) {
			if (power & 1) {
				ans *= curr;
			}
			power >>= 1;
			if (power) curr *= curr;

		}
		return ans;
	}

	modular_int operator ^ (int power) const {
		modular_int<MOD> ans;
		ans.x = 1;
		modular_int<MOD> curr(this);

		if (curr.x <= 1) {
			if (power == 0) curr.x = 1;
			return curr;
		}
		while ( power > 0) {
			if (power & 1) {
				ans *= curr;
			}
			power >>= 1;
			if (power) curr *= curr;

		}
		return ans;
	}

	template<typename T>
	modular_int& operator ^= (T power) {
		modular_int<MOD> res = (*this)^power;
		x = res.x;
		return *this;
	}


	template<typename T>
	modular_int pow(T x) {
		return (*this)^x;
	}


	pair<long long, long long> gcd(const int a, const int b) const {
		if (b == 0) return {1, 0};
		pair<long long, long long> c = gcd(b , a % b);
		return { c.second , c.first - (a / b)*c.second};
	}

	inline void init_inverse_list() const {

		vector<int>& dp = modular_int<MOD>::inverse_list;
		dp.resize(modular_int<MOD>::inverse_limit + 1);
		int n = modular_int<MOD>::inverse_limit;
		dp[0] = 1;
		if (n > 1) dp[1] = 1;
		for (int i = 2; i <= n; ++i) {
			dp[i] = (dp[MOD % i] * 1ull * (MOD - MOD / i)) % MOD;
		}

	}
	modular_int<MOD> get_inv() const {
		if (modular_int<MOD>::inverse_list.size()
		        < modular_int<MOD>::inverse_limit + 1) init_inverse_list();

		if (this->x <= modular_int<MOD>::inverse_limit) {
			return modular_int<MOD>::inverse_list[this->x];
		}
		pair<long long, long long> G = gcd(this->x, MOD);
		return modular_int<MOD>(G.first);
	}
	modular_int<MOD> operator - () const {
		modular_int<MOD> v(0);
		v -= (*this);
		return v;
	}
	modular_int operator / (const modular_int<MOD>& m) const {
		modular_int<MOD> U(this);
		U *= m.get_inv();
		return U;
	}
	modular_int& operator /= (const modular_int<MOD>& m) {
		(*this) *= m.get_inv();
		return *this;
	}
	bool operator==(const modular_int<MOD>& m) const {
		return x == m.x;
	}

	bool operator < (const modular_int<MOD>& m) const {
		return x < m.x;
	}


	template<typename T>
	bool operator == (const T& m) const {
		return (*this) == (modular_int<MOD>(m));
	}

	template<typename T>
	bool operator < (const T& m) const {
		return x < (modular_int<MOD>(m)).x;
	}
	template<typename T>
	bool operator > (const T& m) const {
		return x > (modular_int<MOD>(m)).x;
	}
	template<typename T>
	friend bool operator == (const T& x, const modular_int<MOD>& m) {
		return (modular_int<MOD>(x)).x == m.x;
	}
	template<typename T>
	friend bool operator < (const T& x, const modular_int<MOD>& m) {
		return (modular_int<MOD>(x)).x < m.x;
	}
	template<typename T>
	friend bool operator > (const T& x, const modular_int<MOD>& m) {
		return (modular_int<MOD>(x)).x > m.x;
	}

	friend istream& operator >> (istream& is, modular_int<MOD>& p) {
		int64_t val;
		is >> val;
		p.x = (val % MOD);
		if (p.x < 0) p.x += MOD;
		return is;
	}
	friend ostream& operator << (ostream& os, const modular_int<MOD>& p)
	{return os << p.x;}



};



using mint = modular_int<mod>;
template<const int MOD>
vector<int> modular_int<MOD>::inverse_list ;
template<const int MOD>
const int modular_int<MOD>::inverse_limit = -1;
template<const int MOD>
const bool modular_int<MOD>::is_prime = true;
template<>   //-> useful if computing inverse fact = i_f[i-1] / i;
const int modular_int<mod>::inverse_limit = 1000;


/******* Debugging Class Template *******/
#define DEBUG

#ifdef DEBUG

#define debug(args...)     (Debugger()) , args
#define dbg(var1) cerr<<#var1<<" = "<<(var1)<<endl;
#define dbg2(var1,var2) cerr<<#var1<<" = "<<(var1)<<", "<<#var2<<" = "<<(var2)<<endl;
#define dbg3(var1,var2,var3) cerr<<#var1<<" = "<<(var1)<<", "<<#var2<<" = "<<(var2)<<", "<<#var3<<" = "<<(var3)<<endl;

class Debugger
{
public:
	Debugger(const std::string& _separator = " - ") :
		first(true), separator(_separator) {}

	template<typename ObjectType> Debugger& operator , (const ObjectType& v)
	{
		if (!first)
std: cerr << separator;
		std::cerr << v;
		first = false;
		return *this;
	}
~Debugger() {  std: cerr << endl;}

private:
	bool first;
	std::string separator;
};

#else
#define debug(args...)                  // Just strip off all debug tokens
#endif

/**************************************/

/******** User-defined Function *******/
/**************************************/


/********** Main()  function **********/
int main()
{
#define ONLINE_JUDGE
#define SUBLIME_TEXT
#if !defined(ONLINE_JUDGE) || defined(SUBLIME_TEXT)
	freopen("../IO/input.txt", "r", stdin);
	freopen("../IO/output.txt", "w", stdout);
#endif

	std::ios::sync_with_stdio(false);
	cin.tie(0);

	int N = 4e6 + 5;
	int phi[N], ans[N];
	phi[0] = 0;
	phi[1] = 1;
	ans[0] = ans[1] = 0;
	for (int i = 2; i < N; i++)
	{
		ans[i] = 0;
		phi[i] = i;
	}

	for (int i = 2; i < N; i++) {
		if (phi[i] == i) {
			phi[i] = i - 1;
			for (int j = 2 * i; j < N; j += i)
				phi[j] = phi[j] / i * (i - 1);
		}
	}

	for (int i = 1; i < N; i++) {
		ans[i] += i - 1;
		for (int j = 2 * i; j < N; j += i) {
			ans[j] += i * ((1 + phi[j / i]) / 2);
		}
	}

	int tc;
	INP(tc);

	while (tc--) {
		int k;
		INP(k);
		cout << (ans[4 * k + 1]) << "\n";
	}
	return 0;
}
