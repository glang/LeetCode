class Solution {
public:	
    int computeArea(int leftX1, int leftY1, int rightX1, int rightY1, int leftX2, int leftY2, int rightX2, int rightY2) {
    	int res = 0;
    	int overlapWidth = -1, overlapHeight = -1;

    	if (leftX1 == leftX2 && rightX1 == rightX1) {
    		overlapWidth = rightX1 - leftX1;
    	}

    	if (leftY1 == leftY2 && rightY1 == leftY2) {
    		overlapHeight = rightY1 - leftY1;
    	}

    	if (overlapHeight == 0 || overlapWidth == 0) {
    		return 0;
    	}


    }
};

/*
				CD
 ---------------- 
 | 				 |
 |				 |        GH
 |			----- -------
 |			|	 |		|
 ----------------		|
 AB			|       	|
 			 -----------
 		  EF	 	
*/