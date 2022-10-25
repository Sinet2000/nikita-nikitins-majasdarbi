// Adding to vectors:
// [instance].push_back(const T& x) -- pushes back
// [instance].insert(p, t)  => {a: vector_name, p:
// iterator_pointing_to_element_in_front_which_insert_will_take_place, } =>
// *** vector1 = {"blue", "red", "grey", "pearl"};
// ***** vector::iterator p = vector1.end();
// ***** vector::iterator pRet = vector1.insert(p, "yellow");
// ******** coyt << *pRet << endl;

// *** or a.insert(p, n, t); {p: index, n: count, t: item}
// https://linuxhint.com/append-vector-cpp/#:~:text=Appending%20to%20a%20vector%20means,to%20append%20is%20push_back().