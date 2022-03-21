Class KA1 {
  ...
};

void KA1 :: evolue() {
  if ( place[ P1 ] && t1 && FA1() ) {
    place[ P1 ] -- ;
    place[ P2 ] ++ ;
  }

  if ( place[ P2 ] && t2 ) {
    palce[ P2 ] -- ;
    place[ P3 ] ++ ;
  }

  if ( place[ P3 ] && t3 && FA2() ) {
    palce[ P3 ] -- ;
    place[ P4 ] ++ ;
  }

  if ( place[ P4 ] && t4 ) {
    palce[ P4 ] -- ;
    place[ P1 ] ++ ;
  }
}
