vector<char> buildOrder(vector<char> projects, vector<pair<char, char>> dependencies) {
    unordered_set<char> noDepend = independents(projects, dependencies);

    if (noDepend.empty()) {
        throw "error";
    }

    vector<char> buildOrder(noDepend.begin(), noDepend.end());
    bool found = true;
    int remaining = dependencies.size() - noDepend.size();
    
    while (found && remaining > 0) {
        found = false;
        
        for (pair<char, char> p : dependencies) {
            if (noDepend.find(p.second) != noDepend.end()) {
                found = true;
                --remaining;
                noDepend.insert(p.first);
                buildOrder.push_back(p.first);
                p.second = 0;
            }
        }
    }

    if (remaining > 0) {
        throw "error";
    } else {
        return buildOrder;
    }
}

unordered_set<char> independents(vector<char> &projects, vector<pair<char, char>>& dependencies) {
    unordered_set<char> result;
    vector<char> depends;

    for (pair<char, char> p : dependencies) {
        depends.push_back(p.first);
    }

    sort(projects.begin(), depends.end());
    sort(depends.begin(), depends.end());
    set_intersection(projects.begin(), projects.end(), depends.begin(), depends.end(), inserter(result.begin());

    return result;
}