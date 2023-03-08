#include <bits/stdc++.h>
#define pii pair <int, int>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	ordered_set <pii> st;
	st.insert({10, 1});
	st.insert({7, 2});
	st.insert({1, 3});
	st.insert({1, 4});

	cout << (st.find_by_order(2) -> first) << endl; //print element in k-th index
	cout << st.order_of_key({10, 2}) << endl; //print number of items < k

	auto print = [&] () {
		for (auto z : st) cout << z.first << ' ';
		cout << endl;
	};

	print();
	st.erase(st.lower_bound({0, 1}));
	print();

	return 0;
}

// #define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
// #define ordered_set tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update>
//less than or equal -> use              less_equal<int>
// #define ordered_set tree<pair<int,int>, null_type, pair<int,int>, rb_tree_tag, tree_order_statistics_node_update>
//to use multiset -> use pair<int, int> where first element is value and second element is index
