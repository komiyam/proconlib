// BEGIN CUT HERE
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <string>
#include <vector>
#include <map>
#include <set>

template<typename T>
void PARRAY(T from, T to) {
	for (T itr = from; itr != to; ++itr) {
		std::cout << *itr << (itr +1 == to ? '\n' : ',');
	}
	std::cout << std::flush;
}

template<class T>
std::ostream& operator<< (std::ostream& os, const std::vector<T>& xs) {
	os << "v[";
	for (typename std::vector<T>::const_iterator itr = xs.begin(); itr != xs.end(); ++itr) {
		if (itr != xs.begin()) {
			os << ", ";
		}
		os << *itr;
	}
	os << "]";
	return os;
}

template<class T1, class T2>
std::ostream& operator<< (std::ostream& os, const std::map<T1, T2>& xs) {
	os << "m[";
	for (typename std::map<T1,T2>::const_iterator itr = xs.begin(); itr != xs.end(); ++itr) {
		if (itr != xs.begin()) {
			os << ", ";
		}
		os << itr->first << ":" << itr->second;
	}
	os << "]";
	return os;
}

template<class T>
std::ostream& operator<< (std::ostream& os, const std::set<T>& xs) {
	os << "s[";
	for (typename std::set<T>::const_iterator itr = xs.begin(); itr != xs.end(); ++itr) {
		if (itr != xs.begin()) {
			os << ", ";
		}
		os << *itr;
	}
	os << "]";
	return os;
}

template<class T1, class T2>
std::ostream& operator<< (std::ostream& os, const std::pair<T1, T2>& x) {
	return os << "p(" << x.first << ", " << x.second << ")";
}

std::string STRBIN(int binary, int n) {
	std::string ret;
	for (int i = 0; i < n; ++i) {
		ret += (char)('0' + ((binary>>i)&1));
	}
	return ret;
}

template<class T>
std::string toString__(T x) {
	std::ostringstream os;
	os << x;
	return os.str();
}

struct DEBUG_STRING__ : std::string {
	template<class T>
	DEBUG_STRING__ operator, (T x) {
		*this += ", " + toString__(x);
		return *this;
	}
};

std::string TRIM__(DEBUG_STRING__ x) {
	return (int)x.length() >= 2 ? x.substr(2) : x;
}

const char* COLOR_ = "\x1b[31m";
const char* DEFAULT_ = "\x1b[0m";

#define DEBUG(...) std::cout << COLOR_ << #__VA_ARGS__ << " @" << __LINE__ << ": " << DEFAULT_ << TRIM__((DEBUG_STRING__(),##__VA_ARGS__)) << std::endl;
#define DEBUGLN(...) std::cout << COLOR_ << #__VA_ARGS__ << " @" << __LINE__ << ": " << DEFAULT_ << std::endl << TRIM__((DEBUG_STRING__(),##__VA_ARGS__)) << std::endl;
#define DEBUGF(...) std::cout << COLOR_ << #__VA_ARGS__ << " @" << __LINE__ << ": " << DEFAULT_ , printf(__VA_ARGS__), puts(""), fflush(stdout);
#define DEBUGFLN(...) std::cout << COLOR_ << #__VA_ARGS__ << " @" << __LINE__ << ": " << DEFAULT_ << std::endl, printf(__VA_ARGS__), puts(""), fflush(stdout);
#define DEBUGN() std::cout << std::endl;
#define DEBUG_VEC(xs) std::cout << COLOR_ << #xs << " @" << __LINE__ << ":" << DEFAULT_ << std::endl, PARRAY(xs.begin(), xs.end())
#define DEBUG_ARRAY(arr, n) std::cout << COLOR_ << #arr << " @" << __LINE__ << ":" << DEFAULT_ << std::endl, PARRAY(arr, arr+n)
#define DEBUG_2ARRAY(arr, h, w, delim) {std::cout << COLOR_ << #arr << " @" << __LINE__ << ":" << DEFAULT_ << std::endl;for(int i_=0; i_<(h); ++i_)for(int j_=0; j_<(w); ++j_)std::cout<<arr[i_][j_]<<(j_==(w)-1 ? "\n" : (delim));std::cout<<std::flush;}
#define DEBUGASSERT(cond, ...) {if(!(cond)){std::cout << COLOR_ << "A[ " << #cond << " ]: "; DEBUG(__VA_ARGS__); std::cout << DEFAULT_ << std::flush; exit(128 + 6);}}
// END CUT HERE
#include <cstdio>
using namespace std;

void init() {

}

int main() {
	init();
	return 0;
}
