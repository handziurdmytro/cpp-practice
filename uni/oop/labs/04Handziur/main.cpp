// Developed by Handziur Dmytro on 29.03.2026
#include <iostream>
#include "Sequence.h"
#include <cassert>

using std::cout;

int main()
{
	cout << "\t** INTEGER TESTS **\n\n";

	Sequence<int> arr_int_seq;
	assert(arr_int_seq.empty());
	assert(arr_int_seq.size() == 0);

	Sequence<int, ForwardList> node_int_seq;
	assert(node_int_seq.empty());
	assert(node_int_seq.size() == 0);

	cout << "Empty array integer sequence: "<< arr_int_seq << "; size: " << arr_int_seq.size() << '\n';
	cout << "Empty node integer sequence: "<<node_int_seq << "; size: " << node_int_seq.size() << '\n';

	arr_int_seq.append(23);
	arr_int_seq.append(7);
	arr_int_seq.append(37);
	arr_int_seq.append(17);
	arr_int_seq.append(11);
	arr_int_seq.append(13);

	assert(!arr_int_seq.empty());
	assert(arr_int_seq.size() == 6);

	node_int_seq.append(23);
	node_int_seq.append(7);
	node_int_seq.append(37);
	node_int_seq.append(17);
	node_int_seq.append(11);
	node_int_seq.append(13);

	assert(!node_int_seq.empty());
	assert(node_int_seq.size() == 6);

	cout << "\nFilled array integer sequence: " << arr_int_seq << "; size: " << arr_int_seq.size() << '\n';
	cout << "Filled node integer sequence: " << node_int_seq << "; size: " << node_int_seq.size() << '\n';

	cout << "\nArray: has 37? " << (arr_int_seq.contains(37) ? "Yes" : "No") << '\n';
	cout << "Array: has 39? " << (arr_int_seq.contains(39) ? "Yes" : "No") << '\n';
	cout << "Node: has 37? " << (node_int_seq.contains(37) ? "Yes" : "No") << '\n';
	cout << "Node: has 39? " << (node_int_seq.contains(39) ? "Yes" : "No") << '\n';

	arr_int_seq.remove(37);
	arr_int_seq.remove(999);/* will be ignored */

	node_int_seq.remove(37);
	node_int_seq.remove(999);/* will be ignored */

	cout << "\nArray integer sequence after '37' removal: " << arr_int_seq << "; size: " << arr_int_seq.size() << '\n';
	cout << "Node integer sequence after '37' removal: " << node_int_seq << "; size: " << node_int_seq.size() << '\n';

	cout << "\nArray: has 37? " << (arr_int_seq.contains(37) ? "Yes" : "No") << '\n';
	cout << "Node: has 37? " << (node_int_seq.contains(37) ? "Yes" : "No") << '\n';

	cout << "\n\n\t** STRING TESTS **\n\n";

	Sequence<std::string> arr_str_seq;
	assert(arr_str_seq.empty());
	assert(arr_str_seq.size() == 0);

	Sequence<std::string, ForwardList> node_str_seq;
	assert(node_str_seq.empty());
	assert(node_str_seq.size() == 0);

	cout << "Empty array integer sequence: " << arr_str_seq << "; size: " << arr_str_seq.size() << '\n';
	cout << "Empty node integer sequence: " << node_str_seq << "; size: " << node_str_seq.size() << '\n';

	arr_str_seq.append("c++");
	arr_str_seq.append("rust");
	arr_str_seq.append("golang");
	arr_str_seq.append("zig");
	arr_str_seq.append("c");
	arr_str_seq.append("asm");

	assert(!arr_str_seq.empty());
	assert(arr_str_seq.size() == 6);

	node_str_seq.append("c++");
	node_str_seq.append("rust");
	node_str_seq.append("golang");
	node_str_seq.append("zig");
	node_str_seq.append("c");
	node_str_seq.append("asm");

	assert(!node_str_seq.empty());
	assert(node_str_seq.size() == 6);

	cout << "\nFilled array integer sequence: " << arr_str_seq << "; size: " << arr_str_seq.size() << '\n';
	cout << "Filled node integer sequence: " << node_str_seq << "; size: " << node_str_seq.size() << '\n';

	cout << "\nArray: has 'zig'? " << (arr_str_seq.contains("zig") ? "Yes" : "No") << '\n';
	cout << "Array: has 'java'? " << (arr_str_seq.contains("java") ? "Yes" : "No") << '\n';
	cout << "Node: has 'zig'? " << (node_str_seq.contains("zig") ? "Yes" : "No") << '\n';
	cout << "Node: has 'java'? " << (node_str_seq.contains("java") ? "Yes" : "No") << '\n';

	arr_str_seq.remove("zig");
	arr_str_seq.remove("python");/* will be ignored */

	node_str_seq.remove("zig");
	node_str_seq.remove("python");/* will be ignored */

	cout << "\nArray integer sequence after 'zig' removal: " << arr_str_seq << "; size: " << arr_str_seq.size() << '\n';
	cout << "Node integer sequence after 'zig' removal: " << node_str_seq << "; size: " << node_str_seq.size() << '\n';

	cout << "\nArray: has 'zig'? " << (arr_str_seq.contains("zig") ? "Yes" : "No") << '\n';
	cout << "Node: has 'zig'? " << (node_str_seq.contains("zig") ? "Yes" : "No") << '\n';
}
