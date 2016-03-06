class Solution {
public:
	bool isPal(string &s) {
		for (int i = 0; i != s.size()/2; ++i) {
			if (s.at(i) != s.at(s.size() - i - 1))
				return false;
		}

		return true;
	}

    string longestPalindrome(string s) {
        for (int i = s.size(); i >= 0; --i) {
        	for (int j = 0; j <= s.size() - i; ++j) {
        		string sub = s.substr(j, i);
        		if (isPal(sub)) {
        			return sub;
        		}
        	}
        }
    }
};

// "miycvxmqggnmmcwlmizfojwrurwhwygwfykyefxbgveixykdebenzitqnciigfjgrzzbtgeazyrbiirmejhdwcgjzwqolrturjlqpsgunuqerqjevbheblmbvgxyedxshswsokbhzapfuojgyfhctlaifrisgzqlczageirnukgnmnbwogknyyuynwsuwbumdmoqwxprykmazghcpmkdcjduepjmjdxrhvixxbfvhybjdpvwjbarmbqypsylgtzyuiqkexgvirzylydrhrmuwpmfkvqllqvekyojoacvyrzjevaupypfrdguhukzuqojolvycgpjaendfetkgtojepelhcltorueawwjpltehbbjrvznxhahtuaeuairvuklctuhcyzomwrrznrcqmovanxmiyilefybkbveesrxkmqrqkowyrimuejqtikcjfhizsmumajbqglxrvevexnleflocxoqgoyrzgqflwiknntdcykuvdcpzlakljidclhkllftxpinpvbngtexngdtntunzgahuvfnqjedcafzouopiixw"