class Solution {
public:	
    int computeArea(int xmin1, int ymin1, int xmax1, int ymax1, int xmin2, int ymin2, int xmax2, int ymax2) {
    	int overlapWidth = 0, overlapHeight = 0;

    	//check if no overlap
    	if (xmax1 <= xmin2 || xmax2 <= xmin1 || ymax1 <= ymin2 || ymax2 <= ymin1) {
    		return (xmax1 - xmin1) * (ymax1 - ymin1) + (xmax2 - xmin2) * (ymax2 - ymin2);
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

        return (xmax1 - xmin1) * (ymax1 - ymin1) + (xmax2 - xmin2) * (ymax2 - ymin2) - overlapWidth * overlapHeight;
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