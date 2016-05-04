bool oneAway(string before, string after) {
	bool edited = false;

	auto beforeIter = before.begin();
	auto afterIter = after.begin();

	if (after.size() < before.size() - 1 || after.size() > before.size() + 1) {
		return false;
	}

	while (beforeIter != before.end() && afterIter != after.end()) {
		if (*beforeIter != *afterIter) {
			if (edited) {
				return false;
			}

			edited = true;

			if (after.size() - 1 == before.size()) {
				++beforeIter;
			} else if (after.size() + 1 == before.size()) {
				++afterIter;
			} else {
				++beforeIter;
				++afterIter;
			}
		} else {
			++beforeIter;
			++afterIter;
		}
	}

	return true;
}