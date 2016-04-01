class Solution {
public:	
    int computeArea(int min_x1, int min_y1, int max_x1, int max_y1, int min_x2, int min_y2, int max_x2, int max_y2) {
    	int res = 0;
    	int overlapWidth = 0, overlapHeight = 0;

    	//check if no overlap
    	if (max_x1 <= min_x2 || max_x2 <= min_x1 || max_y1 <= min_y2 || max_y2 <= min_y1) {
    		return 0;
    	}

    	//find width of overlap
    	if (xmin2 >= xmin1) {
    		if (xmax2 >= xmax1) {
    			overlapWidth = xmax1 - xmin2;
    		} else {
    			overlapWidth = xmax2 - xmin2;
    		}
    	} else {
            if (xmax1 >= xmax2) {
                overlapWidth = xmax2 - xmin1;
            } else {
                overlapWidth = xmax1 - xmin1;
            }            
        }
  
        //find height of overlap
        if (ymin2 >= ymin1) {
            if (ymax2 >= ymax1) {
                overlapHeight = ymax1 - ymin2;
            } else {
                overlapHeight = ymax2 - ymin2;
            }
        } else {
            if (ymax1 >= ymax2) {
                overlapHeight = ymax2 - ymin1;
            } else {
                overlapHeight = ymax1 - ymin1;
            }            
        }

        return overlapWidth * overlapHeight;
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