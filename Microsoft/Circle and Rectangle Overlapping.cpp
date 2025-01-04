class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
          int x_nearest=max(x1,min(x2,xCenter));
          int y_nearest=max(y1,min(y2,yCenter));
          int x_dist=x_nearest-xCenter;
          int y_dist=y_nearest-yCenter;

          return sqrt((x_dist *x_dist)+(y_dist*y_dist)) <= radius?true:false;
        
    }
};
