// Q26. Write a function that computes the factorial of a positive integer.
// A:
// for implementation
int factorial(int n) {
	int output = 1;
	for(int i=0;i<n;i++) {
		output *= i;
	}
	return output;
}

// recursive implementation
int factorial(int n) {
	if(n==0) return 1;
	return n*factorial(n-1);
}

// tail recursive implementation
int factorial(int n, int last = 1) {
	if(n==0) return last;
	return factorial(n-1, last*n);
}

// Q27. Write a function that taks an array and returns the subarray with the largest sum.
// A:
#include <vector>
#include <algorithm> //std::max
using namespace std;

template <typename T>
T max_sub_array(vector<T> const& numbers) {
	T max_ending = 0, max_so_far = 0;
	for(auto& number:numbers){
		max_ending = max(0,max_ending+number);
		max_so_far = max(max_so_far, max_ending);
	}
	return max_so_far;
}

// Q28. Write a function that returns the prime factors of a positive integer.
// A:
#include <vector>
using namespace std;

vector<int> prime_factors(int n){
	vector<int> factors;
	for(int i=2;i<=n/i;++i){
		while(n%i==0){
			factors.push_back(i);
			n/=i;
		}
		if(n>1)
			factors.push_back(n);
	}
	return factors;
}

// Q29. Write a function that takes a 64-bit integer and swaps the bits at indices i and j.
// A:
long swap_bits(long x, const int &i, const int &j) {
	if(((x>>i) & 1L) != ((x>>j) & 1L))
		x ^= (1L <<i) | (1L <<j);
	return x;
}

// Q30. Write a function that reverses a single linked list.
// A:
#include <memory> // shared_ptr
using namespace std;

template <typename T>
struct node_t {
	T data;
	shared_ptr<node_T<T>> next;
};

// recursive implementation
template <typename T> shared_ptr<node_t <T>>
reverse_linked_list(const shared_ptr<node_t <T> &head){
	if(!head||!head->next) {
		return head;
	}

	shared_ptr<node_t<T>>
		new_head = reverse_linked_list(head->next);
	head->next->next = head;
	head->next = nullptr;
	return new_head;
}

// while implementation
template <typename T> shared_ptr<node_t<T>>
	reverse_linked_list(const shared_ptr<node_t<T>> &head){
		shared_ptr<node_t<T>>
			prev = nullptr, curr = head;
		while(curr) {
			shared_ptr<node_t<T>> temp = curr->next;
			curr->next = prev;
			prev = curr;
			curr = temp;
		}
		return prev;
	}