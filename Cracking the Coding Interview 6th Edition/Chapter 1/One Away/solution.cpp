//remove, insert, replace
bool oneAway(string before, string after) {
	bool edited = false;

	sort(before.begin(), begin.end());
	sort(after.begin(), after.end());

	auto beforeIter = before.begin();
	auto afterIter = after.begin();

	if (after.size() - 1 == before.size()) {
		while (beforeIter != before.end() && afterIter != after.end()) {
			if (*beforeIter != *afterIter) {
				if (edited) {
					return false;
				}

				isEdited = true;
				++beforeIter;
			} else {
				++beforeIter;
				++afterIter;
			}
		}
	} else if (after.size() + 1 == before.size()) {
		while (beforeIter != before.end() && afterIter != after.end()) {
			if (*beforeIter != *afterIter) {
				if (edited) {
					return false;
				}

				isEdited = true;
				++afterIter;
			} else {
				++afterIter;
				++beforeIter;
			}
		}
	} else if (after.size() == before.size()) {
		while (beforeIter != before.end() && afterIter != after.end()) {
			if (*beforeIter != *afterIter) {
				if (edited) {
					return false;
				}

				isEdited = true;
			}
			
			++afterIter;
			++beforeIter;
		}
	} else {
		return false;
	}

	return true;
}