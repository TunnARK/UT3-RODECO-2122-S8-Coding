// Modification pour communication synchrone

Class KA1 : public Systeme_RdP {
  Public :
    enum nom_place { P1, P2, P3, P4 };
    KA1 ( m1 * machine );
    void evolue();

  Private :
    m1 * lem1 ;
};

KA1 ( m1 * machine ) : Systeme_RdP( 4 ), lem1 ( machine ) {
  place[ P1 ] = 1 ;
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

  if ( place[ P4 ] && lem1->t4() ) {
    palce[ P4 ] -- ;
    place[ P1 ] ++ ;
  }
}
