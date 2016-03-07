class Solution {
public:
    string longestPalindrome(string s) {
    	int maxLen = 0, loc = 0;

        for (int i = 0; i < s.size(); ++i) {
        	for (int j = 0; i - j >= 0 && i + j < s.size() && s.at(i - j) == s.at(i + j); ++j) {
	        	if (maxLen < j * 2 + 1) {
	        		maxLen = j * 2 + 1;
	        		loc = i - j;
	        	}
			}
        }

        for (int i = 0; i < s.size(); ++i) {
        	for (int j = 1; i - j + 1 >= 0 && i + j < s.size() && s.at(i - j + 1) == s.at(i + j); ++j) {
	        	if (maxLen < j * 2) {
	        		maxLen = j * 2;
	        		loc = i - j + 1;
	        	}
			}
        }

        return s.substr(loc, maxLen);
    }
};

// "miycvxmqggnmmcwlmizfojwrurwhwygwfykyefxbgveixykdebenzitqnciigfjgrzzbtgeazyrbiirmejhdwcgjzwqolrturjlqpsgunuqerqjevbheblmbvgxyedxshswsokbhzapfuojgyfhctlaifrisgzqlczageirnukgnmnbwogknyyuynwsuwbumdmoqwxprykmazghcpmkdcjduepjmjdxrhvixxbfvhybjdpvwjbarmbqypsylgtzyuiqkexgvirzylydrhrmuwpmfkvqllqvekyojoacvyrzjevaupypfrdguhukzuqojolvycgpjaendfetkgtojepelhcltorueawwjpltehbbjrvznxhahtuaeuairvuklctuhcyzomwrrznrcqmovanxmiyilefybkbveesrxkmqrqkowyrimuejqtikcjfhizsmumajbqglxrvevexnleflocxoqgoyrzgqflwiknntdcykuvdcpzlakljidclhkllftxpinpvbngtexngdtntunzgahuvfnqjedcafzouopiixw"