bool reachDestination(int sx, int sy, int dx, int dy) {
    if(sx==dx && sy==dy) return 1;
    if(sx>dx || sy>dy) return 0;
    
   if(dx>dy) reachDestination(sx, sy, dx-dy, dy);
   else reachDestination(sx, sy, dx, dy-dx);
}
