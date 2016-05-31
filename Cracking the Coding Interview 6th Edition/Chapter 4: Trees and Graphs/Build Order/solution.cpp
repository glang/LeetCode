vector<char> buildOrder(set<char> projects, set<pair<char, char>> dependencies) {
    set<char> noDepend = independents(projects, dependencies);
    unordered_map<char, set<char>> dependMap = makeDependMap(dependencies);
    vector<char> buildOrder(noDepend.begin(), noDepend.end());
    int remaining = dependencies.size() - noDepend.size();
    
    while (remaining > 0) {
        bool found = false;
        
        for (auto &p : dependMap) {
            if (include(noDepend.begin(), noDepend.end(), p.second.begin(), p.second.end()) {
                found = true;
                --remaining;
                noDepend.insert(p.first);
                buildOrder.push_back(p.first);
                p.second = set<char>({0});
            }
        }

        if (!found) {
            throw "error";
        }
    }

    return buildOrder;
}


set<char> independents(set<char> &projects, set<pair<char, char>>& dependencies) {
    set<char> result;
    set<char> depends;

    for (auto const &p : dependencies) {
        depends.insert(p.first);
    }

    set_difference(projects.begin(), projects.end(), depends.begin(), depends.end(), inserter(result, result.begin());

    return result;
}

unordered_map<char, set<char>> makeDependMap(set<pair<char, char>>& dependencies) {
    unordered_map<char, set<char>> map;

    for (auto &p : dependencies) {
        if (map.find(p.first) == map.end()) {
            map[p.first] = p.second;
        } else {
            map[p.first].insert(p.second);
        }
    }

    return map;
}